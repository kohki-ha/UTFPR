#include <stdio.h>
#include <stdlib.h>

void soma_quadrados(int n1, int n2)
{
    int soma = 0;

    for (size_t i = n1; i <= n2; i++)
    {
        soma = soma + (i * i);
    }

    printf("%d", soma);
}

int main(int argc, char const *argv[])
{
    soma_quadrados(3, 5);

    return 0;
}
