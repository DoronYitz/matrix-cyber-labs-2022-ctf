/**
 * Extract prime, generator and alice key from incoming message
 *
 * @param message incoming message from netcat
 * @returns prime, generator and alice key
 */
function extractPGA(message: string) {
  let [, prime, generator] = message.match(/p, g = \((\d+), (\d+)\)/);
  let [, aliceKey] = message.match(/A = (\d+)/);
  return { prime: +prime, generator: +generator, aliceKey: +aliceKey };
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
