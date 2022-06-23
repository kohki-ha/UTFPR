#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void iniciar_programa(Personagem *personagens)
{
    int numero_linhas = 0;
    Personagem temp;
    FILE *arq;

    arq = fopen("dados.dat", "r+b");

    if (arq == NULL)
    {
        arq = fopen("dados.dat", "wb");

        if (arq == NULL)
        {
            printf("\n\tErro ao abrir o arquivo...");
            exit(1);
        }
        else
            menu(personagens, numero_linhas, arq);
    }
    else
    {
        fwrite(&numero_linhas, sizeof(int), 1, arq);
        fwrite(personagens, sizeof(Personagem), numero_linhas, arq);

        printf("\n\n%d personagens\n\n", numero_linhas);

        menu(personagens, numero_linhas, arq);
    }

    fclose(arq);
}
