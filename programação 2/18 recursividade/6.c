#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calcula o somatório de 0 até a
 * 
 * @param a 
 * @return int 
 */
int funcaox(int a);

int main(int argc, char const *argv[])
{
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("\n%d\n", funcaox(numero));
    return 0;
}

int funcaox(int a)
{
    int somatorio = 0;

    for (size_t i = 0; i <= a; i++)
        somatorio = somatorio + i;

    return somatorio;
}