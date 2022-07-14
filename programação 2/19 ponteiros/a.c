#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a, b;
    int* pointer;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    printf("Digite o valor de b: ");
    scanf("%d", &b);

    pointer = &a;

    if(&b > &a)
    {
        pointer = &b;
        printf("\nO maior endereço é do B, que tem valor: ");
    }
    else
        printf("\nO maior endereço é do A, que tem valor: ");
    printf("%d\n", *pointer);

    return 0;
}
