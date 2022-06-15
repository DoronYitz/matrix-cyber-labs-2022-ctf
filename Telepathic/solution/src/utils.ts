/**
 * Turn number into hex string
 *
 * @param number
 * @param padding default to 2
 * @returns hex string
 */
function decimalToHex(number, padding = 2): string {
  let hex = Number(number).toString(16);

  while (hex.length < padding) {
    hex = "0" + hex;
  }

  return hex;
}

/**
 * Turn hex string to number
 *
 * @param hex hex string
 * @returns number
 */
function hexToDecimal(hex): number {
  return parseInt(hex, 16);
}

export { hexToDecimal, decimalToHex };
