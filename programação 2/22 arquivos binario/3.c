#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    char esporte[30];
    int idade;
    float altura;
} Atleta;

void cadastrarAtleta(Atleta *atl)
{
    printf("\nNome: ");
    setbuf(stdin, NULL);
    fgets(atl->nome, 30, stdin);
    atl->nome[strcspn(atl->nome, "\n")] = '\0';

    printf("Esporte: ");
    setbuf(stdin, NULL);
    fgets(atl->esporte, 30, stdin);
    atl->esporte[strcspn(atl->esporte, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &atl->idade);

    printf("Altura: ");
    scanf("%f", &atl->altura);
}

int main(int argc, char const *argv[])
{
    Atleta atletas[5];
    char nome_arq[15];
    FILE *arq;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 15, stdin);
    nome_arq[strcspn(nome_arq, "\n")] = '\0';

    arq = fopen(nome_arq, "wb");

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(1);
    }

    for (size_t i = 0; i < 5; i++)
    {
        cadastrarAtleta(&atletas[i]);
    }

    fwrite(atletas, sizeof(Atleta), 5, arq);

    fclose(arq);

    return 0;
}
