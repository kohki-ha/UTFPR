#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calcula x elevado a y
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int potencia(int x, int y);

int main(int argc, char const *argv[])
{
    int numero1, numero2, potenciacao;

    printf("Digite um numero: ");
    scanf("%d", &numero1);

    printf("Digite outro numero: ");
    scanf("%d", &numero2);

    potenciacao = potencia(numero1, numero2);

    printf("A potenciacao eh: %d\n", potenciacao);

    return 0;
}

int potencia(int x, int y)
{
    if(y == 0)
        return 1;
    else
        return x * potencia(x, y - 1);
}