#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char op;
    char palavra[30];
    char tmp[30];
    char tmp2;
    int tamanho;
    int vogal = 0, consoante = 0;

    printf("Digite uma palavra: ");
    fgets(palavra, 30, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    printf("Escolha uma opcao:\n");
    printf("1 - Inverso\n");
    printf("2 - Palindromo\n");
    printf("3 - Maiusculo\n");
    printf("4 - Vogal-consoante\n> ");
    setbuf(stdin, NULL);
    scanf("%c", &op);

    strcpy(tmp, palavra);
    tamanho = strlen(palavra);

    for (size_t i = 0; i < tamanho / 2; i++)
    {
        tmp2 = tmp[i];
        tmp[i] = tmp[tamanho - i - 1];
        tmp[tamanho - i - 1] = tmp2;
    }

    if (op == '1')
    {
        printf("\n%s\n", tmp);
    }

    if (op == '2')
    {
        if (strcmp(palavra, tmp) == 0)
            printf("\nA palavra eh uma palindromo\n");
        else
            printf("\nA palavra NAO eh uma palindromo\n");
    }

    if (op == '3')
    {
        for (size_t i = 0; palavra[i] != '\0'; i++)
            palavra[i] = toupper(palavra[i]);

        printf("\n%s\n", palavra);
    }

    if (op == '4')
    {
        for (size_t i = 0; palavra[i] != '\0'; i++)
        {
            if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
                vogal++;
            else
                consoante++;
                
        }

        printf("\nVogais: %d\nConsoantes: %d\n", vogal, consoante);
    }

    return 0;
}
