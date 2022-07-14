#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Multiplica dois numeros
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int multiplicar(int x, int y);

int main(int argc, char const *argv[])
{
    int numero1, numero2, multiplicaco;

    printf("Digite um numero: ");
    scanf("%d", &numero1);

    printf("Digite outro numero: ");
    scanf("%d", &numero2);

    multiplicaco = multiplicar(numero1, numero2);

    printf("A multiplicacao eh: %d\n", multiplicaco);

    return 0;
}

int multiplicar(int x, int y)
{
    if(y == 0)
        return 0;
    else
        return x + (multiplicar(x, y - 1));
}