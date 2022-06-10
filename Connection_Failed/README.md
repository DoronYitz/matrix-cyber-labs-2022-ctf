# Connection_Failed

---

In this challenge we have message, and a interactive shell using netcat, and `Connection_failed.zip` which contains server and client files

##### Message

> Can you help me in establishing a connection and get the flag?

```
nc 0.cloud.chals.io 24939
```

##### Goal

We need to establish the connection to recive the flag from the server.

##### Solution

First step

Using ghidra, we deassembled and decomplied both client and server file. Then we noticed few things.

First one:

```
iVar1 = strcmp((char *)&local_3c,"YES");
  if (iVar1 == 0) {
    iVar1 = socket(2,1,0);
    if (iVar1 < 0) {
      puts("\n Socket creation error ");
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = inet_pton(2,(char *)&local_32,local_54);
      if (iVar2 < 1) {
        puts("\nInvalid address/ Address not supported ");
        uVar3 = 0xffffffff;
      }
```

It is using strcmp to compare between our input and the string "YES"

Second one:

```
local_33 = 0x33332e312e373231;
local_2b = 0x372e;
```

Means we the server ip on localhost is `127.1.33.7`

###### Buffer Overflow

After few different ideas, we trying to assert a null byte to abuse strcmp mechanic

```
YES\0AAAAAA
```

And we noticed a different message

> Invalid address/ Address not supported

Which means the null byte works.

Next, we tried to changed the ip using Buffer overflow to override the property of `local_32` on client.c file which is the ip address of the server with different paddings:

```
YES\0A127.1.33.7
YES\0AA127.1.33.7
YES\0AAA127.1.33.7
YES\0AAAA127.1.33.7
YES\0AAAAA127.1.33.7
YES\0AAAAAA127.1.33.7
```

##### Plan:

- Abuse strcmp mechanic using nullbyte `\0`
- Create a buffer overflow to override the ip with the correct ip address of the server.
- Get the flag

##### Output:

Do you want the flag ?
Request flag from the server
Server response

##### Flag

```
MCL{1t5_51mpLE_b0f}
```
