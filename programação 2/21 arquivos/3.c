#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    FILE *entrada, *saida;
    char nome_entrada[20], nome_saida[20], c;

    printf("Digite o nome do arquivo de entrada: ");
    fgets(nome_entrada, 20, stdin);
    nome_entrada[strcspn(nome_entrada, "\n")] = '\0';

    printf("Digite o nome do arquivo de saida: ");
    fgets(nome_saida, 20, stdin);
    nome_saida[strcspn(nome_saida, "\n")] = '\0';

    entrada = fopen(nome_entrada, "r");
    saida = fopen(nome_saida, "w");

    if(entrada == NULL || saida == NULL)
    {
        printf("Erro ao abrir os arquivos...");
        exit(1);
    }

    while((c = fgetc(entrada)) != EOF)
    {
        c = toupper(c);
        fputc(c, saida);
    }

    fclose(entrada);
    fclose(saida);

    
    return 0;
}
