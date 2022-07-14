#include <stdio.h>
#include <stdlib.h>

int* definirVetorC(int* a, int* b, int n)
{
    int* c;
    
    c = (int*) malloc(sizeof(int) * n);

    for (size_t i = 0; i < n; i++)
    {
        c[i] = a[i] * b[i];
    }

    return c;
}


int main(int argc, char const *argv[])
{
    int n;
    int* a;
    int* b;
    int* c;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    a = (int*) malloc(n * sizeof(int));
    b = (int*) malloc(n * sizeof(int));

    for (size_t i = 0; i < n; i++)
    {
        printf("\nVetor A [%li]: ", i);
        scanf("%d", (a + i));
    }

    printf("\n");

    for (size_t i = 0; i < n; i++)
    {
        printf("\nVetor B [%li]: ", i);
        scanf("%d", (b + i));
    }

    c = definirVetorC(a, b, n);

    for (size_t i = 0; i < n; i++)
    {
        printf("C [%li]: %d\n", i, *(c + i));
    }

    free(a);
    free(b);
    free(c);

    return 0;
}
