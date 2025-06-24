/**
 * Implements 32-bit signed integer division for numbers split into high and low 16-bit parts
 * @param a_lo - Lower 16 bits of dividend
 * @param a_hi - Higher 16 bits of dividend
 * @param b_lo - Lower 16 bits of divisor
 * @param b_hi - Higher 16 bits of divisor
 * @returns The result of division as a 32-bit number
 */
export function divide32bitSigned(a_lo: number, a_hi: number, b_lo: number, b_hi: number): number {
  // Track if the result should be negative
  let isNegative = false;
  
  // Handle negative dividend
  if (a_hi < 0) {
    isNegative = !isNegative;
    const borrow = a_lo !== 0 ? 1 : 0;
    a_lo = (-a_lo) & 0xFFFF;
    a_hi = ((-borrow - a_hi) & 0xFFFF);
  }
  
  // Handle negative divisor
  if (b_hi < 0) {
    isNegative = !isNegative;
    const borrow = b_lo !== 0 ? 1 : 0;
    b_lo = (-b_lo) & 0xFFFF;
    b_hi = ((-borrow - b_hi) & 0xFFFF);
  }
  
  let quotientLo = 0;
  let quotientHi = 0;
  
  // Special case: if divisor high part is 0, we can do simpler division
  if (b_hi === 0) {
    quotientHi = Math.floor(a_hi / b_lo);
    
    // Calculate remainder of a_hi / b_lo, then combine with a_lo for next division
    const remainder = a_hi % b_lo;
    const combined = (remainder << 16) | a_lo;
    quotientLo = Math.floor(combined / b_lo);
  } 
  else {
    // For larger divisors, use bit shifting to find quotient
    let tempA_lo = a_lo;
    let tempA_hi = a_hi;
    let tempB_lo = b_lo;
    let tempB_hi = b_hi;
    
    // Normalize by shifting until divisor's high part becomes 0
    let shift = 0;
    while (tempB_hi !== 0) {
      tempB_hi = (tempB_hi >> 1) & 0x7FFF;
      tempB_lo = (tempB_lo >> 1) | ((tempB_hi & 1) << 15);
      
      tempA_hi = (tempA_hi >> 1) & 0x7FFF;
      tempA_lo = (tempA_lo >> 1) | ((tempA_hi & 1) << 15);
      
      shift++;
    }
    
    // Perform division with normalized values
    quotientLo = Math.floor(((tempA_hi << 16) | tempA_lo) / tempB_lo);
    
    // Adjust quotient if needed
    const product_lo = (b_lo * quotientLo) & 0xFFFF;
    const product_hi = Math.floor((b_lo * quotientLo) / 0x10000) + (quotientLo * b_hi);
    
    if (
      (product_hi > a_hi) || 
      (product_hi === a_hi && product_lo > a_lo)
    ) {
      quotientLo--;
    }
  }
  
  // Apply sign to result
  if (isNegative) {
    const borrow = quotientLo !== 0 ? 1 : 0;
    quotientLo = (-quotientLo) & 0xFFFF;
    quotientHi = (-borrow - quotientHi) & 0xFFFF;
  }
  
  // Combine high and low parts
  return (quotientHi << 16) | quotientLo;
}