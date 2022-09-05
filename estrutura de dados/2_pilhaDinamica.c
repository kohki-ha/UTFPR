#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct noPilha
{
    int key;
    /* dados */
    struct noPilha* next;
} NoPilha;

typedef struct
{
    NoPilha* topo;
    int qtde;
} PilhaDinamica;

void inicializaPilha(PilhaDinamica *pilha)
{
    pilha->topo = NULL;
    pilha->qtde = 0;
}

int tamanhoPilha(PilhaDinamica pilha)
{
    return pilha.qtde;
}

bool estaVazia(PilhaDinamica pilha)
{
    return (pilha.qtde == 0);
}

// inserir
void push(PilhaDinamica* pilha, int key)
{
    NoPilha *aux = NULL;

    aux = (NoPilha*) malloc(sizeof(NoPilha));

    aux->key = key;

    aux->next = pilha->topo;

    pilha->topo = aux;

    pilha->qtde++;
}

// remover
void pop(PilhaDinamica* pilha)
{
    NoPilha *aux = NULL;

    aux = (NoPilha*) malloc(sizeof(NoPilha));

    aux = pilha->topo;

    pilha->topo = pilha->topo->next;

    free(aux);

    pilha->qtde--;
}

// remover tudo
void popAll(PilhaDinamica* pilha)
{
    while(pilha->qtde != 0)
        pop(pilha);
    
}

void testar(PilhaDinamica pilha)
{
    printf("\n--------------------\n");
    printf("Tamanho da pilha: %d\n", tamanhoPilha(pilha));

    if (estaVazia(pilha) == 1)
        printf("Pilha esta vazia\n");
    else
    {
        printf("Topo: %d\n", pilha.topo->key);
        printf("Pilha nao esta vazia\n");
    }
    printf("--------------------\n");
}

int main(int argc, char const *argv[])
{
    PilhaDinamica pilha;

    inicializaPilha(&pilha);
    testar(pilha);

    push(&pilha, 5);
    testar(pilha);

    push(&pilha, 2);
    testar(pilha);

    push(&pilha, 7);
    testar(pilha);

    pop(&pilha);
    testar(pilha);

    popAll(&pilha);
    testar(pilha);

    return 0;
}
