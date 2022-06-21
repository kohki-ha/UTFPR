#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

void login()
{
    FILE *arq;
    char usuario[31], *senha, buffer[31];
    arq = fopen("senha.txt", "r");
    int i;

    senha = (char*) malloc(31 * sizeof(char));

    if (arq == NULL)
    {
        arq = fopen("senha.txt", "w");
        if (arq == NULL)
        {
            printf("\n\tErro ao abrir o arquivo...");
        }
        else
        {
            printf("\n\tCADASTRAR USUARIO\n\n");
            printf("\tNome de usuario:\n\t");
            setbuf(stdin, NULL);
            fgets(usuario, 31, stdin);
            usuario[strcspn(usuario, "\n")] = '\0';
            fputs(usuario, arq);
            fputc('\n', arq);

            printf("\n\tSenha:\n\t");
            setbuf(stdin, NULL);
            fgets(senha, 31, stdin);
            senha[strcspn(senha, "\n")] = '\0';

            cifra_cesar(senha);
            fputs(senha, arq);
        }
    }
    else
    {
        fgets(usuario, 31, arq);
        usuario[strcspn(usuario, "\n")] = '\0';
        fgets(senha, 31, arq);
        descriptografar(senha);
        printf("\n\tUsuario: %s / %s", usuario, senha);

        while (1)
        {
            printf("\n\tSenha: ");
            setbuf(stdin, NULL);
            fgets(buffer, 31, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strcmp(buffer, senha) == 0)
            {
                printf("\n\tSenha correta!\n\n");
                break;
            }
        }
    }

    fclose(arq);
}

void cifra_cesar(char* key)
{
    while (*key != '\0')
    {
        *key = (*key) + 2;
        key++;
    }
}

void descriptografar(char* key)
{
    while (*key != '\0')
    {
        *key = (*key) - 2;
        key++;
    }
}