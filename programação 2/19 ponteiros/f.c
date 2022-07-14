#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int a, *b, **c, ***d, dobro, triplo, quadruplo;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    b = &a;
    c = &b;
    d = &c;

    dobro = (*b * 2);
    triplo = (**c * 3);
    quadruplo = (***d * 4);

    printf("Dobro: %d", dobro);
    printf("\nTriplo: %d", triplo);
    printf("\nQuadruplo: %d\n", quadruplo);



    return 0;
}
