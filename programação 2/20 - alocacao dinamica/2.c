
#include <stdio.h>
#include <stdlib.h>


int* definirTamanho(int n)
{
    int* vetor;
    if(n > 0)
    {
        vetor = (int*) malloc(sizeof(int) * n);
        return vetor;
    }
    else
        return NULL;
}

int main(int argc, char const *argv[])
{
    int tamanho;
    int* vetor;

    printf("Digite o tamanho: ");
    scanf("%d", &tamanho);

    vetor = definirTamanho(tamanho);

    for (size_t i = 0; i < tamanho; i++)
    {
        printf("\nVetor [%li]: ", i);
        scanf("%d", (vetor + i));
    }

    printf("\n");

    for (size_t i = 0; i < tamanho; i++)
    {
        printf("%d ", *(vetor + i));
    }
    
    printf("\n");

    free(vetor);

    return 0;
}
