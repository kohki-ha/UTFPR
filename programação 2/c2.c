#include <stdio.h>
#include <stdlib.h>

void verificar_matriz(int matriz[5][5])
{
    int positivo = 0;
    int negativo = 0;

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if(matriz[i][j] < 0)
                negativo++;
            else
                positivo++;
        }
    }
    
    if(positivo == 25)
        printf("\nPositiva\n");
    else if(negativo == 25)
        printf("\nNegativa\n");
    else
        printf("\nMista\n");
}

int main(int argc, char const *argv[])
{
    int matriz[5][5];

    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            printf("matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
        
    }
    
    verificar_matriz(matriz);

    return 0;
}
