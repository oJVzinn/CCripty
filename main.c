#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* criptMessage(char* message);
char* uncriptMessage(char* message);

void main() {
    bool continueLoop = true;
    while (continueLoop) {
        printf("\nDigite uma mensagem: \n");
        char message[100];
        scanf("%s", &message);

        char* encrypted = criptMessage(message);
        printf("Sua mensagem criptografada e: %s\n", encrypted);

        bool sendOption = true;
        char option;
        while (sendOption) {
            printf("Voce deseja decriptografar? S - Sim ou N - Nao\n");
            scanf("%s", &option);
            if (tolower(option) == 's' || tolower(option) == 'n') {
                sendOption = false;
            }
        }

        if (tolower(option) == 's') {
            char* uncripted = uncriptMessage(encrypted);
            printf("Sua mensagem decriptografada e %s\n", uncripted);
            free(uncripted);
        }

        free(encrypted);
        sendOption = true;
        while (sendOption) {
            printf("Deseja finalizar ou criptografar outra mensagem? 1 - Continuar ou 2 - Fim\n");
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
        messageCript[i] = message[i] + 4;
    }

    messageCript[stringLen] = '\0';

    return messageCript;
}

char* uncriptMessage(char* message) {
    const int stringLen = strlen(message);
    char* messageCript = malloc(stringLen + 1);
    for (int i = 0; i < stringLen; i++) {
        messageCript[i] = message[i] - 4;
    }

    messageCript[stringLen] = '\0';
    return messageCript;
}