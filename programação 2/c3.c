#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int vetor[10], cont = 0;

    for (size_t i = 0; i < 10; i++)
    {
        printf("Vetor [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = i + 1; j < 10; j++)
        {
            if (vetor[i] == vetor[j])
            {
                cont = 2;
                printf("\n%d - ", vetor[i]);

                for (j = j + 1; j < 10; j++)
                {
                    if (vetor[i] == vetor[j])
                    {
                        cont++;
                    }
                }
                printf("Repetiu %d vezes\n", cont);
            }
        }
    }

    return 0;
}
