/**
 * Implements 32-bit multiplication for numbers split into high and low 16-bit parts
 * @param a_lo - Lower 16 bits of first number
 * @param a_hi - Higher 16 bits of first number
 * @param b_lo - Lower 16 bits of second number
 * @param b_hi - Higher 16 bits of second number
 * @returns The 32-bit result of multiplication
 */
export function multiply32bit(a_lo: number, a_hi: number, b_lo: number, b_hi: number): number {
  // If both high parts are 0, we can do a simple multiplication
  if (b_hi === 0 && a_hi === 0) {
    return a_lo * b_lo;
  }
  
  // For the full 32-bit multiplication we need to handle the parts separately
  // Calculate the low part of the result
  const low_result = (a_lo * b_lo) & 0xFFFF;
  
  // Calculate the high part by:
  // 1. Getting the high 16 bits from a_lo * b_lo
  // 2. Adding a_hi * b_lo
  // 3. Adding a_lo * b_hi
  const high_result = (Math.floor((a_lo * b_lo) / 0x10000) + 
                       (a_hi * b_lo) + 
                       (a_lo * b_hi)) & 0xFFFF;
  
  // Combine high and low parts
  return (high_result << 16) | low_result;
}