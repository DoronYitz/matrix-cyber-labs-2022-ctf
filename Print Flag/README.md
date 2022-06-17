# Print Flag

---

In this challenge we a script `print_flag.py`, and a method we need to implement called `toString()`

##### Message

> I have a code that prints a flag :)
> Unfortunately one function is missing, can you mend it?

##### Goal

Implement toString() and get the flag.

##### Solution

After few attempts that failed, I tryed the simplest solution, trying to turn a number into a string.

E.g
7 -> Seven

Then, the toString method will pick a random at `letter[1]`

```
flag += toString(letter[0])[letter[1]]
```

And it worked

##### Flag

```
MCL{nuM_to_words}
```
