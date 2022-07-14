#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificar(char *str1, char *str2, int indice)
{
    int j;
    
    for (size_t i = indice; i < strlen(str1); i++)
    {
        if(str1[i] == str2[j])
            j++;
        else
            j = 0;
        if(j == strlen(str2))
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    FILE* arq;
    int cont = 0, posicao;
    char nome_arquivo[20], palavra[20], *linha;

    printf("Digite o nome do arquivo: ");
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strcspn(nome_arquivo, "\n")] = '\0';

    arq = fopen(nome_arquivo, "r");

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(1);
    }

    printf("Digite uma palavra: ");
    fgets(palavra, 20, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    while(fgets(linha, 200, arq) != 0)
    {
        do
        {
            posicao = verificar(linha, palavra, posicao);
            if(posicao != -1)
                cont++;
        } while (posicao != -1);
    }

    printf("A palavra apareceu %d vezes.\n", cont);

    fclose(arq);

    return 0;
}