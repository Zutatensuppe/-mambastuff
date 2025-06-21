#include <windows.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// TODO: draw statistics/infos next to the mamba map
// punkte 
// bild (level)
// leben 
// anteil in %
// zeit in sec

// number of snakes increases over levels (not each level)
// and maybe the speed of snakes? i dont remember

// inner map size. edge is drawn around it
#define MAP_W_PIXELS 455
#define MAP_H_PIXELS 359

// amount of cells in the map
#define MAP_W_CELLS 38
#define MAP_H_CELLS 30

#define CELL_SIZE 11 // inner cell size. edge is drawn around it.

// size in pixels of edge around cells/map
// the edge is ALWAYS drawn around the map
// the edge is drawn around cells captured. the edge is only shown like 
// it was captured by the spider (i.e. the trail the spider leaves 
// behind stays when the area got captured)
// cell size is collapsed to 1 (2 cells next to each other share the edge)
#define EDGE_SIZE 1

#define WIN_W (MAP_W_PIXELS)
#define WIN_H (MAP_H_PIXELS)

bool claimed[MAP_W_CELLS][MAP_H_CELLS];       // claimed cells

// past edges where spider walked and that are locked in 
// (territory is claimed, so these paths cannot be changed anymore)
bool past_path_h[MAP_W_CELLS][MAP_H_CELLS + 1]; // horizontal past path edges
bool past_path_v[MAP_W_CELLS + 1][MAP_H_CELLS]; // vertical past path edges

// current path the spider is taking (excluding the last edge, as that is still incomplete 
// (spider moves along the cells, but not one whole cell at a time. a cell is 11 pixels, 
// but spider walks 1 pixel at a time))
bool path_h[MAP_W_CELLS][MAP_H_CELLS + 1]; // horizontal path edges
bool path_v[MAP_W_CELLS + 1][MAP_H_CELLS]; // vertical path edges

// current spider location in pixels
int spider_x = 0, spider_y = 0;

// current spider velocity in pixels
int spider_vx = 0, spider_vy = 0;

// last vertex the spider was at
int last_vertex_x = 0, last_vertex_y = 0;

int input_vx = 0;
int input_vy = 0;

uint32_t pixels[WIN_W * WIN_H];

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

// Draw claimed cells: light blue, unclaimed remain blue background
void draw_cells() {
    for (int y = 0; y < MAP_H_CELLS; y++) {
        for (int x = 0; x < MAP_W_CELLS; x++) {
            if (claimed[x][y]) {
                draw_rect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, 0xFF87CEFA); // light blue
            }
        }
    }
}

// Draw the web lines on edges
void draw_web() {
    uint32_t web_color = 0xFFFFFFFF; // white

    // Horizontal edges
    for (int y = 0; y <= MAP_H_CELLS; y++) {
        for (int x = 0; x < MAP_W_CELLS; x++) {
            if (past_path_h[x][y]) {
                int px = x * CELL_SIZE;
                int py = y * CELL_SIZE;
                for (int i = 0; i < CELL_SIZE; i++) {
                    int offset_x = px + i;
                    if (offset_x >= 0 && offset_x < WIN_W && py >= 0 && py < WIN_H)
                        pixels[py * WIN_W + offset_x] = web_color;
                }
            }
        }
    }

    // Vertical edges
    for (int x = 0; x <= MAP_W_CELLS; x++) {
        for (int y = 0; y < MAP_H_CELLS; y++) {
            if (past_path_v[x][y]) {
                int px = x * CELL_SIZE;
                int py = y * CELL_SIZE;
                for (int i = 0; i < CELL_SIZE; i++) {
                    int offset_y = py + i;
                    if (px >= 0 && px < WIN_W && offset_y >= 0 && offset_y < WIN_H)
                        pixels[offset_y * WIN_W + px] = web_color;
                }
            }
        }
    }
}

// Draw spider as a small red square centered on vertex
void draw_spider() {
    int px = spider_x;
    int py = spider_y;
    int size = 5; // 5x5 square

    draw_rect(px - size / 2, py - size / 2, size, size, 0xFFFF0000);
}

void update_spider() {
    if (!spider_vx && !spider_vy) return;

    int new_x = spider_x + spider_vx;
    int new_y = spider_y + spider_vy;

    if (new_x < 0 || new_x > WIN_W || new_y < 0 || new_y > WIN_H) {
        spider_vx = 0;
        spider_vy = 0;
        debug_printf("Spider hit map edge and stopped.\n");
        return;
    }

    spider_x = new_x;
    spider_y = new_y;

    debug_printf_fmt("Spider moved to %d,%d\n", spider_x, spider_y);
}

void update_game() {
    update_spider();
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            debug_printf("WM_CREATE.\n");
            spider_x = 0;
            spider_y = 0;
            spider_vx = 0;
            spider_vy = 0;

            SetTimer(hwnd, 1, 16, NULL); // ~60 FPS
            return 0;

        case WM_KEYDOWN:
            debug_printf("WM_KEYDOWN.\n");
            switch (wParam) {
                case VK_LEFT:  input_vx = -1; input_vy = 0; break;
                case VK_RIGHT: input_vx = 1;  input_vy = 0; break;
                case VK_UP:    input_vx = 0;  input_vy = -1; break;
                case VK_DOWN:  input_vx = 0;  input_vy = 1; break;
                case VK_SPACE: spider_vx = 0; spider_vy = 0; input_vx = 0; input_vy = 0; break;
            }
            return 0;

        case WM_TIMER:
            debug_printf("WM_TIMER.\n");
            update_game();
            InvalidateRect(hwnd, NULL, FALSE);
            return 0;

        case WM_PAINT: {
            debug_printf("WM_PAINT.\n");
            debug_printf_fmt("Spider is now at %d,%d\n", spider_vx, spider_vy);
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            clear_screen(0xFF0000FF); // clear blue background

            draw_cells();  // Draw claimed areas only
            draw_web();    // Draw spider web edges
            draw_spider();

            BITMAPINFO bmi = {0};
            bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
            bmi.bmiHeader.biWidth = WIN_W;
            bmi.bmiHeader.biHeight = -WIN_H; // negative for top-down bitmap
            bmi.bmiHeader.biPlanes = 1;
            bmi.bmiHeader.biBitCount = 32;
            bmi.bmiHeader.biCompression = BI_RGB;

            // Draw at normal size (no scaling)
            StretchDIBits(hdc,
                          0, 0, WIN_W, WIN_H,
                          0, 0, WIN_W, WIN_H,
                          pixels, &bmi, DIB_RGB_COLORS, SRCCOPY);

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

    debug_printf("Console allocated.\n");
    
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MambaClass";
    wc.hbrBackground = NULL;

    RegisterClass(&wc);

    HWND hwnd = CreateWindow("MambaClass", "Mamba 1.0", WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, CW_USEDEFAULT,
                             WIN_W + 16, WIN_H + 39,
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
