#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Globally declared variables
char encrypted[100];
char decrypted[100];
int key = 5;

//Function to encrypt the message
void encrypt(char message[], char alphabets[], char encrypted[]) {
    int length = strlen(message);
    for (int i = 0; i < length; i++) {
        char c = message[i];
        int found = 0;

        for (int j = 0; j < 26; j++) {
            //Condition to encrypt even characters
            if (c == alphabets[j] && i%2==0) {
                int temp = (j + key) % 26;
                encrypted[i] = alphabets[temp];
                found = 1;
                break;
            }
            //Condition to encrypt even characters
            else if(c == alphabets[j] && i%2!=0){
                int temp = (j - key + 26) % 26;
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
void decrypt(char encrypted[], char alphabets[], char decrypted[]){
    int length = strlen(encrypted);
    for(int i=0; i<length; i++){
        char c = encrypted[i];
        int found = 0;

        for(int j=0; j<26; j++){
            //Condition to decrypt even characters
            if (c == alphabets[j] && i%2==0) {
                int temp = (j - key + 26) % 26;        
                decrypted[i] = alphabets[temp];
                found = 1;
                break;
            }
            //Condition to decrypt odd characters
            else if(c == alphabets[j] && i%2!=0){
                int temp = (j + key) % 26;
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

void main(){
    char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char message[100];
    printf("Enter your message : ");
    gets(message);
    //Converting the text into upper case for uniformity
    strupr(message);
    printf("Converting into Upper Case : \0");
    printf(message);
    printf("\nThe Ciphered text is : \0");
    encrypt(message,alpha,encrypted);
    printf("The decrypted text is : \0");
    decrypt(encrypted,alpha,decrypted);
}   