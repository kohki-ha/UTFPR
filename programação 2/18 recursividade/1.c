#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calcula o fatorial de um numero
 * 
 * @param n Numero que sera calculado
 * @return int 
 */
int calcularFatorial(int n);


int main(int argc, char const *argv[])
{
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    printf("O fatorial desse numero eh: %d", calcularFatorial(numero));
    return 0;
}


int calcularFatorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n * calcularFatorial(n - 1);
}