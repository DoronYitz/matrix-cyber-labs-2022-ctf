# Plagiarism

---

In this challenge we have message, and a `flag.txt` file.

##### Message

> I wish there was a more human friendly way to keep track of it all.

##### Goal

We need to find the flag somehow using the `flag.txt` file.

##### Solution

First step

We used google and translated `Plagiarism`, and we found a slight connection to Books.

Then, we noticed `082182676X` sequence which means it it's HEX or something else.
And we try to google it.

And found out it is `ISBN-10` number of `John Von Neumann: The Scientific Genius Who Pioneered the Modern`.
Then, we trying the flag template which is `MCL{_____________}` 
And notice that `1 5 22 { 1 36 6 8 24 15 17 13 16 40 7 }` is the letter we should take. 

Example

```
0061186422
"M Is for Magic" 
1
We take letter "M"
```

##### Plan:

- Google each ISBN 10 and get the book name
- Take the letter on the `x` position and add it to the flag

##### Flag

```
MCL{Bookworming}
```
