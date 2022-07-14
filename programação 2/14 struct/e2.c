#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int hora;
    int minuto;
    int segundo;
} Horario;

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    char local[30];
    Horario hor;
    Data dat;
    char descricao[300];
} Compromisso;

int main(int argc, char const *argv[])
{
    Compromisso evento;

    printf("Digite o local do compromisso: ");
    fgets(evento.local, 30, stdin);
    evento.local[strcspn(evento.local, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("Digite o horario do evento (h:min:s): ");
    scanf("%d:%d:%d", &evento.hor.hora, &evento.hor.minuto, &evento.hor.segundo);
    setbuf(stdin, NULL);

    printf("Digite a data do evento (dd/mm/aa): ");
    scanf("%d/%d/%d", &evento.dat.dia, &evento.dat.mes, &evento.dat.ano);
    setbuf(stdin, NULL);

    printf("Digite a descricao do evento: ");
    fgets(evento.descricao, 300, stdin);
    evento.descricao[strcspn(evento.descricao, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("\nLocal do compromisso: %s\n", evento.local);

    printf("Horario do evento: %d:%d:%d\n", evento.hor.hora, evento.hor.minuto, evento.hor.segundo);

    printf("Dia do evento: %d/%d/%d\n", evento.dat.dia, evento.dat.mes, evento.dat.ano);

    printf("Descricao do evento: %s\n", evento.descricao);


    return 0;
}
