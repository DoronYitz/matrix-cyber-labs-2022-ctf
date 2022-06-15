/**
 * Extract prime, generator and alice key from incoming message
 *
 * @param message incoming message from netcat
 * @returns prime, generator and alice key
 */
function extractPGA(message: string) {
  let numsInBrackets = message
    .match(/\(\d.*?\)/g)[0]
    .replace(/[{()}]/g, "")
    .split(", ");
  let prime = +numsInBrackets[0];
  let generator = +numsInBrackets[1];
  let equalsIndex = message.lastIndexOf("=");
  let dollarIndex = message.lastIndexOf("$");
  let aliceKey = +message.slice(equalsIndex + 2, dollarIndex - 1).trim();
  return { prime, generator, aliceKey };
}

/**
 * Extract iv and flag from incoming message
 *
 * @param message incoming message from netcat
 * @returns object contains iv as base64 and flag base64 url
 */
function extractIVAndFlag(message: string): { ivBase64: string; flagBase64url: string } {
  let ivIndex = message.indexOf("IV:");
  let paddingIndex = message.indexOf("==");
  let flagIndex = message.indexOf("flag:");
  const ivBase64 = message.slice(ivIndex + 4, paddingIndex + 2).trim();
  const flagBase64url = message.slice(flagIndex + 6).trim();
  return { ivBase64, flagBase64url };
}

export { extractIVAndFlag, extractPGA };
