#include <stdio.h>
#include <stdlib.h>

int verificarMaior(int n[]){
    int maior = n[0];
    if(n[1] > n[0] && n[1] > n[2])
        maior = n[1];
    else if(n[2] > n[0] && n[2] > n[1])
        maior = n[2];
    return maior;
}

int main(int argc, char const *argv[])
{
    int numeros[3];

    for (size_t i = 0; i < 3; i++)
    {
        printf("\nDigite um numero: ");
        scanf("%d", &numeros[i]);
    }

    printf("\nO maior numero eh: %d", verificarMaior(numeros));

    return 0;
}
