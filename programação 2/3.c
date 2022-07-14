#include <stdio.h>
#include <stdlib.h>

void dobraVetor(int* vetor)
{
    for (size_t i = 0; i < 12; i++)
    {
        vetor[i] = vetor[i] * 2;
    }
    
}

int main(int argc, char const *argv[])
{
    int vetor[12];

    for (size_t i = 0; i < 12; i++)
    {
        printf("Vetor [%i]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    dobraVetor(vetor);

    for (size_t i = 0; i < 12; i++)
    {
        printf("\nVetor [%i] = %d", i, vetor[i]);
    }
    
    return 0;
}
