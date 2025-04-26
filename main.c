#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* criptMessage(char* message);
char* decryptMessage(char* message);
char convertSymbolToNumber(char c);
char convertNumberToSymbol(char c);

void main() {
    bool continueLoop = true;
    while (continueLoop) {
        printf("\nDigite uma mensagem: \n");
        char message[100];
        scanf("%s", message);

        char* encrypted = criptMessage(message);
        printf("Sua mensagem criptografada e: %s\n", encrypted);


        bool sendOption = true;
        char option;
        while (sendOption) {
            printf("\nVoce deseja decriptografar? S - Sim ou N - Nao\n");
            scanf("%s", &option);
            if (tolower(option) == 's' || tolower(option) == 'n') {
                sendOption = false;
            }
        }

        if (tolower(option) == 's') {
            char* decrypted = decryptMessage(encrypted);
            printf("Sua mensagem decriptografada e %s\n", decrypted);
            free(decrypted);
        }

        free(encrypted);
        sendOption = true;
        while (sendOption) {
            printf("\nDeseja finalizar ou criptografar outra mensagem? 1 - Continuar ou 2 - Fim\n");
            scanf("%s", &option);
            if (option == '1' || option == '2') {
                sendOption = false;
            }
        }

        if (option == '2') {
            continueLoop = false;
        }
    }
}

char* criptMessage(char* message) {
    const int stringLen = strlen(message);
    char* messageCript = malloc(stringLen + 1);

    for (int i = 0; i < stringLen; i++) {
        const char now = message[i];
        if (isdigit(now)) messageCript[i] = convertNumberToSymbol(now);
        else messageCript[i] = message[i] + 4;
    }

    messageCript[stringLen] = '\0';
    return messageCript;
}

char* decryptMessage(char* message) {
    const int stringLen = strlen(message);
    char* messageCript = malloc(stringLen + 1);
    for (int i = 0; i < stringLen; i++) {
        const char now = message[i];
        if (strchr("%^&*()!@#$", now))messageCript[i] = convertSymbolToNumber(now);
        else messageCript[i] = message[i] - 4;
    }

    messageCript[stringLen] = '\0';
    return messageCript;
}

char convertSymbolToNumber(char c) {
    switch(c) {
        case '%': return '1';
        case '^': return '2';
        case '&': return '3';
        case '*': return '4';
        case '(': return '5';
        case ')': return '6';
        case '!': return '7';
        case '@': return '8';
        case '#': return '9';
        case '$': return '0';
        default: return c;
    }
}


char convertNumberToSymbol(char c) {
    switch(c) {
        case '1': return '%';
        case '2': return '^';
        case '3': return '&';
        case '4': return '*';
        case '5': return '(';
        case '6': return ')';
        case '7': return '!';
        case '8': return '@';
        case '9': return '#';
        case '0': return '$';
        default: return c;
    }
}
