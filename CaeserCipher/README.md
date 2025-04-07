# Caesar Cipher Implementation

This repository contains C implementations of the Caesar Cipher and a document detailing the code, explanations, outputs, and comparisons.

## Files

* **`CaesarCipher.c`**: A basic C implementation of the Caesar Cipher.
* **`RevisedCaesarCipher.c`**: An enhanced version of the Caesar Cipher with potential improvements or modifications.
* **`CaesarCipher.docx`**: A Microsoft Word document containing:
    * Detailed explanations of the Caesar Cipher algorithm.
    * The C code for both implementations.
    * Example outputs.
    * Comparisons between the basic and revised versions.
    * Any other relevant information.

## Caesar Cipher Overview

The Caesar Cipher is a simple substitution cipher where each letter in the plaintext is shifted a certain number of places down the alphabet. For example, with a shift of 3, A would be replaced by D, B would become E, and so on.

## `CaesarCipher.c`

This file provides a straightforward implementation of the Caesar Cipher. It demonstrates the core logic of shifting characters by a specified key.
## `RevisedCaesarCipher.c`

This file contains a potentially modified or improved version of the Caesar Cipher.

## `CaesarCipher.docx`

The Word document provides a comprehensive overview of the Caesar Cipher implementations. It includes:

* **Algorithm Explanation:** A detailed explanation of how the Caesar Cipher works.
* **Code Walkthrough:** A breakdown of the C code, explaining each part.
* **Output Examples:** Sample inputs and corresponding outputs for both implementations.
* **Comparison:** A comparison of the basic and revised versions, highlighting their differences and advantages.
* **Usage Instructions:** How to compile and run the C programs.

## Usage

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/rachitshah-1/InformationSecurity
    ```
2.  **Navigate to the directory:**
    ```bash
    cd CaesarCipher
    ```
3.  **Compile the C code:**
    ```bash
    gcc CaesarCipher.c -o caesar
    gcc RevisedCaesarCipher.c -o revised_caesar
    ```
4.  **Run the programs:**
    ```bash
    ./caesar
    ./revised_caesar
    ```
5.  **Open `CaesarCipher.docx`** for detailed information.

## Contributing

If you have any improvements or suggestions, feel free to contribute by submitting a pull request.
