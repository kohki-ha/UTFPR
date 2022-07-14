#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char pais[20];
    char cidade[20];
    int servidores_up;
    int servidores_down;
    int total_up;
    int total_down;
} Not;

Not* receber_dados(Not * not, int *tamanho)
{
    int tam_acrescentado = 0;
    int op;
    int aux = 0;
    

    while (1)
    {
        // sai do loop infinito ao sair do "for"
        if (aux == 1)
        {
            break;
        }
        for (size_t i = tam_acrescentado; i < tam_acrescentado + 5; i++)
        {
            printf("\nPais: ", tam_acrescentado + 5, i);
            setbuf(stdin, NULL);
            fgets(not [i].pais, 20, stdin);
            not [i].pais[strcspn(not [i].pais, "\n")] = '\0';

            // sair do "for" e salvar o tamanho do vetor da estrutura
            if (strcmp(not [i].pais, "sair") == 0)
            {
                aux = 1;
                (*tamanho) = i;
                break;
            }

            printf("Cidade: ");
            setbuf(stdin, NULL);
            fgets(not [i].cidade, 20, stdin);
            not [i].cidade[strcspn(not [i].cidade, "\n")] = '\0';

            printf("Servidores up: ");
            scanf("%d", &not [i].servidores_up);

            printf("Servidores down: ");
            scanf("%d", &not [i].servidores_down);

            // amenta o tamanho do vetor qnd necessário
            if (i == (tam_acrescentado + 4))
            {
                not = realloc(not, (tam_acrescentado + 5) * sizeof(Not));
                tam_acrescentado = tam_acrescentado + 5;
                break;
            }
        }
    }

    return not;
}

void escrever_binario(Not* not, int *tamanho)
{
    FILE *arq;

    arq = fopen("notifications.dat","wb");
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...\n");
        exit(1);
    }

    //escreve os dados em um arquivo binario
    fwrite(not,sizeof(Not),(*tamanho),arq);

    //fecha o arquivo de escrita
    fclose(arq);

    //libera memoria do vetor
    free(not);
}

void ler_binario(Not* not, int *tamanho)
{
    FILE *arq;

    arq = fopen("notifications.dat","rb");
    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...\n");
        exit(1);
    }

    //aloca o tamanho necessario para receber os dados do arquivo
    //not = realloc(not, (*tamanho) * sizeof(Not));
    not = malloc((*tamanho) * sizeof(Not));

    //le o arquivo e salva os dados no vetor
    fread(not, sizeof(Not), (*tamanho), arq);

    //exibe na tela os dados que foram lidos
    for (size_t i = 0; i < (*tamanho); i++)
    {
        printf("\n\nPais: %-20s | ", not[i].pais);
        printf("Cidade: %-20s | ", not[i].cidade);
        printf("Servidores up: %-3d | ", not[i].servidores_up);
        printf("Servidores down: %-3d\n", not[i].servidores_down);
    }
}

void calcular_servidores(Not* not, int *tamanho)
{
    FILE *arq_report;

    for (size_t i = 0; i < (*tamanho); i++)
    {
        not[i].total_up = 0;
        not[i].total_down = 0;
    }

    //calcular total de servidores up e down
    for (size_t i = 0; i < (*tamanho); i++)
    {
        not[i].total_up = not[i].total_up + not[i].servidores_up;
        not[i].total_down = not[i].total_down + not[i].servidores_down;
    }

    //exibe na tela os dados na tela
    printf("\nPAIS   | UP| DOWN| RATE|");
    for (size_t i = 0; i < (*tamanho); i++)
    {
        printf("\n%s | ", not[i].pais);
        printf("%d | ", not[i].servidores_up);
        printf("%d| ", not[i].servidores_down);
        printf("%.1f%%", (float) not[i].servidores_down / (not[i].total_up + not[i].total_down) * 100);
    }

    //abre o arquivo para escreve o report
    arq_report = fopen("report.txt", "w");

    fprintf(arq_report, "\nPAIS   | UP| DOWN| RATE|");
    for (size_t i = 0; i < (*tamanho); i++)
    {
        fprintf(arq_report, "\n%s | ", not[i].pais);
        fprintf(arq_report, "%d | ", not[i].servidores_up);
        fprintf(arq_report, "%d| ", not[i].servidores_down);
        fprintf(arq_report, "%.1f%%", (float) not[i].servidores_down / (not[i].total_up + not[i].total_down) * 100);
    }
}

int main(int argc, char const *argv[])
{
    Not * not;
    int tamanho;

    not = malloc(5 * sizeof(Not));

    not = receber_dados(not, &tamanho);

    escrever_binario(not, &tamanho);

    //not = malloc(5 * sizeof(Not));

    ler_binario(not, &tamanho);

    calcular_servidores(not, &tamanho);

    return 0;
}
