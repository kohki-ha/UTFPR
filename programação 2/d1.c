#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int operacao;
    float matriz[3][3], soma = 0;

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }

    scanf("%i", &operacao);

    if(operacao == 1)
    {
        for (size_t i = 0; i < 3; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                soma = soma + matriz[i][j];
            }
        }
        
        printf("%.1f\n", soma);
    }
    
    if(operacao == 2)
    {
        for (size_t i = 0; i < 3; i++)
        {
            soma = soma + matriz[i][3 - 1 - i];
        }

        printf("%.1f\n", soma);
    }

    return 0;
}
