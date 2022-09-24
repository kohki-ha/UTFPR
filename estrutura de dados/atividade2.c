/**
 * Nome: Mabylly Neres        RA: 2368013
 * Nome: Thales Hasegawa      RA: 2272075
 *
 * Avaliação Prática 2 - FILAS
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct visitaEstatica
{
    int id;
    char proprietario[30];
    char rua[30];
    int numeroCasa;
} VisitaEstatica;

typedef struct filaEstatica
{
    VisitaEstatica visita[10];
    int quantidadeElemento;
    int inicio;
    int fim;
} FilaEstatica;

typedef struct visitaDinamica
{
    int id;
    char proprietario[30];
    char rua[30];
    int numeroCasa;
    struct visitaDinamica *prox;
} VisitaDinamica;

typedef struct filaDinamica
{
    VisitaDinamica *inicio;
    VisitaDinamica *fim;
    int tamanho;
} FilaDinamica;

void inicializarFilaEstatica(FilaEstatica *estatica)
{
    estatica->fim = estatica->inicio = -1;
    estatica->quantidadeElemento = 0;
}

void inicializarFilaDinamica(FilaDinamica *dinamica)
{
    dinamica->inicio = NULL;
    dinamica->fim = NULL;
    dinamica->tamanho = 0;
}

bool estaVaziaEstatica(FilaEstatica estatica)
{
    return (estatica.quantidadeElemento == 0);
}

bool estaCheiaEstatica(FilaEstatica estatica)
{
    return (estatica.quantidadeElemento == 10);
}

void inserirFilaEstatica(FilaEstatica *estatica, VisitaEstatica tmp)
{
    if (estaVaziaEstatica(*estatica))
    {
        estatica->fim = estatica->inicio = 0;
        estatica->visita[0] = tmp;
        estatica->quantidadeElemento;
    }

    if (estaCheiaEstatica(*estatica))
    {
        printf("\nFila cheia!!!\n");
        return;
    }

    estatica->fim = (estatica->fim + 1) % 10;
    estatica->visita[estatica->fim] = tmp;
    estatica->quantidadeElemento++;
}

bool estaVaziaDinamica(FilaDinamica dinamica)
{
    return (dinamica.tamanho == 0);
}

void inserirFilaDinamica(FilaDinamica *dinamica, VisitaDinamica tmp)
{
    VisitaDinamica *novo;
    novo = (VisitaDinamica *)malloc(sizeof(VisitaDinamica));
    (*novo) = tmp;
    novo->prox = NULL;

    if (estaVaziaDinamica(*dinamica))
    {
        dinamica->inicio = dinamica->fim = novo;
    }
    else
    {
        dinamica->fim->prox = novo;
        dinamica->fim = novo;
    }

    dinamica->tamanho++;
}

void removerFilaEstatica(FilaEstatica *estatica)
{
    if (estaVaziaEstatica(*estatica))
    {
        printf("\nA fila estatica esta vazia!!!\n");
        return;
    }

    estatica->inicio = (estatica->inicio + 1) % 10;
    estatica->quantidadeElemento--;
}

void imprimeFilaDinamica(FilaDinamica dinamica)
{
    int i = 0;

    for (VisitaDinamica *aux = dinamica.inicio; aux != NULL; aux = aux->prox)
    {
        printf("%d: %d %s %s %d\n", ++i, aux->id, aux->proprietario, aux->rua, aux->numeroCasa);
    }
}

bool visitaConcretizada(int i)
{
    char opcao;

    printf("\nDigite: \n1 - se a visita a casa %d foi concretizada\n2 - se a visita nao foi concretizada\n", i + 1);
    setbuf(stdin, NULL);
    scanf("%c", &opcao);

    return (opcao == '1');
}

int main(int argc, char const *argv[])
{
    VisitaEstatica tmp1;
    VisitaDinamica tmp2;
    FilaEstatica estatica;
    FilaDinamica dinamica1;
    FilaDinamica dinamica2;
    FILE *entrada;
    FILE *saida;
    char lixo;
    int cont = 0;

    entrada = fopen(argv[1], "r+");
    saida = fopen(argv[2], "w");

    if (entrada == NULL)
    {
        printf("\nErro ao abrir o arquivo de entrada...\n");
        exit(1);
    }

    if (saida == NULL)
    {
        printf("\nErro ao abrir o arquivo de saida...\n");
        exit(1);
    }

    inicializarFilaEstatica(&estatica);
    inicializarFilaDinamica(&dinamica1);
    inicializarFilaDinamica(&dinamica2);

    for (size_t i = 0; i < 10; i++)
    {
        fscanf(entrada, "{ %d; %[^;]; %[^;]; %d }\n", &tmp1.id, &tmp1.proprietario, &tmp1.rua, &tmp1.numeroCasa);
        inserirFilaEstatica(&estatica, tmp1);
        printf("%d %s %s %d\n", estatica.visita[i].id, estatica.visita[i].proprietario, estatica.visita[i].rua, estatica.visita[i].numeroCasa);
    }

    while (!feof(entrada))
    {
        removerFilaEstatica(&estatica);

        tmp2.id = tmp1.id;
        tmp2.numeroCasa = tmp1.numeroCasa;
        strcpy(tmp2.proprietario, tmp1.proprietario);
        strcpy(tmp2.rua, tmp1.rua);

        if (visitaConcretizada(cont))
        {
            printf("aaaa\n\n\n");
            fprintf(saida, "{ %d; %s; %s; %d; concretizado}\n", tmp1.id, tmp1.proprietario, tmp1.rua, tmp1.numeroCasa);
            printf("aaaa\n\n\n");
            inserirFilaDinamica(&dinamica1, tmp2);
            printf("aaaa\n\n\n");
        }
        else
        {
            fprintf(saida, "{ %d; %s; %s; %d; nao concretizado}\n", tmp1.id, tmp1.proprietario, tmp1.rua, tmp1.numeroCasa);

            fscanf(entrada, "{ %d; %[^;]; %[^;]; %d }\n", &tmp1.id, &tmp1.proprietario, &tmp1.rua, &tmp1.numeroCasa);
            inserirFilaEstatica(&estatica, tmp1);
            inserirFilaDinamica(&dinamica2, tmp2);
        }
        printf("\n%d\n", cont);

        cont++;
    }

    printf("Fila dinamica 1::::::::::::::::::::::::::\n");
    imprimeFilaDinamica(dinamica1);

    printf("\n\nFila dinamica 2::::::::::::::::::::::::::\n");
    imprimeFilaDinamica(dinamica2);

    fclose(entrada);
    fclose(saida);

    return 0;
}
