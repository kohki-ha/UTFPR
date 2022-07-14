#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int vetor[5];

    for (size_t i = 0; i < 5; i++)
    {
        printf("Digite um valor: ");
        scanf("%d", (vetor + i));
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("\n%d", *(vetor + i) * 2);
    }

    printf("\n");

    for (size_t i = 0; i < 5; i++)
    {
        printf("\n%p", (vetor + i));
    }
    
    return 0;
}
