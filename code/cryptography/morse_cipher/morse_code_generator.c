/* Part of Cosmos by OpenGenus Foundation */
//C implementation of morse code generator
#include <stdio.h>
#include <string.h>

void encrypt(char* msg){
    int i, size;
    char morse_code[1000] = "";

    // Morse Code for the numbers [0-10]
    char* num[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
    // Morse Code for the alphabet
    char* letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                      "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    size = strlen(msg);
    for(i=0;i < size; i++)
        if(msg[i]!=' ')
            if(msg[i] >= '0' && msg[i] <= '9')
                strcat(morse_code, num[msg[i] - 48]);
            else
                strcat(morse_code, letters[msg[i] - 65]);

        else
            strcat(morse_code, " ");

    printf("%s\n", morse_code);
}

int main(){
    char* msg = "CONVERT THIS MORSE CODE";
    encrypt(msg);

    return 0;
}
