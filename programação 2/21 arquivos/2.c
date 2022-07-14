#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char nomeArq[2][20];
    char str1[300], str2[300];
    FILE* arq1;
    FILE* arq2;
    FILE* saida;
    
    for (size_t i = 0; i < 2; i++)
    {
        printf("Digite o nome do arquivo %li: ", i +1);
        fgets(nomeArq[i], 20, stdin);
        nomeArq[i][strcspn(nomeArq[i], "\n")] = '\0';
    }

    arq1 = fopen(nomeArq[0], "r");
    arq2 = fopen(nomeArq[1], "r");
    saida = fopen("saida.txt", "w");

    if (arq1 == NULL || arq2 == NULL)
    {
        printf("Erro ao abrir arquivos...");
        exit(1);
    }

    while (fgets(str1, 200, arq1) != 0)
    {
        fputs(str1, saida);
    }

    while (fgets(str2, 200, arq2) != 0)
    {
        fputs(str2, saida);
    }

    fclose(arq1);
    fclose(arq2);
    fclose(saida);
    
    return 0;
}
