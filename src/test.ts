import { multiply32bit } from './functions/multiply32bit';
import { divide32bitSigned } from './functions/divide32bitSigned';


const additional_blocks = 5;


// Given values
const g_filled_blocks_count_lo = 1140;
const g_filled_blocks_count_hi = 0;
const b_lo = 0x3f7; // 1015 in decimal
const b_hi = 0;

// Calculate the result
const lVar5 = multiply32bit(g_filled_blocks_count_lo, g_filled_blocks_count_hi, 100, 0);
console.log("Result of multiplication:", lVar5);

// Extract high and low parts of lVar5
const lVar5_lo = lVar5 & 0xFFFF;
const lVar5_hi = (lVar5 >> 16) & 0xFFFF;

// Perform division
const uVar4 = divide32bitSigned(lVar5_lo, lVar5_hi, b_lo, b_hi);
console.log("Final result:", uVar4);

// Get the high and low parts of the result
const result_lo = uVar4 & 0xFFFF;
const result_hi = (uVar4 >> 16) & 0xFFFF;
console.log("Result low part:", result_lo);
console.log("Result high part:", result_hi);
