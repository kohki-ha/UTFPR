#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

typedef struct
{
    char usuario[31], senha[31];
} Log;

void login()
{
    FILE *arq;
    Log logar;
    char buffer[31];
    int i;

    arq = fopen("senha.dat", "rb");

    if (arq == NULL)
    {
        arq = fopen("senha.dat", "wb");

        if (arq == NULL)
        {
            printf("\n\tErro ao abrir o arquivo...");
            exit(1);
        }
        else
        {
            printf("\n\tCADASTRAR USUARIO\n");
            printf("\tNome de usuario:\n\t");
            setbuf(stdin, NULL);
            fgets(logar.usuario, 31, stdin);
            logar.usuario[strcspn(logar.usuario, "\n")] = '\0';

            printf("\n\tSenha:\n\t");
            setbuf(stdin, NULL);
            fgets(logar.senha, 31, stdin);
            logar.senha[strcspn(logar.senha, "\n")] = '\0';

            cifra_cesar(logar.senha);
            fwrite(&logar, sizeof(Log), 1, arq);
        }
    }
    else
    {
        fread(&logar, sizeof(Log), 1, arq);
        descriptografar(logar.senha);
        printf("\n\tUsuario: %s / %s", logar.usuario, logar.senha);

        while (1)
        {
            printf("\n\tSenha: ");
            setbuf(stdin, NULL);
            fgets(buffer, 31, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strcmp(buffer, logar.senha) == 0)
            {
                printf("\n\tSenha correta!\n\n");
                break;
            }
        }
    }

    fclose(arq);
}

void cifra_cesar(char *key)
{
    for (size_t i = 0; key[i] != '\0'; i++)
    {
        key[i] = key[i] + 3;
    }
}

void descriptografar(char *key)
{
    for (size_t i = 0; key[i] != '\0'; i++)
    {
        key[i] = key[i] - 3;
    }
}