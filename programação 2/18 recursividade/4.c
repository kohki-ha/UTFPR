#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calcula o termo escolhido da sequencia de Fibonacci
 * 
 * @param n Termo escolhido pelo usuario
 * @return int - Valor contido no escolhido
 */
int fibonacci(int n);

int main(int argc, char const *argv[])
{
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("O termo %d da sequencia eh: %d", n, fibonacci(n));

    return 0;
}

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}