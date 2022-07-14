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
    FILE *arq;

    for (size_t i = 0; i < 5; i++)
    {
        printf("\nNome: ");
        setbuf(stdin, NULL);
        fgets(jogadores[i].nome, 30, stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = '\0';
    
        printf("Pontos: ");
        scanf("%d", &jogadores[i].pontos);
    }

    arq = fopen("rank.txt", "w");

    for (size_t i = 0; i < 5; i++)
    {
        fprintf(arq, "Nome: %-30s ", jogadores[i].nome);
        fprintf(arq, "Pontos: %3d\n", jogadores[i].pontos);
    }
    
    fclose(arq);

    return 0;
}
