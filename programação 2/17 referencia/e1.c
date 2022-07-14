#include <stdio.h>
#include <stdlib.h>

void converterHora(int total_segundos, int* hora, int* min, int* seg)
{
    (*hora) = total_segundos / 3600;
    (*min) = (total_segundos % 3600) / 60;
    (*seg) = (total_segundos % 3600) % 60;
}

int main(int argc, char const *argv[])
{
    int quantidade_segundos, hora, minutos, segundos;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &quantidade_segundos);

    converterHora(quantidade_segundos, &hora, &minutos, &segundos);

    printf("\n%02d:%02d:%02d\n", hora, minutos, segundos);

    return 0;
}
