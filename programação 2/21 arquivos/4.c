#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE* arq;
    int cont = 0;
    char nome_arquivo[20], linha[400], c;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    arq = fopen(nome_arquivo, "r");

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(1);
    }

    while((c =fgetc(arq)) != EOF)
    {
        if(c == ' ' || c == '\n')
            cont++;
    }

    printf("%d palavras\n", cont);

    fclose(arq);

    return 0;
}