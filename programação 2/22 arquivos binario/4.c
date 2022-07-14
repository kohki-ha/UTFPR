#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[30];
    char esporte[30];
    int idade;
    float altura;
} Atleta;

int main(int argc, char const *argv[])
{
    Atleta atletas[5];
    FILE *arq;
    int maior_altura = 0, maior_idade = 0, indice_maior_altura, indice_maior_idade;

    //abir arquivo
    arq = fopen("atletas.dat", "rb");

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(1);
    }

    //ler arquivo
    fread(atletas, sizeof(Atleta), 5, arq);

    //verificar maior altura
    for (size_t i = 0; i < 5; i++)
    {
        if(atletas[i].altura > maior_altura)
        {
            maior_altura = atletas[i].altura;
            indice_maior_altura = i;
        }
    }

    printf("O atleta com maior altura eh: %s\n", atletas[indice_maior_altura].nome);

    //verificar maior idade
    for (size_t i = 0; i < 5; i++)
    {
        if(atletas[i].idade > maior_idade)
        {
            maior_idade = atletas[i].idade;
            indice_maior_idade = i;
        }
    }

    printf("O atleta com maior idade eh: %s\n", atletas[indice_maior_idade].nome);
    
    //fechar arquivo
    fclose(arq);

    return 0;
}
