#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIM 40

void verificarStrings(char* str1, char* str2)
{
    int aux = -1;// abacate eh bom     bom

    for (size_t i = 0; i < strlen(str1); i++)
    {
        if(*(str1 + i) == *(str2 + 0) && aux == -1)
        {
            aux = 0;
        }

        if(*(str1 + i) == *(str2 + aux))
        {
            aux++;
        }
    }

    if(aux == strlen(str2))
        printf("A segunda string esta contida na primeira.\n");
    else
        printf("A segunda string NAO esta contida na primeira.\n");
}


int main(int argc, char const *argv[])
{
    char str1[LIM];
    char str2[LIM];

    printf("Digite a string 1: ");
    fgets(str1, LIM, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Digite a string 2: ");
    fgets(str2, LIM, stdin);
    str2[strcspn(str2, "\n")] = '\0';

    verificarStrings(str1, str2);

    return 0;
}