#include <stdio.h>
#include <stdlib.h>

int calcularFatorial(int n){
    int fatorial = 1;

    if(n == 1)
        return n;
    else{
        for (size_t i = 2; i <= n; i++)
        {
            fatorial = i * fatorial;
        }
        return fatorial;
    }
}

int main(int argc, char const *argv[])
{
    int valor;

    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);

    printf("O fatorial desse numero eh: %d", calcularFatorial(valor));

    return 0;
}
