#include <stdio.h>
#define size 80

int main(void)
{
        int message[size] = {' '};
        int ciphertext[size] = {' '};
        int shift;
        int i = 0;
        char ch;
        char option;
        printf("Welcome to the Caesar Cipher machine.\n");
        printf("Enter your message: ");
        while ((ch = getchar()) != '\n')
        {
                message[i] = ch;
                i++;
        }
        printf("Enter shift amount (1-25): ");
        scanf("%d", &shift);
        printf("Choose from the following options: \n");
        printf("e: encrypt a plaintext message\nd: decrypt a ciphertext\n");
        scanf(" %c", &option);
        if (option == 'd')
                shift = 26 - shift;
        printf("Encrypted message: ");
        for (int j = 0; j < size; j++)
        {
                switch(message[j])
                {
                        /*Allows encryption to skip over spaces and punctuation*/
                        case 32: case 33: case 39: case 44: case 46: case 63:
                             ciphertext[j] = message[j];
                }

                if ((message[j] >= 97) && (message[j]<= 122))
                                ciphertext[j] = ((message[j] - 'a') + shift) % 26 + 'a';
                if ((message[j] >= 65) && (message[j]<= 90))
                                ciphertext[j] = ((message[j] - 'A') + shift) % 26 + 'A';
                printf("%c", ciphertext[j]);
        }
        printf("\n");
        return 0;

}
