#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome_banda[30], tipo_musica[15];
    int numero_integrantes, posicao_no_ranking;
} Banda;

/**
 * @brief preenche as informacoes das bandas
 * 
 * @param banda estrutura que tera seus membros preenchidos
 */
void preencherBandas(Banda* banda);

/**
 * @brief  mostra a informação da banda
 * 
 * @param banda estrutura que tera suas informações exibidas
 */
void mostrarBandas(Banda* banda);

/**
 * @brief pede um número de um a cinco
 * 
 * @return int - valor escolhido pelo usuário
 */
int escolherNumero();

/**
 * @brief pede ao usuário um tipo de música e mostra a bandas desse tipo
 * 
 * @param banda estrutura que sera verificada
 * @param i contador da estrutura for da main
 * @param k auxiliar que incrementa se a banda não pertence ao tipo escolhido
 * @param j auxiliar que incrementa se a banda pertence ao tipo escolhido
 */
void escolherTipoMusica(Banda* banda, int* i, int* k, int* j);

/**
 * @brief 
 * 
 * @param banda estrutura que sera verificada
 * @param i contador da estrutura for da main
 * @param j auxiliar que incrementa se a banda pertence aos favoritos
 */
void procurarNome(Banda* banda, int* i, int* j);


int main(int argc, char const *argv[])
{
    int numero, op, k = 0, j = 0;
    Banda bandas[5];

    do
    {
        printf("\n\n\n\tMenu:");
        printf("\n1. Preencher estruturas das bandas");
        printf("\n2. Escolher um numero de 1 a 5");
        printf("\n3. Escolher um tipo de musica");
        printf("\n4. Escrever o nome de uma banda");
        printf("\n0. SAIR...");
        printf("\nEscolha uma opcao: ");
        setbuf(stdin, NULL);
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            for (size_t i = 0; i < 5; i++)
                preencherBandas(&bandas[i]);
            for (size_t i = 0; i < 5; i++)
                mostrarBandas(&bandas[i]);
            break;

        case 2:
            numero = escolherNumero();
            for (size_t i = 0; i < 5; i++)
                if (numero == bandas[i].posicao_no_ranking)
                    mostrarBandas(&bandas[i]);
            break;

        case 3:
            for (size_t i = 0; i < 5; i++)
                escolherTipoMusica(&bandas[i], &i, &k, &j);
            if(k != 0 && j == 0)
                printf("\nNao ha nenhuma musica deste tipo...\n");
            break;

        case 4:
            for (size_t i = 0; i < 5; i++)
            {
                //k = i;
                procurarNome(&bandas[i], &i, &j);
            }
            break;
        }

        if(op != 0)
            printf("\nOpcao invalida!");
    } while (op != 0);

    return 0;
}

void preencherBandas(Banda* banda)
{
    printf("\nDigite o nome da banda: ");
    setbuf(stdin, NULL);
    fgets(banda->nome_banda, 30, stdin);
    banda->nome_banda[strcspn(banda->nome_banda, "\n")] = '\0';

    printf("Digite o tipo de musica: ");
    setbuf(stdin, NULL);
    fgets(banda->tipo_musica, 15, stdin);
    banda->tipo_musica[strcspn(banda->tipo_musica, "\n")] = '\0';

    printf("Digite o nuero de integrantes: ");
    scanf("%d", &banda->numero_integrantes);
    setbuf(stdin, NULL);

    printf("Digite a posicao no ranking: ");
    scanf("%d", &banda->posicao_no_ranking);
    setbuf(stdin, NULL);
}

void mostrarBandas(Banda* banda)
{
    printf("\nBanda: %s\n", banda->nome_banda);
    printf("Tipo de musica: %s\n", banda->tipo_musica);
    printf("Numero de integrantes: %d\n", banda->numero_integrantes);
    printf("Posicao no ranking: %d\n", banda->posicao_no_ranking);
}

int escolherNumero()
{
    int numero;

    printf("\nEscolha um numero de 1 a 5: ");
    scanf("%d", &numero);

    return numero;
}

void escolherTipoMusica(Banda* banda, int* i, int* k, int* j)
{
    char tipo_musica[15];

    if(*i == 0)
    {
        printf("\nEscolha um tipo de musica: ");
        setbuf(stdin, NULL);
        fgets(tipo_musica, 15, stdin);
        tipo_musica[strcspn(tipo_musica, "\n")] = '\0';

        (*j) = 0;
    }

    if(strcmp(tipo_musica, banda->tipo_musica) == 0)
    {
        mostrarBandas(&(*banda));
        (*j)++;
    }
    else
        (*k)++;
}

void procurarNome(Banda* banda, int* i, int* j)
{
    char nome_banda[30];

    if(*i == 0)
    { 
        printf("\nDigite o nome de uma banda: ");
        setbuf(stdin, NULL);
        fgets(nome_banda, 15, stdin);
        nome_banda[strcspn(nome_banda, "\n")] = '\0';
        
        (*j) = 0;
    }

    if(strcmp(nome_banda, banda->nome_banda) == 0)
    {
        printf("\nA banda pertence aos favoritos.\n");
        (*j)++;
    }
    else if(*i == 4 && *j == 0)
        printf("\nA banda nao pertence aos favoritos...\n");
}