#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int hora, minuto, segundo;
} Horario;

/**
 * @brief converte segundos para horas, minutos e segundos
 * 
 * @param total_segundos segundos a ser convertido
 * @param hor estrutura do horário
 */
void converterHorario(int total_segundos, Horario* hor)
{
    hor->hora = total_segundos / 3600;
    hor->minuto = (total_segundos % 3600) / 60;
    hor->segundo = (total_segundos % 3600) % 60;

    return;
}

int main(int argc, char const *argv[])
{
    Horario horas;
    int quantidade_segundos;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &quantidade_segundos);

    converterHorario(quantidade_segundos, &horas);

    printf("\n%02d:%02d:%02d\n", horas.hora, horas.minuto, horas.segundo);
    return 0;
}
