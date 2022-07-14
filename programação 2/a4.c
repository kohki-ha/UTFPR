#include <stdio.h>
#include <stdlib.h>

float media(int vet[], int tam)
{
    int soma_vetor = 0;
    float calculo_media =0;

    for (size_t i = 0; i < tam; i++)
    {
        soma_vetor =  soma_vetor + vet[i];
    }

    calculo_media = soma_vetor / tam;

    return calculo_media;
}

int main(int argc, char const *argv[])
{
    int x[] = {2, 3, 7};

    printf("%.1f\n", media(x, 3));

    return 0;
}
