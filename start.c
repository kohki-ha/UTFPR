#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void iniciar_programa(Personagem *personagens)
{
    int num_personagens = 0;
    Personagem temp;
    FILE *arq;

    arq = fopen("dados.dat", "r+b");

    if (arq == NULL)
    {
        arq = fopen("dados.dat", "wb");

        if (arq == NULL)
        {
            printf(ANSI_COLOR_RED "\n\tErro ao abrir o arquivo..." ANSI_COLOR_RESET);
            exit(1);
        }
        else
        {
            menu(personagens, &num_personagens);
            fwrite(&num_personagens, sizeof(int), 1, arq);
            fwrite(personagens, sizeof(Personagem), num_personagens, arq);
        }
    }
    else
    {
        fread(&num_personagens, sizeof(int), 1, arq);
        fread(personagens, sizeof(Personagem), num_personagens, arq);

        printf(ANSI_COLOR_YELLOW "\n\tPersonagens carregados: %d\n" ANSI_COLOR_RESET, num_personagens);

        menu(personagens, &num_personagens);
    }

    fclose(arq);
}