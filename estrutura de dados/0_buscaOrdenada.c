#include <stdio.h>
#include <stdlib.h>

int buscaBin(int elem, int vet[], int tam)
{
    int inicio = 0, fim = tam - 1, meio;

    while (inicio <= fim) // voltar quando terminar
    {
        meio = (int)(inicio + fim) / 2;

        if (vet[meio] == elem)
            return meio;
        if (vet[meio] < elem)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

int buscaBinRec(int elem, int vet[], int inicio, int fim)
{
    int meio = (int)(inicio + fim) / 2;

    if (inicio > fim)
        return -1;
    if (vet[meio] == elem)
        return meio;
    if (vet[meio] < elem)
        return (buscaBinRec(elem, vet, meio + 1, fim));
    else
        return buscaBinRec(elem, vet, inicio, meio - 1);
}

int main(int argc, char const *argv[])
{
    int vet[] = {3, 8, 13, 18, 20, 23, 21};
    int tam = 7;
    int elem = 8;
    int pos;

    if ((pos = buscaBinRec(elem, vet, 0, tam - 1)) == -1)
        printf("o elemento nao esta no vetor...\n");
    else
        printf("o elemento %d esta na posicao %d\n", elem, pos);

    return 0;
}
