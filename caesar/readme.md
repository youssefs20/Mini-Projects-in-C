# Caesar Cipher (C Language)

A simple implementation of the **Caesar Cipher encryption algorithm** using the C programming language — without using the CS50 library.

## 📌 Overview

Caesar Cipher is one of the oldest known encryption techniques. It encrypts a message by shifting each letter by a number (`key`) provided by the user.

Example:  
If the key = `2`

-   A → C
-   B → D
-   H → J

We use the formula:

-   ci = (pi + k) % 26

Where:

-   `pi` = index of the character in the plaintext (0 → 25)
-   `k` = key (number of shifts)
-   `ci` = index of encrypted letter (cipher text)

---

## 🚀 Features

-   Works with uppercase and lowercase letters.
-   Keeps non-alphabetic characters unchanged (spaces, punctuation, numbers…).
-   Validates that the key entered is a **numeric value**.
-   Doesn't depend on **CS50 library**.

---

## 🛠️ How to Use

### 1. Compile the program

```sh
gcc caesar.c -o caesar
```

### 2. Run the executable and provide the key

```sh
./caesar 5
```

### Enter the text you want to encrypt

for ex :

```sh
text: Hello, World!
ciphertext: Mjqqt, Btwqi!
```

---

### pseudo code

1. Check if the command line argument (key) exists
2. Check that the key is numeric (not a letter or symbol)
3. Convert the key from string to integer
4. Ask the user to enter plaintext
5. Loop through each character in the plaintext:
    - If uppercase → rotate within A-Z
    - If lowercase → rotate within a-z
    - If not a letter → print as is
6. Print ciphertext

---

### Ex output

```sh
$ ./caesar 3
text: abc XYZ!
ciphertext: def ABC!
```
