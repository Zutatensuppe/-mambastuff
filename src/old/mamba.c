#include <windows.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h> // For memset/memcpy
#include "spider_bmp.h"

// Game constants from your code
#define EDGE_SIZE 1 
#define MAP_W_PIXELS 455 
#define MAP_H_PIXELS 359 
#define MAP_W_PIXELS_INCL_EDGE (MAP_W_PIXELS + EDGE_SIZE + EDGE_SIZE) 
#define MAP_H_PIXELS_INCL_EDGE (MAP_H_PIXELS + EDGE_SIZE + EDGE_SIZE) 
#define MAP_W_CELLS 35
#define MAP_H_CELLS 29
#define CELL_SIZE 11 
#define SPIDER_MAX_X (MAP_W_CELLS * (CELL_SIZE + EDGE_SIZE))
#define SPIDER_MAX_Y (MAP_H_CELLS * (CELL_SIZE + EDGE_SIZE))
#define WIN_BORDER 16 
#define WIN_W (MAP_W_PIXELS_INCL_EDGE + 2 * WIN_BORDER)
#define WIN_H (MAP_H_PIXELS_INCL_EDGE + 2 * WIN_BORDER)

// Colors
int color_black = 0x000000;
int color_white = 0xFFFFFF;
int color_cyan = 0xFFFF00; // Corrected: BGR, so Cyan is FFFF00
int color_light_gray = 0xC0C0C0;

// Game state variables
bool claimed[MAP_W_CELLS][MAP_H_CELLS];
bool past_path_h[MAP_W_CELLS][MAP_H_CELLS + 1];
bool past_path_v[MAP_W_CELLS + 1][MAP_H_CELLS];
bool path_h[MAP_W_CELLS][MAP_H_CELLS + 1]; // Current path
bool path_v[MAP_W_CELLS + 1][MAP_H_CELLS]; // Current path

int spider_x = 0, spider_y = 0; // Pixel coordinates
int spider_vx = 0, spider_vy = 0; // Pixel velocity
int last_vertex_x = 0, last_vertex_y = 0; // Grid coordinates
int input_vx_intent = 0, input_vy_intent = 0; // Queued pixel velocity intent

uint32_t pixels[WIN_W * WIN_H];


// --- START: Core Data Structures ---
typedef struct { int x, y; } Point;

typedef struct {
    Point cells[MAP_W_CELLS * MAP_H_CELLS];
    int count;
    bool is_adjacent_to_claimed_territory;
} Region;
// --- END: Core Data Structures ---

// Spider state
typedef enum {
    SPIDER_IDLE_ON_CLAIMED,
    SPIDER_MOVING_ON_CLAIMED,
    SPIDER_DRAWING_PATH
} SpiderState;
SpiderState spider_state = SPIDER_IDLE_ON_CLAIMED;

// Path drawing state
int path_start_vertex_x, path_start_vertex_y; // Grid coords where current path started
Point current_path_vertices[MAP_W_CELLS * MAP_H_CELLS * 2]; // Max possible vertices in a path
int current_path_len = 0;

// Game progression
int total_cells = MAP_W_CELLS * MAP_H_CELLS;
int claimed_cell_count = 0;

// --- START: Point and Queue for BFS ---

#define MAX_QUEUE_SIZE (MAP_W_CELLS * MAP_H_CELLS)
Point queue[MAX_QUEUE_SIZE];
int queue_front, queue_rear;
bool visited_bfs[MAP_W_CELLS][MAP_H_CELLS]; // Visited array for BFS

void init_queue() { queue_front = queue_rear = 0; }
void enqueue(Point p) {
    if ((queue_rear + 1) % MAX_QUEUE_SIZE == queue_front) { /*fprintf(stderr, "Queue full!\n");*/ return; }
    queue[queue_rear] = p;
    queue_rear = (queue_rear + 1) % MAX_QUEUE_SIZE;
}
Point dequeue() {
    if (queue_front == queue_rear) { /*fprintf(stderr, "Queue empty!\n");*/ return (Point){-1,-1}; }
    Point p = queue[queue_front];
    queue_front = (queue_front + 1) % MAX_QUEUE_SIZE;
    return p;
}
bool is_queue_empty() { return queue_front == queue_rear; }
// --- END: Point and Queue for BFS ---


// Forward declarations
void attempt_claim_territory();
void clear_current_path_data();
void initialize_game_state();


void debug_printf_fmt(const char* fmt, ...) {
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    OutputDebugStringA(buffer);
}

void debug_printf(const char* msg) {
    OutputDebugStringA(msg);
}

void clear_screen(uint32_t color) {
    for (int i = 0; i < WIN_W * WIN_H; i++) {
        pixels[i] = color;
    }
}

void draw_rect(int x, int y, int w, int h, uint32_t color) {
    for (int dy = 0; dy < h; dy++) {
        for (int dx = 0; dx < w; dx++) {
            int px = x + dx;
            int py = y + dy;
            if (px >= 0 && px < WIN_W && py >= 0 && py < WIN_H) {
                pixels[py * WIN_W + px] = color;
            }
        }
    }
}

void draw_cells() {
    for (int y = 0; y < MAP_H_CELLS; y++) {
        for (int x = 0; x < MAP_W_CELLS; x++) {
            if (claimed[x][y]) {
                draw_rect(WIN_BORDER + EDGE_SIZE + x * (CELL_SIZE + EDGE_SIZE) , 
                          WIN_BORDER + EDGE_SIZE + y * (CELL_SIZE + EDGE_SIZE) , 
                          CELL_SIZE, CELL_SIZE, color_light_gray);
            }
        }
    }
}

void draw_bitmap(const uint32_t *bitmap, int x, int y, int bitmap_w, int bitmap_h) {
    for (int dy = 0; dy < bitmap_h; dy++) {
        for (int dx = 0; dx < bitmap_w; dx++) {
            int px = x + dx;
            int py = y + dy;
            if (px >= 0 && px < WIN_W && py >= 0 && py < WIN_H) {
                uint32_t color = bitmap[dy * bitmap_w + dx];
                if (color == 0xFF000000) continue; // Skip fully transparent black pixels (alpha example)
                                                  // Or if your bitmap uses a specific transparent color key:
                if (color == 0x000000 && (bitmap == spider_pixels)) continue; // Example: black is transparent for spider
                pixels[py * WIN_W + px] = color;
            }
        }
    }
}

void draw_paths(bool is_current_path_drawing) {
    uint32_t path_color = is_current_path_drawing ? color_white : color_black;
    bool (*h_paths_to_draw)[MAP_H_CELLS + 1] = is_current_path_drawing ? path_h : past_path_h;
    bool (*v_paths_to_draw)[MAP_H_CELLS]     = is_current_path_drawing ? path_v : past_path_v;

    int baseOffset = WIN_BORDER;

    // Draw horizontal edges
    for (int y = 0; y < MAP_H_CELLS + 1; y++) {
        for (int x = 0; x < MAP_W_CELLS; x++) {
            if (h_paths_to_draw[x][y]) {
                int draw_x = baseOffset + x * (CELL_SIZE + EDGE_SIZE) + EDGE_SIZE; // Start after vertical border
                int draw_y = baseOffset + y * (CELL_SIZE + EDGE_SIZE);
                draw_rect(draw_x, draw_y, CELL_SIZE, EDGE_SIZE, path_color);
            }
        }
    }
    // Draw vertical edges
    for (int y = 0; y < MAP_H_CELLS; y++) {
        for (int x = 0; x < MAP_W_CELLS + 1; x++) {
            if (v_paths_to_draw[x][y]) {
                int draw_x = baseOffset + x * (CELL_SIZE + EDGE_SIZE);
                int draw_y = baseOffset + y * (CELL_SIZE + EDGE_SIZE) + EDGE_SIZE; // Start after horizontal border
                draw_rect(draw_x, draw_y, EDGE_SIZE, CELL_SIZE, path_color);
            }
        }
    }
}


void rotate_pixels(const uint32_t* src, uint32_t* dst, int width, int height, int angle) {
    int out_w = width, out_h = height;
    if (angle == 90 || angle == 270) {
        out_w = height;
        out_h = width;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int src_idx = y * width + x;
            int dst_idx;

            switch (angle) {
                case 90: dst_idx = x * out_h + (out_h - 1 - y); break; // Rotated height
                case 180: dst_idx = (height - 1 - y) * width + (width - 1 - x); break;
                case 270: dst_idx = (out_w - 1 - x) * out_h + y; break; // Rotated width
                default: dst_idx = src_idx; break;
            }
            if (dst_idx < out_w * out_h) dst[dst_idx] = src[src_idx];
        }
    }
}

void draw_spider() {
    int baseOffset = WIN_BORDER;
    uint32_t spider_pixels_rotated[SPIDER_WIDTH * SPIDER_HEIGHT]; // Ensure this buffer is large enough for rotated dimensions
    
    int sprite_w_orig = SPIDER_WIDTH;
    int sprite_h_orig = SPIDER_HEIGHT;
    int sprite_w_eff = sprite_w_orig;
    int sprite_h_eff = sprite_h_orig;

    if (spider_vx > 0) { // Right
        rotate_pixels(spider_pixels, spider_pixels_rotated, sprite_w_orig, sprite_h_orig, 90);
        sprite_w_eff = sprite_h_orig; sprite_h_eff = sprite_w_orig;
    } else if (spider_vx < 0) { // Left
        rotate_pixels(spider_pixels, spider_pixels_rotated, sprite_w_orig, sprite_h_orig, 270);
        sprite_w_eff = sprite_h_orig; sprite_h_eff = sprite_w_orig;
    } else if (spider_vy > 0) { // Down
        rotate_pixels(spider_pixels, spider_pixels_rotated, sprite_w_orig, sprite_h_orig, 180);
    } else { // Up or stationary (default orientation)
        rotate_pixels(spider_pixels, spider_pixels_rotated, sprite_w_orig, sprite_h_orig, 0);
    }

    int draw_x = spider_x - sprite_w_eff / 2 + EDGE_SIZE;
    int draw_y = spider_y - sprite_h_eff / 2 + EDGE_SIZE;
    draw_bitmap(spider_pixels_rotated, baseOffset + draw_x, baseOffset + draw_y, sprite_w_eff, sprite_h_eff);
}

bool is_spider_on_cross_section() {
    bool on_cross_section_x = (spider_x % (CELL_SIZE + EDGE_SIZE)) == 0;
    bool on_cross_section_y = (spider_y % (CELL_SIZE + EDGE_SIZE)) == 0;
    return on_cross_section_x && on_cross_section_y;
}

// --- START: Movement and Path Logic Helper Functions ---
bool is_edge_part_of_claimed_area(int gx, int gy, bool is_horizontal_edge) {
    // gx, gy are grid coordinates of the top-left part of the edge or cell.
    // For horizontal edge at (gx, gy), it's path_h[gx][gy].
    // For vertical edge at (gx, gy), it's path_v[gx][gy].
    if (is_horizontal_edge) {
        if (gx < 0 || gx >= MAP_W_CELLS || gy < 0 || gy > MAP_H_CELLS) return false;
        if (past_path_h[gx][gy]) return true;
        if (gy > 0 && gy < MAP_H_CELLS) { // Edge is between cells
            return claimed[gx][gy - 1] && claimed[gx][gy];
        } else if (gy == 0 && gy < MAP_H_CELLS) { // Top border edge
             return claimed[gx][gy];
        } else if (gy == MAP_H_CELLS && gy > 0) { // Bottom border edge
            return claimed[gx][gy-1];
        }
    } else { // Vertical edge
        if (gx < 0 || gx > MAP_W_CELLS || gy < 0 || gy >= MAP_H_CELLS) return false;
        if (past_path_v[gx][gy]) return true;
        if (gx > 0 && gx < MAP_W_CELLS) { // Edge is between cells
            return claimed[gx - 1][gy] && claimed[gx][gy];
        } else if (gx == 0 && gx < MAP_W_CELLS) { // Left border edge
            return claimed[gx][gy];
        } else if (gx == MAP_W_CELLS && gx > 0) { // Right border edge
            return claimed[gx-1][gy];
        }
    }
    return false;
}

bool can_move_on_claimed_territory(int cvx, int cvy, int move_dir_x, int move_dir_y) {
    // cvx, cvy: current spider vertex (grid coords)
    // move_dir_x, move_dir_y: intended direction of movement (-1, 0, or 1 for grid steps)
    if (move_dir_x == 1)  return is_edge_part_of_claimed_area(cvx, cvy, true);       // Right: H-edge at (cvx, cvy)
    if (move_dir_x == -1) return is_edge_part_of_claimed_area(cvx - 1, cvy, true);   // Left:  H-edge at (cvx-1, cvy)
    if (move_dir_y == 1)  return is_edge_part_of_claimed_area(cvx, cvy, false);      // Down:  V-edge at (cvx, cvy)
    if (move_dir_y == -1) return is_edge_part_of_claimed_area(cvx, cvy - 1, false);  // Up:    V-edge at (cvx, cvy-1)
    return false;
}

bool can_start_drawing_path(int cvx, int cvy, int move_dir_x, int move_dir_y) {
    // Check if the cells adjacent to the new path segment are unclaimed.
    if (move_dir_x == 1) { // Drawing H-Path right from (cvx,cvy) -> path_h[cvx][cvy]
        bool above_ok = (cvy == 0) || (cvy > 0 && cvx < MAP_W_CELLS && !claimed[cvx][cvy - 1]);
        bool below_ok = (cvy == MAP_H_CELLS) || (cvy < MAP_H_CELLS && cvx < MAP_W_CELLS && !claimed[cvx][cvy]);
        return above_ok && below_ok;
    } else if (move_dir_x == -1) { // Drawing H-Path left from (cvx,cvy) -> path_h[cvx-1][cvy]
        bool above_ok = (cvy == 0) || (cvy > 0 && cvx > 0 && !claimed[cvx - 1][cvy - 1]);
        bool below_ok = (cvy == MAP_H_CELLS) || (cvy < MAP_H_CELLS && cvx > 0 && !claimed[cvx - 1][cvy]);
        return above_ok && below_ok;
    } else if (move_dir_y == 1) { // Drawing V-Path down from (cvx,cvy) -> path_v[cvx][cvy]
        bool left_ok = (cvx == 0) || (cvx > 0 && cvy < MAP_H_CELLS && !claimed[cvx - 1][cvy]);
        bool right_ok = (cvx == MAP_W_CELLS) || (cvx < MAP_W_CELLS && cvy < MAP_H_CELLS && !claimed[cvx][cvy]);
        return left_ok && right_ok;
    } else if (move_dir_y == -1) { // Drawing V-Path up from (cvx,cvy) -> path_v[cvx][cvy-1]
        bool left_ok = (cvx == 0) || (cvx > 0 && cvy > 0 && !claimed[cvx - 1][cvy - 1]);
        bool right_ok = (cvx == MAP_W_CELLS) || (cvx < MAP_W_CELLS && cvy > 0 && !claimed[cvx][cvy - 1]);
        return left_ok && right_ok;
    }
    return false;
}

bool is_vertex_on_claimed_border(int vx, int vy) {
    // Check past_path edges incident to vertex (vx,vy)
    if (vx < MAP_W_CELLS && past_path_h[vx][vy]) return true;         // Edge to the right
    if (vx > 0 && past_path_h[vx-1][vy]) return true;                 // Edge to the left
    if (vy < MAP_H_CELLS && past_path_v[vx][vy]) return true;         // Edge below
    if (vy > 0 && past_path_v[vx][vy-1]) return true;                 // Edge above

    // Check if vertex is a corner of any claimed cell
    if (vx < MAP_W_CELLS && vy < MAP_H_CELLS && claimed[vx][vy]) return true;         // Vertex is BR corner of cell (vx,vy)
    if (vx > 0 && vy < MAP_H_CELLS && claimed[vx-1][vy]) return true;                 // Vertex is BL corner of cell (vx-1,vy)
    if (vx < MAP_W_CELLS && vy > 0 && claimed[vx][vy-1]) return true;                 // Vertex is TR corner of cell (vx,vy-1)
    if (vx > 0 && vy > 0 && claimed[vx-1][vy-1]) return true;                         // Vertex is TL corner of cell (vx-1,vy-1)
    
    return false;
}

void clear_current_path_data() {
    memset(path_h, 0, sizeof(path_h));
    memset(path_v, 0, sizeof(path_v));
    current_path_len = 0;
}
// --- END: Movement and Path Logic Helper Functions ---

void update_spider() {
    int current_grid_x = spider_x / (CELL_SIZE + EDGE_SIZE);
    int current_grid_y = spider_y / (CELL_SIZE + EDGE_SIZE);

    // Handle input intent if on a cross-section or 180-degree turn
    if (input_vx_intent != 0 || input_vy_intent != 0) {
        bool is_180_turn = (spider_vx == -input_vx_intent && input_vx_intent != 0) || 
                           (spider_vy == -input_vy_intent && input_vy_intent != 0);

        if (is_spider_on_cross_section() || is_180_turn) {
            int intent_dir_x = (input_vx_intent > 0) ? 1 : ((input_vx_intent < 0) ? -1 : 0);
            int intent_dir_y = (input_vy_intent > 0) ? 1 : ((input_vy_intent < 0) ? -1 : 0);

            if (spider_state == SPIDER_IDLE_ON_CLAIMED || spider_state == SPIDER_MOVING_ON_CLAIMED) {
                if (can_move_on_claimed_territory(current_grid_x, current_grid_y, intent_dir_x, intent_dir_y)) {
                    spider_vx = input_vx_intent;
                    spider_vy = input_vy_intent;
                    spider_state = SPIDER_MOVING_ON_CLAIMED;
                } else if (can_start_drawing_path(current_grid_x, current_grid_y, intent_dir_x, intent_dir_y)) {
                    spider_vx = input_vx_intent;
                    spider_vy = input_vy_intent;
                    spider_state = SPIDER_DRAWING_PATH;
                    path_start_vertex_x = current_grid_x;
                    path_start_vertex_y = current_grid_y;
                    clear_current_path_data();
                    current_path_vertices[current_path_len++] = (Point){current_grid_x, current_grid_y};
                } else { // Invalid move
                    spider_vx = 0; spider_vy = 0; // Stop if previous move was valid but new one isn't
                    if (spider_state == SPIDER_MOVING_ON_CLAIMED) spider_state = SPIDER_IDLE_ON_CLAIMED;
                }
            } else if (spider_state == SPIDER_DRAWING_PATH) {
                // Allow direction change while drawing, unless it's into a wall not part of claim process
                // For now, assume player manages not to hit walls directly unless completing path
                spider_vx = input_vx_intent;
                spider_vy = input_vy_intent;
            }
            input_vx_intent = 0; input_vy_intent = 0; // Consume intent
        }
    }
    
    // Stop spider if no velocity (e.g. after failed move or at start)
    if (spider_vx == 0 && spider_vy == 0 && spider_state == SPIDER_MOVING_ON_CLAIMED) {
        spider_state = SPIDER_IDLE_ON_CLAIMED;
    }


    // Update spider position based on velocity
    int new_x = spider_x + spider_vx;
    int new_y = spider_y + spider_vy;

    // Boundary checks
    if (new_x > SPIDER_MAX_X) new_x = SPIDER_MAX_X;
    if (new_x < 0) new_x = 0;
    if (new_y > SPIDER_MAX_Y) new_y = SPIDER_MAX_Y;
    if (new_y < 0) new_y = 0;

    // If movement occurred
    if (spider_x != new_x || spider_y != new_y) {
         if (spider_state == SPIDER_IDLE_ON_CLAIMED && (spider_vx != 0 || spider_vy != 0) ) {
            // This case should ideally be caught by input handling, if starting from idle.
            // But if somehow missed, transition to moving.
            spider_state = SPIDER_MOVING_ON_CLAIMED;
        }
    }
    spider_x = new_x;
    spider_y = new_y;


    if (is_spider_on_cross_section()) {
        int next_grid_x = spider_x / (CELL_SIZE + EDGE_SIZE);
        int next_grid_y = spider_y / (CELL_SIZE + EDGE_SIZE);

        if (last_vertex_x != next_grid_x || last_vertex_y != next_grid_y) { // Moved to a new vertex
            if (spider_state == SPIDER_DRAWING_PATH) {
                bool self_intersect = false;
                // Add current vertex to path list and check for self-intersection
                for(int i=0; i < current_path_len -1; ++i) { // -1 to not check against immediate predecessor
                    if(current_path_vertices[i].x == next_grid_x && current_path_vertices[i].y == next_grid_y) {
                        self_intersect = true;
                        break;
                    }
                }
                if (current_path_len < sizeof(current_path_vertices)/sizeof(Point)) {
                     current_path_vertices[current_path_len++] = (Point){next_grid_x, next_grid_y};
                }


                // Mark the edge in current path_h/path_v
                // Edge from (last_vertex_x, last_vertex_y) to (next_grid_x, next_grid_y)
                if (next_grid_x > last_vertex_x) path_h[last_vertex_x][next_grid_y] = true; // Moved right
                else if (next_grid_x < last_vertex_x) path_h[next_grid_x][next_grid_y] = true; // Moved left
                else if (next_grid_y > last_vertex_y) path_v[next_grid_x][last_vertex_y] = true; // Moved down
                else if (next_grid_y < last_vertex_y) path_v[next_grid_x][next_grid_y] = true; // Moved up
                
                bool returned_to_claimed = is_vertex_on_claimed_border(next_grid_x, next_grid_y);

                if (self_intersect || returned_to_claimed) {
                    attempt_claim_territory();
                }
            }
            last_vertex_x = next_grid_x;
            last_vertex_y = next_grid_y;
        }
    }
}

// --- START: Territory Claiming Logic ---
bool can_flood_fill_pass(int cx, int cy, int ncx, int ncy) {
    // Check if moving from (cx,cy) to (ncx,ncy) crosses a path line
    if (ncx == cx + 1) { // Moving right
        return !(path_v[cx + 1][cy] || past_path_v[cx + 1][cy]);
    } else if (ncx == cx - 1) { // Moving left
        return !(path_v[cx][cy] || past_path_v[cx][cy]);
    } else if (ncy == cy + 1) { // Moving down
        return !(path_h[cx][cy + 1] || past_path_h[cx][cy + 1]);
    } else if (ncy == cy - 1) { // Moving up
        return !(path_h[cx][cy] || past_path_h[cx][cy]);
    }
    return true; // Should not happen for cardinal moves
}

void flood_fill_region(int start_x, int start_y, Region* region, bool visited_map[MAP_W_CELLS][MAP_H_CELLS]) {
    init_queue();
    region->count = 0;
    region->is_adjacent_to_claimed_territory = false;

    if (start_x < 0 || start_x >= MAP_W_CELLS || start_y < 0 || start_y >= MAP_H_CELLS) return;
    if (claimed[start_x][start_y] || visited_map[start_x][start_y]) return;

    enqueue((Point){start_x, start_y});
    visited_map[start_x][start_y] = true;

    while (!is_queue_empty()) {
        Point p = dequeue();
        if (region->count < MAP_W_CELLS * MAP_H_CELLS) {
            region->cells[region->count++] = p;
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx >= 0 && nx < MAP_W_CELLS && ny >= 0 && ny < MAP_H_CELLS &&
                !claimed[nx][ny] && !visited_map[nx][ny]) {
                if (can_flood_fill_pass(p.x, p.y, nx, ny)) {
                    visited_map[nx][ny] = true;
                    enqueue((Point){nx, ny});
                }
            }
        }
    }
}

bool check_region_adjacency(Region* region, int num_pre_existing_claimed_cells) {
    for (int i = 0; i < region->count; i++) {
        Point p = region->cells[i]; // A cell in the potential new region

        // Check adjacency to previously claimed cells (sharing edge or corner)
        for (int dy_adj = -1; dy_adj <= 1; dy_adj++) {
            for (int dx_adj = -1; dx_adj <= 1; dx_adj++) {
                if (dx_adj == 0 && dy_adj == 0) continue;

                int nx_adj = p.x + dx_adj;
                int ny_adj = p.y + dy_adj;

                if (nx_adj >= 0 && nx_adj < MAP_W_CELLS && ny_adj >= 0 && ny_adj < MAP_H_CELLS) {
                    if (claimed[nx_adj][ny_adj]) { // This cell was claimed in a *previous* operation
                        return true;
                    }
                }
            }
        }
        
        // If no cells were claimed before this operation, check adjacency to initial border
        if (num_pre_existing_claimed_cells == 0) {
            if (p.x == 0 && past_path_v[0][p.y]) return true; // Left border
            if (p.x == MAP_W_CELLS - 1 && past_path_v[MAP_W_CELLS][p.y]) return true; // Right border
            if (p.y == 0 && past_path_h[p.x][0]) return true; // Top border
            if (p.y == MAP_H_CELLS - 1 && past_path_h[p.x][MAP_H_CELLS]) return true; // Bottom border
        }
    }
    return false;
}


void attempt_claim_territory() {
    Region found_regions[10]; // Assume max 10 distinct regions formed, adjust if needed
    int found_region_count = 0;
    bool overall_visited_cells[MAP_W_CELLS][MAP_H_CELLS];
    memset(overall_visited_cells, 0, sizeof(overall_visited_cells));

    int pre_existing_claims = 0;
    for(int r=0; r<MAP_H_CELLS; ++r) for(int c=0; c<MAP_W_CELLS; ++c) if(claimed[c][r]) pre_existing_claims++;

    for (int y = 0; y < MAP_H_CELLS; y++) {
        for (int x = 0; x < MAP_W_CELLS; x++) {
            if (!claimed[x][y] && !overall_visited_cells[x][y] && found_region_count < 10) {
                flood_fill_region(x, y, &found_regions[found_region_count], overall_visited_cells);
                if (found_regions[found_region_count].count > 0) {
                    found_regions[found_region_count].is_adjacent_to_claimed_territory = 
                        check_region_adjacency(&found_regions[found_region_count], pre_existing_claims);
                    found_region_count++;
                }
            }
        }
    }

    Region* best_region_to_claim = NULL;
    int min_size = total_cells + 1;

    for (int i = 0; i < found_region_count; i++) {
        if (found_regions[i].is_adjacent_to_claimed_territory) {
            if (found_regions[i].count < min_size) {
                min_size = found_regions[i].count;
                best_region_to_claim = &found_regions[i];
            }
        }
    }

    if (best_region_to_claim != NULL) {
        for (int i = 0; i < best_region_to_claim->count; i++) {
            Point p = best_region_to_claim->cells[i];
            if (!claimed[p.x][p.y]) { // Double check not already claimed
                 claimed[p.x][p.y] = true;
                 claimed_cell_count++;
            }
        }
        // Merge current path into past_path
        for (int y_path = 0; y_path <= MAP_H_CELLS; y_path++) {
            for (int x_path = 0; x_path < MAP_W_CELLS; x_path++) {
                if (path_h[x_path][y_path]) past_path_h[x_path][y_path] = true;
            }
        }
        for (int y_path = 0; y_path < MAP_H_CELLS; y_path++) {
            for (int x_path = 0; x_path <= MAP_W_CELLS; x_path++) {
                if (path_v[x_path][y_path]) past_path_v[x_path][y_path] = true;
            }
        }
        clear_current_path_data();
        spider_state = SPIDER_IDLE_ON_CLAIMED; // Or MOVING if auto-move along new border
        spider_vx = 0; spider_vy = 0; // Stop for now
    } else {
        // No valid region claimed, reset path
        clear_current_path_data();
        spider_x = path_start_vertex_x * (CELL_SIZE + EDGE_SIZE);
        spider_y = path_start_vertex_y * (CELL_SIZE + EDGE_SIZE);
        last_vertex_x = path_start_vertex_x;
        last_vertex_y = path_start_vertex_y;
        spider_vx = 0; spider_vy = 0;
        spider_state = SPIDER_IDLE_ON_CLAIMED;
    }
}
// --- END: Territory Claiming Logic ---

void update_game_title(HWND hwnd) {
    char title[100];
    float percentage_claimed = 0.0f;
    if (total_cells > 0) {
        percentage_claimed = (float)claimed_cell_count / total_cells * 100.0f;
    }
    sprintf(title, "Mamba 1.0 - Claimed: %.2f%%", percentage_claimed);
    SetWindowText(hwnd, title);
}


void initialize_game_state() {
    memset(claimed, 0, sizeof(claimed));
    memset(past_path_h, 0, sizeof(past_path_h));
    memset(past_path_v, 0, sizeof(past_path_v));
    clear_current_path_data(); // Clears path_h, path_v, current_path_len

    // Set up initial border as past_path
    for (int x = 0; x < MAP_W_CELLS; x++) {
        past_path_h[x][0] = true;             // Top border
        past_path_h[x][MAP_H_CELLS] = true;   // Bottom border
    }
    for (int y = 0; y < MAP_H_CELLS; y++) {
        past_path_v[0][y] = true;             // Left border
        past_path_v[MAP_W_CELLS][y] = true;   // Right border
    }

    spider_x = 0; // Top-left vertex in pixels
    spider_y = 0;
    spider_vx = 0; 
    spider_vy = 0;
    input_vx_intent = 0;
    input_vy_intent = 0;

    last_vertex_x = 0; // Grid coordinates
    last_vertex_y = 0;
    
    spider_state = SPIDER_IDLE_ON_CLAIMED;
    claimed_cell_count = 0;
    // path_start_vertex will be set when drawing starts
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            initialize_game_state();
            SetTimer(hwnd, 1, 32, NULL); // ~30 FPS for easier debugging, adjust to 16 for ~60FPS
            return 0;

        case WM_KEYDOWN:
            switch (wParam) {
                // Using pixel velocity directly for intent
                case VK_LEFT:  input_vx_intent = -1; input_vy_intent = 0; break;
                case VK_RIGHT: input_vx_intent = 1;  input_vy_intent = 0; break;
                case VK_UP:    input_vx_intent = 0;  input_vy_intent = -1; break;
                case VK_DOWN:  input_vx_intent = 0;  input_vy_intent = 1; break;
                case VK_SPACE: 
                    spider_vx = 0; spider_vy = 0; 
                    input_vx_intent = 0; input_vy_intent = 0; 
                    if(spider_state == SPIDER_MOVING_ON_CLAIMED) spider_state = SPIDER_IDLE_ON_CLAIMED;
                    // If drawing path and space is hit, Qix rules might mean death or path cancel.
                    // For now, it just stops.
                    if(spider_state == SPIDER_DRAWING_PATH) {
                        // Cancel path drawing
                        clear_current_path_data();
                        spider_x = path_start_vertex_x * (CELL_SIZE + EDGE_SIZE);
                        spider_y = path_start_vertex_y * (CELL_SIZE + EDGE_SIZE);
                        last_vertex_x = path_start_vertex_x;
                        last_vertex_y = path_start_vertex_y;
                        spider_state = SPIDER_IDLE_ON_CLAIMED;
                    }
                    break;
                case 'R': // Reset key
                    initialize_game_state();
                    break;
            }
            return 0;

        case WM_TIMER:
            update_spider();
            update_game_title(hwnd); // Update title with percentage
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            clear_screen(color_light_gray); 

            // Map background in cyan (unclaimed areas default)
            draw_rect(WIN_BORDER + EDGE_SIZE, WIN_BORDER + EDGE_SIZE, MAP_W_PIXELS, MAP_H_PIXELS, color_cyan);
            
            draw_cells();         // Draw claimed cell interiors (light gray)
            draw_paths(false);    // Draw past paths (black)
            draw_paths(true);     // Draw current path (white)
            draw_spider();

            // Outer border of the map area
            // Top
            draw_rect(WIN_BORDER, WIN_BORDER, MAP_W_PIXELS_INCL_EDGE, EDGE_SIZE, color_black);
            // Bottom
            draw_rect(WIN_BORDER, WIN_BORDER + MAP_H_PIXELS_INCL_EDGE - EDGE_SIZE, MAP_W_PIXELS_INCL_EDGE, EDGE_SIZE, color_black);
            // Left
            draw_rect(WIN_BORDER, WIN_BORDER + EDGE_SIZE, EDGE_SIZE, MAP_H_PIXELS, color_black);
            // Right
            draw_rect(WIN_BORDER + MAP_W_PIXELS_INCL_EDGE - EDGE_SIZE, WIN_BORDER + EDGE_SIZE, EDGE_SIZE, MAP_H_PIXELS, color_black);


            BITMAPINFO bmi = {0};
            bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bmi.bmiHeader.biWidth = WIN_W;
            bmi.bmiHeader.biHeight = -WIN_H; 
            bmi.bmiHeader.biPlanes = 1;
            bmi.bmiHeader.biBitCount = 32;
            bmi.bmiHeader.biCompression = BI_RGB;

            StretchDIBits(hdc, 0, 0, WIN_W, WIN_H, 0, 0, WIN_W, WIN_H, pixels, &bmi, DIB_RGB_COLORS, SRCCOPY);
            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_DESTROY:
            KillTimer(hwnd, 1);
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    FILE* fDummy;
    
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MambaClass";
    wc.hbrBackground = NULL; // Important for custom drawing

    RegisterClass(&wc);

    // Adjust window size slightly for borders and title bar
    RECT wr = {0, 0, WIN_W, WIN_H};
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

    HWND hwnd = CreateWindow("MambaClass", "Mamba 1.0", WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             wr.right - wr.left, wr.bottom - wr.top, // Use adjusted size
                             NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}