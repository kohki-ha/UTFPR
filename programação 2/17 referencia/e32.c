#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome_banda[30], tipo_musica[15];
    int numero_integrantes, posicao_no_ranking;
} Banda;

/**
 * @brief Preenche os membros das bandas
 * 
 * @param bandas Estruturas a serem preenchidas
 */
void preencherBandas(Banda* bandas)
{
    for (size_t i = 0; i < 5; i++)
    {
        //printf("%d", i);
        printf("\n\nDigite o nome da banda: ");
        setbuf(stdin, NULL);
        fgets((bandas + i)->nome_banda, 30, stdin);
        (bandas + i)->nome_banda[strcspn((bandas + i)->nome_banda, "\n")] = '\0';

        setbuf(stdin, NULL);
        printf("Digite o tipo de musica: ");
        fgets((bandas + i)->tipo_musica, 15, stdin);
        setbuf(stdin, NULL);
        (bandas + i)->tipo_musica[strcspn((bandas + i)->tipo_musica, "\n")] = '\0';

        printf("Digite o nuero de integrantes: ");
        scanf("%d", &(bandas + i)->numero_integrantes);
        setbuf(stdin, NULL);

        printf("Digite a posicao no ranking: ");
        scanf("%d", &(bandas + i)->posicao_no_ranking);
        setbuf(stdin, NULL);
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("\n\nBanda: %s", (bandas + i)->nome_banda);
        printf("\nTipo de musica: %s", (bandas + i)->tipo_musica);
        printf("\nNumero de integrantes: %d", (bandas + i)->numero_integrantes);
        printf("\nPosicao no ranking: %d", (bandas + i)->posicao_no_ranking);
    }
}



int main(int argc, char const *argv[])
{
    Banda bandas[5];

    preencherBandas(bandas);

    return 0;
}