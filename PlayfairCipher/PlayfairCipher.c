#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Globally declared variables
char spaceLess[100];
char paired[100];
char matrix[5][5];
char encrypted[100];
char decrypted[100];

//Function to remove space from the plain text
void removeSpaces(char text[], char spaceLess[]){
    int message_length = strlen(text);
    int j=0;
    for(int i = 0; i < message_length; i++ ){
        if(text[i]!=' '){
            spaceLess[j] = text[i];
            j++;
        }
    }
}

//Function for pairing
void pairing(char spaceLess[],char paired[]){
    int message_length = strlen(spaceLess);
    int j = 0;
    int i = 0;
    while(i < message_length){
        if(spaceLess[i]!=spaceLess[i+1] && (i+1) < message_length ){
            paired[j]=spaceLess[i];
            paired[j+1]=spaceLess[i+1];
            i+=2;
        }
        //Condition for same letters
        else{
            paired[j]=spaceLess[i];
            paired[j+1]='X';
            i++;
        }
        j+=2;
    }
    paired[j] = '\0';
}

//Function for creating Matrix
void matrixCreation(char keyword[],char matrix[5][5]){
    int seen[26] = {0};
    int row = 0;
    int col = 0;
    //Filling the matrix with the keyword
    for (int i = 0; keyword[i] != '\0'; i++) {
        if (!seen[keyword[i] - 'A']) {
            matrix[row][col++] = keyword[i];
            seen[keyword[i] - 'A'] = 1;
            if (col == 5) {
                row++;
                col = 0;
            }
        }
    }

    // Fill the remaining cells with the alphabet
    char ch = 'A';
    while (row < 5) {
        while (col < 5) {
            if (!seen[ch - 'A']) {
                matrix[row][col] = ch;
                seen[ch - 'A'] = 1;
                col++;
            }
            ch++;
        }
        row++;
        col = 0;
    }
}

//Function to Print Matrix
void printMatrix(char matrix[][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%c ",matrix[i][j]);
        }
        printf("\n");
    }
}

//Function to Encrypt
void encrypt(char paired[], char matrix[][5], char encrypted[]) {
    int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
    int e = 0;

    for (int k = 0; k < strlen(paired); k += 2) {
        bool found1 = false, found2 = false;

        // Finding positions of paired characters in the matrix
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (paired[k] == matrix[i][j]) {
                    i1 = i;
                    j1 = j;
                    found1 = true;
                }
                if (paired[k + 1] == matrix[i][j]) {
                    i2 = i;
                    j2 = j;
                    found2 = true;
                }
                if (found1 && found2) {
                    break;
                }
            }
            if (found1 && found2) {
                break;
            }
        }
        // Same row case
        if (i1 == i2) {
            encrypted[e++] = matrix[i1][(j1 + 1) % 5];
            encrypted[e++] = matrix[i2][(j2 + 1) % 5];
        }
        // Same column case
        else if (j1 == j2) {
            encrypted[e++] = matrix[(i1 + 1) % 5][j1];
            encrypted[e++] = matrix[(i2 + 1) % 5][j2];
        }
        // Rectangle case
        else {
            encrypted[e++] = matrix[i1][j2];
            encrypted[e++] = matrix[i2][j1];
        }
    }
    encrypted[e] = '\0';
}

//Function to Decrypt
void decrypt(char encrypted[], char matrix[][5], char decrypted[]) {
    int i1 = 0, j1 = 0, i2 = 0, j2 = 0;
    int d = 0;
    for (int k = 0; k < strlen(paired); k += 2) {
        bool found1 = false, found2 = false;

        // Finding positions of characters in the matrix
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (encrypted[k] == matrix[i][j]) {
                    i1 = i;
                    j1 = j;
                    found1 = true;
                }
                if (encrypted[k + 1] == matrix[i][j]) {
                    i2 = i;
                    j2 = j;
                    found2 = true;
                }
                if (found1 && found2) {
                    break;
                }
            }
            if (found1 && found2) {
                break;
            }
        }
        // Same row case
        if (i1 == i2) {
            decrypted[d++] = matrix[i1][(j1 - 1 + 5) % 5];
            decrypted[d++] = matrix[i2][(j2 - 1 + 5) % 5];
        }
        // Same column case
        else if (j1 == j2) {
            decrypted[d++] = matrix[(i1 - 1 + 5) % 5][j1];
            decrypted[d++] = matrix[(i2 - 1 + 5) % 5][j2];
        }
        // Rectangle case
        else {
            decrypted[d++] = matrix[i1][j2];
            decrypted[d++] = matrix[i2][j1];
        }
    }
    decrypted[d] = '\0';
}
 
void main(){
    char message[100];
    char keyword[20];
    //Input of Keyword
    printf("Enter your keyword : ");
    gets(keyword);
    strupr(keyword);
    //Input of text
    printf("Enter your message : ");
    gets(message);
    printf("\n");
    //Converting the text into upper case for uniformity
    strupr(message);
    //Removing spaces in the text
    removeSpaces(message,spaceLess);
    printf(spaceLess);
    printf("\n");
    //Pairing the letters in the text
    pairing(spaceLess,paired);
    printf(paired);
    printf("\n");
    printf("\n");
    //Martix Creation 
    matrixCreation(keyword,matrix);
    printMatrix(matrix);
    printf("\n");
    //Encryption
    encrypt(paired,matrix,encrypted);
    printf(encrypted);
    printf("\n");
    //Decryption
    decrypt(encrypted,matrix,decrypted);
    printf(decrypted);
}