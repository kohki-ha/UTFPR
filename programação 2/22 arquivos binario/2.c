#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int numeros[100], soma = 0;
    char nome_arq[15];
    FILE *arq;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 15, stdin);
    nome_arq[strcspn(nome_arq, "\n")] = '\0';

    arq = fopen(nome_arq, "rb");

    fread(numeros, sizeof(int), 100, arq);

    for (size_t i = 0; i < 100; i++)
    {
        soma = soma + numeros[i];
    }
    
    printf("Soma = %d\n", soma);

    fclose(arq);

    return 0;
}
