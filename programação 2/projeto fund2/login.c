#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

typedef struct
{
    char usuario[31], senha[31];
} Log;

void criptografar(char *key)
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
            printf(ANSI_COLOR_RED "\n\tErro ao abrir o arquivo..." ANSI_COLOR_RESET);
            exit(1);
        }
        else
        {
            printf(ANSI_COLOR_YELLOW "\n\tCADASTRAR USUARIO\n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_CYAN "\n\tNome de usuario: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(logar.usuario, 31, stdin);
            logar.usuario[strcspn(logar.usuario, "\n")] = '\0';

            printf(ANSI_COLOR_CYAN "\n\tSenha: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(logar.senha, 31, stdin);
            logar.senha[strcspn(logar.senha, "\n")] = '\0';

            criptografar(logar.senha);
            fwrite(&logar, sizeof(Log), 1, arq);
        }
    }
    else
    {
        fread(&logar, sizeof(Log), 1, arq);
        descriptografar(logar.senha);
        printf(ANSI_COLOR_YELLOW "\n\tUsuario: %s" ANSI_COLOR_RESET, logar.usuario);

        while (1)
        {
            printf(ANSI_COLOR_YELLOW "\n\tSenha: " ANSI_COLOR_RESET);
            setbuf(stdin, NULL);
            fgets(buffer, 31, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            if (strcmp(buffer, logar.senha) == 0)
            {
                printf(ANSI_COLOR_GREEN "\n\tSenha correta!\n\n" ANSI_COLOR_RESET);
                break;
            }
            else
            {
                printf(ANSI_COLOR_RED "\n\tSenha incorreta...\n\n" ANSI_COLOR_RESET);
            }
        }
    }

    fclose(arq);
}
