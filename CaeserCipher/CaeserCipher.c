#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Globally declared variables
char encrypted[100];
char decrypted[100];
int key = 8;

//Function to encrypt the message
void encryption(char message[], char alphabets[], char encrypted[]) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char c = message[i];
        int found = 0;

        for (int j = 0; j < 26; j++) {
            if (c == alphabets[j]) {
                int temp = (j + key + 26) % 26;
                encrypted[i] = alphabets[temp];
                found = 1;
                break;
            }
        }
        //Condition for SPACE
        if (!found) {
            encrypted[i] = c;
        }
    }

    //Printing of encrypted text
    encrypted[length] = '\0';
    printf("%s\n", encrypted);
}

//Function to decrypt the encrypted text
void decryption(char encrypted[], char alphabets[], char decrypted[]){
    int length = strlen(encrypted);
    for(int i=0; i<length; i++){
        char c = encrypted[i];
        int found = 0;

        for(int j=0; j<26; j++){
            if (c == alphabets[j]) {
                int temp = (j - key + 26) % 26;         //edge case condition also tackled
                decrypted[i] = alphabets[temp];
                found = 1;
                break;
            }
        }
        //Condition to handle SPACE
        if (!found) {
            decrypted[i] = c;
        }
    }
    //Printing the decrypted text
    decrypted[length = '\0'];
    printf("%s\n", decrypted);
}

int main(){
    char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char message[100];
    printf("Enter your message : ");
    gets(message);
    //Converting the text into upper case for uniformity
    strupr(message);
    printf("Converting into Upper Case : \0");
    printf(message);
    printf("\nThe Ciphered text is : \0");
    encryption(message,alpha,encrypted);
    printf("The decrypted text is : \0");
    decryption(encrypted,alpha,decrypted);
    return 1;
}   
