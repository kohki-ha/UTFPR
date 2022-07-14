#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int vetor[5], operacao, soma = 0, maior = 0;

    for (size_t i = 0; i < 5; i++)
    {
        scanf("%i", &vetor[i]);
    }

    scanf("%i", &operacao);
    
    if(operacao == 1)
    {
        for (size_t i = 0; i < 5; i++)
        {
            soma = soma + vetor[i];
        }
        
        printf("%i\n", soma);
    }

    if(operacao == 2)
    {
        printf("%i %i %i %i %i\n", vetor[4], vetor[3], vetor[2], vetor[1], vetor[0]);
    }

    if(operacao == 3)
    {
        for (size_t i = 0; i < 5; i++)
        {
            if(vetor[i] > maior)
                maior = vetor[i];
        }
        
        printf("%i", maior);
    }

    return 0;
}
