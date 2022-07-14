#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[16];
    float potencia;
    float tempo_ativo;
} Eletrodomestico;

int main(int argc, char const *argv[])
{
    int dias;
    float consumo[4];
    float consumo_total;
    float consumo_relativo[4];
    Eletrodomestico eletrodomesticos[4];

    for (size_t i = 0; i < 5; i++)
    {
    printf("\nDigite o nome do eletrodomestico %d: ", i);
    fgets(eletrodomesticos[i].nome, 16, stdin);
    setbuf(stdin, NULL);

    printf("Digite a potencia do eletrodomestico %d (kW): ", i);
    scanf("%f", &eletrodomesticos[i].potencia);
    setbuf(stdin, NULL);

    printf("Digite o tempo ativo por dia do eletrodomestico %d (h): ", i);
    scanf("%f", &eletrodomesticos[i].tempo_ativo);
    setbuf(stdin, NULL);
    }

    printf("\nDigite o numero de dias: ");
    scanf("%i", &dias);

    consumo_total = 0;


    for (size_t i = 0; i < 5; i++)
    {
        consumo[i] = dias * eletrodomesticos[i].potencia * eletrodomesticos[i].tempo_ativo;
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        consumo_total = consumo_total + consumo[i];
    }
    
    printf("\nConsumo total: %f kW\n", consumo_total);

    for (size_t i = 0; i < 5; i++)
    {
    printf("Consumo %i: %f\n", i, consumo[i]);
    }
    
    printf("\n");

    for (size_t i = 0; i < 5; i++)
    {
        consumo_relativo[i] = consumo[i] / consumo_total * 100;
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("Consumo relativo do eletrodomestico %i: %f\n", i, consumo_relativo[i]);
    }
    
    return 0;
}
