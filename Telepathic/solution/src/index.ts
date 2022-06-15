import { createDiffieHellman, createDecipheriv } from "crypto";
import NetcatClient from "netcat/client";

import { decimalToHex, hexToDecimal } from "./utils";
import { extractIVAndFlag, extractPGA } from "./extract-text";

// Key - MCL{4_D1fFeR3n7_HeLLM4nNs_kEy_3xCh4ngE}
const hexKeyArr: string[] = [];

// Init netcat client
const nc2 = new NetcatClient();

// Port and host
const PORT = 16499;
const HOST = "0.cloud.chals.io";

// Connect using netcat
const inputStream = nc2.addr(HOST).port(PORT).connect().stream();

// Log incoming data
inputStream.on("data", (incomingMsg) => {
  // Turn data into string
  let message = Buffer.from(incomingMsg).toString().trim();
  console.log(message);

  // If key len is 32, means iterations are done and we got the iv and the encrypted flag
  if (hexKeyArr.length === 32) {
    const { ivBase64, flagBase64url } = extractIVAndFlag(message);
    const flag = decrypt(flagBase64url, ivBase64, hexKeyArr);
    console.log(flag);
    return;
  }

  /**
   * Extract prime, generator and alice key from message
   * p - prime, g - generator, A - alice key
   */
  const { prime, generator, aliceKey } = extractPGA(message);
  console.log(`p,g (${prime},${generator}) , Alice: ${aliceKey}`);

  // Init diffie hellman
  const bob = createDiffieHellman(decimalToHex(prime), "hex", generator);

  // Generate bob keys, return the public key
  const bobKey = bob.generateKeys("hex");

  // Generate bob secret
  const bobSecret = bob.computeSecret(decimalToHex(aliceKey), "hex", "hex");

  // Saving secret
  hexKeyArr.push(bobSecret);

  // Sending bob key to alice
  sendMsg(nc2, hexToDecimal(bobKey));
});

/**
 * This function sends a message using nc
 *
 * @param nc2 nc client
 * @param message message
 */
function sendMsg(nc2, number: number) {
  console.log(">", number);
  nc2.send(number + "\n");
}

/**
 * Decrypt text using aes
 *
 * @param textBase64Url flag in base64url
 * @param ivBase64 iv in base 64
 * @param hexKeyArr hex key arr
 * @returns decrypted text
 */
export function decrypt(textBase64Url: string, ivBase64: string, hexKeyArr: string[]): string {
  const ivBytes = Buffer.from(ivBase64, "base64");
  const keyArr = hexKeyArr.map((x) => parseInt(x, 16));
  const keyBytes = Buffer.from(keyArr);

  let decipher = createDecipheriv("aes-256-cbc", keyBytes, ivBytes);
  let decrypted = decipher.update(textBase64Url, "base64url", "utf8");
  return decrypted + decipher.final("utf8");
}
