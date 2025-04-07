# Caesar Cipher: A Study in Classical Encryption
This directory the Caesar Cipher, a foundational technique in cryptography, with a focus on both its traditional form and a revised implementation.

## Introduction
The Caesar Cipher falls under the category of a Substitution Cipher. In this cipher, plaintext is transformed by shifting each letter a fixed number of positions up or down the alphabet. The amount of this shift is known as the "key".

For example, if we encrypt "I AM RACHIT SHAH" with a key of 5, the result is "N FR WFHMNY XMFM".

## Original Approach
The original Caesar Cipher involves a uniform shift of all characters based on the key.

## Revised Approach
A revised approach introduces a variation where characters at even positions are shifted to the right, and characters at odd positions are shifted to the left.

For instance, encrypting "I AM RACHIT SHAH" with a key of 5 using this revised method yields "N FH MFXMDY XCFC".

## Comparative Analysis
The traditional Caesar Cipher is inherently simple, making it vulnerable to attacks like brute-force, where all 25 possible shifts can be tested. However, the revised approach increases the difficulty of decryption.

Here's why the revised approach is more complex:
* **Repetition of Shifted Values:** A single plaintext letter might be encrypted to the same ciphertext letter at different positions.
* **Variation in Shift Values:** The same plaintext letter can be encrypted to different ciphertext letters depending on its position.

These factors make it harder to decode without knowing the method. Even if an attacker guesses the key, it may not lead to successful decryption.

Consider the example "I AM RACHIT SHAH" encrypted as "N FH MFXMDY XCFC" with a key of 5.  If an attacker uses a key of 5:

* The original approach correctly decrypts to "I AM RACHIT SHAH".
* The revised approach decrypts to "I AC HASHYT SXAX".

This demonstrates the enhanced security of the revised method compared to the original.
