#   Hill Cipher: A Polygraphic Substitution Cipher
This directory explores the Hill Cipher, an encryption technique that uses linear algebra.

##   Introduction
The Hill Cipher is an encryption method that employs linear algebra to secure messages through matrix multiplication.
In the Hill Cipher:
* Plaintext is divided into blocks of letters.
* These letters are represented by numerical values based on their position in the alphabet (e.g., A=0, B=1, ..., Z=25).
* Each block is multiplied by an invertible key matrix.
* This multiplication produces a new set of numerical values, forming the ciphertext.

This method encrypts multiple letters simultaneously, enhancing security compared to simpler ciphers. However, it's important to note that the Hill Cipher is vulnerable to known-plaintext attacks and frequency analysis.

##   Original Approach
In the original Hill Cipher:
* An n x n invertible matrix is chosen as the key.
* Plaintext letters are converted to numbers and split into blocks of size n.
* Encryption involves multiplying each plaintext block by the key matrix and then applying modulo 26.
* Decryption involves multiplying the ciphertext blocks by the inverse of the key matrix (modulo 26) to recover the plaintext.

**Example:**
* Key = HELP, Plaintext = EXAM [cite: 105]
* Key Matrix:

    ```
    7   4
    11  15
    ```

* Plaintext Blocks: \[4, 23] and \[0, 12]  (representing EX and AM) [cite: 105]
* Ciphertext: QZWY [cite: 108]

##   Revised Approach
The revised approach to the Hill Cipher alters the way the key matrix is filled. [cite: 115, 116, 117] Instead of the traditional row-wise (row-major order), the key matrix is filled column-wise (column-major order). [cite: 115, 116, 117] This change affects how the matrix interacts with the plaintext during encryption and decryption. [cite: 116, 117]

**Example:**
* Key = ABCD
* Row-major matrix:

    ```
    A B
    C D
    ```

* Column-major matrix:

    ```
    A C
    B D
    ```

##   Comparative Analysis

Here's a comparison of the original and revised Hill Cipher approaches:

| Aspect                   | Original Approach (Row-major)              | Revised Approach (Column-major)               |
| :----------------------  | :----------------------------------------  | :-------------------------------------------  |
| Matrix Filling Order     | Fills the matrix left to right along rows. | Fills the matrix top to bottom along columns. |
| Example Key Input "ABCD" | \[A B]<br>\[C D]                           | \[A C]<br>\[B D]                              |
| Numerical Representation | \[0 1]<br>\[2 3]                           | \[0 2]<br>\[1 3]                              |
| Encryption Process       | Multiplication is row-major.               | Multiplication is row-major.                  |
| Decryption Process       | Inverse matrix is used row-wise.           | Inverse matrix is used column-wise.           |
| Usability                | Intuitive and common.                      | Useful for systems needing column-major.      |
| Drawback                 | Not suitable if column-major is needed.    | Less common, may require adjustments.         |

##   Conclusion

The primary difference between the original and revised Hill Cipher approaches is the order in which the key matrix is filled and used in matrix multiplication. The original row-major approach is generally more intuitive, while the revised column-major approach may be preferred in specific systems. Both approaches achieve the fundamental goal of the Hill Cipher: securing plaintext using matrix-based transformations.
