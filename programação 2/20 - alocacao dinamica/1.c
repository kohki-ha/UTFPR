#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int tamanho;
    int* vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int*) malloc(tamanho * sizeof(vetor));

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
