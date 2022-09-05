#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

typedef struct
{
    int RA;
    char nome[50];
} Aluno;

typedef struct
{
    Aluno aluno[MAX];
    int topo;
} PilhaEstatica;

void inicializarPilha(PilhaEstatica *pilha)
{
    pilha->topo = 0;
}

bool estaCheio(PilhaEstatica *pilha)
{
    if (pilha->topo == MAX)
        return true;

    return false;
}

void empilharPilha(PilhaEstatica *pilha, Aluno aluno)
{
    if (estaCheio(&(*pilha)) == 1)
    {
        printf("\nPilha cheia...\n");
        return;
    }

    pilha->aluno[pilha->topo] = aluno;
    pilha->topo++;
}

void imprimirPilha(PilhaEstatica pilha)
{
    for (size_t i = 0; i < pilha.topo; i++)
        printf("\nPilha[%li] = %d, %s\n", i, pilha.aluno[i].RA, pilha.aluno[i].nome);
}

// void imprimirTopo(PilhaEstatica pilha)
// {
//     printf("\nTopo = %d\n", pilha.aluno[pilha.topo]);
// }

int main(int argc, char const *argv[])
{
    PilhaEstatica pilha;
    Aluno aluno = {123, "Thales"};

    inicializarPilha(&pilha);
    empilharPilha(&pilha, aluno);

    aluno.RA = 321;
    strcpy(aluno.nome, "Johan");
    empilharPilha(&pilha, aluno);

    imprimirPilha(pilha);

    imprimirTopo(pilha);

    printf("\n Topo: %d\n", pilha.topo);

    return 0;
}
