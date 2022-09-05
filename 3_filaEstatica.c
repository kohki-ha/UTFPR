#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXTAM 5

typedef struct
{
    int key;
} Object;

typedef struct
{
    Object obj[MAXTAM];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *fila)
{
    fila->inicio = -1;
    fila->fim = -1;
    fila->tamanho = 0;
}

bool estaCheia(Fila fila)
{
    if (fila.tamanho == MAXTAM)
        return true;

    return false;
}

bool estaVazia(Fila fila)
{
    if (fila.tamanho == 0)
        return true;

    return false;
}

int incrementaIndice(Fila fila)
{
    return (fila.fim + 1) % MAXTAM; // if(++fila->fim == N) fila.fim = 0
}

void enfileirarFila(Fila *fila, Object obj)
{
    if(estaCheia(*fila) == 1)
        printf("\n\nFila cheia!!\n\n");

    if (estaVazia(*fila) == 1)
    {
        fila->inicio = 0;
        fila->obj[fila->inicio] = obj;
    }

    if (estaCheia(*fila) == 0)
    {
        fila->fim = incrementaIndice(*fila);
        fila->obj[fila->fim] = obj;
        fila->tamanho++;
    }
}

void primeiro(Fila fila)
{
    printf("\nKey: %d\n", fila.obj[fila.inicio].key);
}

void ultimo(Fila fila)
{
    printf("\nKey: %d\n", fila.obj[fila.fim].key);
}

void testeEnfileirar(Fila *fila, int key)
{
    Object obj;

    obj.key = key;

    enfileirarFila(fila, obj);
    ultimo(*fila);
}

void imprime(Fila fila)
{
    for (int i = 0; i< fila.tamanho; i++)
    {
        printf("\nPos[%d] = %d\n", i, fila.obj[(fila.inicio+1) % MAXTAM].key);
    }
}

int main(int argc, char const *argv[])
{
    Fila fila;
    Object obj;

    obj.key = 111;

    inicializarFila(&fila);

    enfileirarFila(&fila, obj);
    primeiro(fila);

    testeEnfileirar(&fila, 222);

    testeEnfileirar(&fila, 333);

    testeEnfileirar(&fila, 444);

    testeEnfileirar(&fila, 555);

    imprime(fila);

    return 0;
}
