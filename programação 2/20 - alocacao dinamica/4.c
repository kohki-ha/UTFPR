#include <stdio.h>
#include <stdlib.h>

int** definirMatriz(int l, int c)
{  
    int** matriz;

    matriz = (int**) malloc(sizeof(int) * l);

    for (size_t i = 0; i < l; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * c);
    }
    
    for (size_t i = 0; i < l; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            matriz[i][j] = 0;
        }
    }

    return matriz;
}

int main(int argc, char const *argv[])
{
    int l, c;
    int** matriz;

    printf("Digite o valor de L:");
    scanf("%d", &l);

    printf("Digite o valor de C:");
    scanf("%d", &c);

    matriz = definirMatriz(l, c);

    for (size_t i = 0; i < l; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            printf("Matriz [%li][%li] = %d  ", i, j, matriz[i][j]);
        }
        printf("\n");
    }

    free(matriz);
    
    return 0;
}
