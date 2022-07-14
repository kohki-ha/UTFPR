#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int pontos;
} Ranking;


int main(int argc, char const *argv[])
{
    Ranking jogadores[5];
    char label[30];
    FILE *arq;

    arq = fopen("rank.txt", "r");

    for (size_t i = 0; i < 5; i++)
    {
        fscanf(arq, "%s %s | ", label, jogadores[i].nome);
        fscanf(arq, "%s %d\n", label, &jogadores[i].pontos);
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("%-30s ", jogadores[i].nome);
        printf("%3d\n", jogadores[i].pontos);
    }
    
    fclose(arq);

    return 0;
}
