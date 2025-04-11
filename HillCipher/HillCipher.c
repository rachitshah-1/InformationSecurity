#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 2

// Modulo of a number
int mod(int a, int b) {
    return (a % b);
}

// Multiplicative inverse of a number modulo 26
int multiplicativeInverse(int a) {
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            return i;
        }
    }
    return -1;
}

// Determinant of a 2x2 matrix
int determinant(int matrix[SIZE][SIZE]) {
    return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
}

// Print a 2x2 matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Print a vector (for plaintext / ciphertext blocks)
void printVector(int vector[SIZE], char label[]) {
    printf("%s: [", label);
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", vector[i]);
    }
    printf("]\n");
}

// Inverse of the key matrix modulo 26
int matrixInverse(int keyMatrix[SIZE][SIZE], int inverseKeyMatrix[SIZE][SIZE]) {
    int det = determinant(keyMatrix);
    int detInverse = multiplicativeInverse(mod(det, 26));

    if (detInverse == -1) {
        printf("Key matrix is not invertible.\n");
        return -1;
    }

    inverseKeyMatrix[0][0] = mod(keyMatrix[1][1] * detInverse, 26);
    inverseKeyMatrix[1][1] = mod(keyMatrix[0][0] * detInverse, 26);
    inverseKeyMatrix[0][1] = mod(-keyMatrix[0][1] * detInverse, 26);
    inverseKeyMatrix[1][0] = mod(-keyMatrix[1][0] * detInverse, 26);
    return 0;
}

// Multiply two matrices modulo 26
void multiplyMatrices(int keyMatrix[SIZE][SIZE], int message_vector[SIZE], int result[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < SIZE; j++) {
            result[i] += keyMatrix[i][j] * message_vector[j];
        }
        result[i] = mod(result[i], 26);
    }
}

// Encryption
void encrypt(char message[], int keyMatrix[SIZE][SIZE], int messageLength, char encrypted[]) {
    int message_vector[SIZE];
    int cipher_vector[SIZE];

    // Print key matrix
    printf("\nKey matrix used for encryption\n");
    printMatrix(keyMatrix);

    for (int i = 0; i < messageLength; i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            message_vector[j] = message[i + j] - 'A';  // Convert char to int
        }

        // Print the message vector (plaintext block)
        printVector(message_vector, "\nPlaintext Block");

        multiplyMatrices(keyMatrix, message_vector, cipher_vector);

        // Print the resulting cipher vector
        printVector(cipher_vector, "Ciphertext Block");

        for (int j = 0; j < SIZE; j++) {
            encrypted[i + j] = cipher_vector[j] + 'A';
        }
    }
    encrypted[messageLength] = '\0';
}

// Decryption
void decrypt(char encrypted[], int keyMatrix[SIZE][SIZE], int messageLength, char decrypted[]) {
    int encrypted_vector[SIZE];
    int plaintext_vector[SIZE];
    int inverseKeyMatrix[SIZE][SIZE];

    if (matrixInverse(keyMatrix, inverseKeyMatrix) == (-1 | 0)) {
        printf("Cannot decrypt due to non-invertible key matrix.\n");
        printf("----------------------------------------------------");
        exit(0);
    }

    printf("\nInverse key matrix used for decryption:\n");
    printMatrix(inverseKeyMatrix);  // Print inverse key matrix

    for (int i = 0; i < messageLength; i += SIZE) {
        for (int j = 0; j < SIZE; j++) {
            encrypted_vector[j] = encrypted[i + j] - 'A';
        }

        // Print the encrypted vector (ciphertext block)
        printVector(encrypted_vector, "\nCiphertext Block");

        multiplyMatrices(inverseKeyMatrix, encrypted_vector, plaintext_vector);

        // Print the resulting plaintext vector
        printVector(plaintext_vector, "Decrypted Plaintext Block");

        for (int j = 0; j < SIZE; j++) {
            decrypted[i + j] = plaintext_vector[j] + 'A';
        }
    }
    decrypted[messageLength] = '\0';
}

int main() {
    int keyMatrix[SIZE][SIZE];
    char plaintext[100];  
    char keyInput[SIZE * SIZE];  
    char encrypted[100];
    char decrypted[100];
    int messageLength;

    // Key matrix input
    printf("\nEnter the 2x2 key matrix (4 alphabetic characters) : ");
    scanf("%s", keyInput);
    strupr(keyInput);

    if(strlen(keyInput)>SIZE*2){
        printf("Key matrix size is too large.\n");
        exit(0);
    }

    // Convert alphabetic key to numeric values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            keyMatrix[i][j] = keyInput[i * SIZE + j] - 'A';
        }
    }

    // Plaintext input
    printf("Enter the plaintext : ");
    scanf("%s", plaintext);
    strupr(plaintext);

    messageLength = strlen(plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, keyMatrix, messageLength, encrypted);
    printf("------------------------------------\n");
    printf("Encrypted Text : %s\n", encrypted);
    printf("------------------------------------\n");

    // Decrypt the encrypted text
    decrypt(encrypted, keyMatrix, messageLength, decrypted);
    printf("------------------------------------\n");
    printf("Decrypted Text : %s\n", decrypted);
    printf("------------------------------------\n");
    
    return 0;
}
