# Telepathic

---

In this challenge we have an interactive shell using netcat, after connecting we have a message.

##### Message

```
nc 0.cloud.chals.io 16499
```

> Welcome player!
> What if told you that colour mixing is essential for telepathy?
> I claim that you and I can arrive at the same number no matter how many times we do so,
> simply by using the right amounts in the correct order :).

> Sync your inner telepathy with mine, for no more than 32 consecutive rounds and get the flag*, easy.
> (*telepathic beings can be very nosy, so I'll be sure to encrypt it beforehand.)

##### Goal

We need to get somehow the encrypted flag, and decrypt it.

##### Solution

First step
Server is sending message like:

> p, g = (251, 57)
> A = 94
> $ enter your number

We need to enter a number for 32 consecutive rounds.

Tried to spam 2 for 32 times, almost 70% of the times it worked and we found out another message:

> Great Job!
> If all went well we should have synced-up telepathically :).
> Here is an IV: quAkn+JVJoiDCw4mLqyl6g==
> and an encrypted flag: arX1FQ7+UyRHm3jrbu1FfwdqLBWL4ma2BhJmzSIRhFSAzQ/neHWjJZE0ykhf7kR5

Means we have the Initial vector, the encryped flag, but we need to achieve the key somehow.

##### Diffie Hellman

A way to exchange shared keys to encryped data between people.

E.g from node documentation

```
import assert from 'assert';

const {
  createDiffieHellman
} = await import('crypto');

// Generate Alice's keys...
const alice = createDiffieHellman(2048);
const aliceKey = alice.generateKeys();

// Generate Bob's keys...
const bob = createDiffieHellman(alice.getPrime(), alice.getGenerator());
const bobKey = bob.generateKeys();

// Exchange and generate the secret...
const aliceSecret = alice.computeSecret(bobKey);
const bobSecret = bob.computeSecret(aliceKey);

// OK
assert.strictEqual(aliceSecret.toString('hex'), bobSecret.toString('hex'));
```

Read more here https://www.cs.umd.edu/~gasarch/COURSES/389/W14/newciphers.pdf

p,g - means prime and generator
A means alice key

Alice is basicly the server and we are Bob.

We need to use prime and generator to generate our "Bob" key - and send the key to alice.
Next lets compute secret using alice key, prime and generator and save it.

- alice secret computation and ours computation has the same result, means we can achieve the same key alice encrypted the flag.

After 32 rounds we have arr of numbers which is the shared key. Let decrypt the flag.

##### Aes256

We have to identify the encoding of the given encrypted flag and the iv.

- IV is base64 according to the `==`
- Encrypted flag is base64url

##### Plan:

- Generate keys using prime and generator
- Calculate the shared key each round and save it
- Send over to alice our key
- Iterate above over 32 rounds
- Decrypt the key using AES256

##### Flag

```
MCL{4_D1fFeR3n7_HeLLM4nNs_kEy_3xCh4ngE}
```
