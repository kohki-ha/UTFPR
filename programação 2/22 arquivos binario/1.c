#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int numeros[100], ler_arq[100];
    char nome_arq[15];
    FILE *arq;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 15, stdin);
    nome_arq[strcspn(nome_arq, "\n")] = '\0';

    arq = fopen(nome_arq, "r+b");

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...\n");
        exit(1);
    }

    for (size_t i = 0; i < 100; i++)
    {
        numeros[i] = rand() % 100;
    }

    fwrite(numeros, sizeof(int), 100, arq);
    
    fclose(arq);
    
    return 0;
}
