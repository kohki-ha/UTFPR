#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Converte um decimal para binario
 * 
 * @param n Numero a ser convertido
 */
void converter_binario(int n);

int main(int argc, char const *argv[])
{
    int numero;

    printf("Digite um decimal para converter para binario: ");
    scanf("%d", &numero);

    converter_binario(numero);

    return 0;
}

void converter_binario(int n)
{
    if(n == 0)
        printf("%d", n);
    else
        converter_binario(n / 2);
        printf("%d", n % 2);
    
    return;
}