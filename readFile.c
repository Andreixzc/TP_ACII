#include <stdio.h>
#include<string.h>

int main() {
    FILE *file = fopen("testeula.ula", "r"); // Abre o arquivo para leitura
    FILE *resultado = fopen("testeula.hex", "w"); //Abre arquivo com codigo Hexadecimal
    char buffer[256];

    if (file == NULL) {
        perror("Falha ao abrir o arquivo");
        return 1; // Retorna um código de erro
    }

    char x, y, w;
    char str[10];

    // Lê o arquivo linha por linha
    while (fgets(buffer, sizeof(buffer), file) != NULL) {

        if(strcmp(buffer, "fim.") == 0) {printf("acabou!\n"); return 0;}
        
        if(buffer[0] == 'X') x = buffer[2];

        else if(buffer[0] == 'Y') y = buffer[2];

        else if(buffer[0] == 'W'){
            for(int i = 2; i < strlen(buffer) - 1; i++){
                //Encerra o loop quando chegar no ponto e virgula e coloca fim na string do comando
                if(buffer[i] == ';') {
                    str[i-2] = '\0'; 
                    i = strlen(buffer);
                }
                

                else {
                    str[i-2] = buffer[i];
                }
            }

            if (strcmp(str, "umL") == 0) {
                w = '0'; // Para "umL"
            } else if (strcmp(str, "A+B") == 0) {
                w = '1';
            } else if (strcmp(str, "copiaA") == 0) {
                w = '2';
            } else if (strcmp(str, "nAxnB") == 0) {
                w = '3';
            } else if (strcmp(str, "AeBn") == 0) {
                w = '4';
            } else if (strcmp(str, "nA") == 0) {
                w = '5';
            } else if (strcmp(str, "AenB") == 0) {
                w = '6';
            } else if (strcmp(str, "nAonB") == 0) {
                w = '7';
            } else if (strcmp(str, "AxB") == 0) {
                w = '8';
            } else if (strcmp(str, "zeroL") == 0) {
                w = '9';
            } else if (strcmp(str, "copiaB") == 0) {
                w = 'A'; // Para "copiaB"
            } else if (strcmp(str, "AeB") == 0) {
                w = 'B'; // Para "AeB"
            } else if (strcmp(str, "nB") == 0) {
                w = 'C'; // Para "nB"
            } else if (strcmp(str, "nAeBn") == 0) {
                w = 'D'; // Para "nAeBn"
            } else if (strcmp(str, "AoB") == 0) {
                w = 'E'; // Para "AoB"
            } else if (strcmp(str, "nAeB") == 0) {
                w = 'F'; // Para "nAeB"
            }

            fprintf(resultado, "%c%c%c\n", x,y,w); // Imprime a linha lida
        }

        
    }

    fclose(file); // Fecha o arquivo
    return 0;
}


