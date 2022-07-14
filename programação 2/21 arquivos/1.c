#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE* arq;
    char nome_arq[10];
    char c;
    int aux = 0;
    int tamanho;
    int i;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 10, stdin);
    nome_arq[strcspn(nome_arq, "\n")] = '\0';

    arq = fopen(nome_arq, "r");
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(1);
    }

    while ((c = fgetc(arq)) != EOF)
    {
        if(c == '\n')
        {
            aux++;
        }
    }
    
    printf("Esse arquivo tem %d linhas.\n", aux + 1);

    fclose(arq);
    
    return 0;
}