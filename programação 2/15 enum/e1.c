#include <stdio.h>
#include <stdlib.h>

typedef enum {JANEIRO = 1, FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, 
              JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO, DEZEMBRO} Meses;

int main(int argc, char const *argv[])
{
    Meses mes;

    printf("Digite um valor inteiro: ");
    scanf("%i", &mes);

    switch (mes)
    {
    case JANEIRO:
        printf("O mes eh janeiro\n");
        printf("Tem 31 dias\n");
        break;
    
    case FEVEREIRO:
        printf("O mes eh fevereiro\n");
        printf("Tem 28 dias\n");
        break;

    case MARCO:
        printf("O mes eh marco\n");
        printf("Tem 31 dias\n");
        break;
    
    case ABRIL:
        printf("O mes eh abril\n");
        printf("Tem 30 dias\n");
        break;
    
    case MAIO:
        printf("O mes eh maio\n");
        printf("Tem 31 dias\n");
        break;
    
    case JUNHO:
        printf("O mes eh junho\n");
        printf("Tem 30 dias\n");
        break;
    
    case JULHO:
        printf("O mes eh julho\n");
        printf("Tem 31 dias\n");
        break;
    
    case AGOSTO:
        printf("O mes eh agosto\n");
        printf("Tem 30 dias\n");
        break;
    
    case SETEMBRO:
        printf("O mes eh setembro\n");
        printf("Tem 31 dias\n");
        break;
    
    case OUTUBRO:
        printf("O mes eh outubro\n");
        printf("Tem 30 dias\n");
        break;
    
    case NOVEMBRO:
        printf("O mes eh novembro\n");
        printf("Tem 31 dias\n");
        break;
    
    case DEZEMBRO:
        printf("O mes eh dezembro\n");
        printf("Tem 30 dias\n");
        break;
    }

    return 0;
}
