/*

Você foi contratado pela Riot Games para elaborar partes do sistema sistema de Ranking do League of Legends. Para isso:

a) Defina um tipo e estrutura para salvar os dados de jogadores para um Ranking.
Cada jogador possui: nome, vitorias, derrotas, tier(nível) e pontos.

Os tiers são: Bronze, Prata, Ouro, Platina, Diamante e Desafiante. Para organizar os níveis utilize uma enumeração.

b) Receba do teclado e armazene os dados de 6 jogadores. Não devem ser permitidos valores negativos, novos valores devem ser solicitados caso necessário.

c) Exiba uma tabela alinhada com o nome e a taxa de vitorias (winrate) de cada jogador
  winrate = vitorias / (vitorias+derrotas) * 100.
  Cada calculo deve ser feito por meio de uma função adicional que recebe o número de vitorias e derrotas via cópia e retorna o winrate.

d) Exiba uma tabela com os líderes (maior número de pontos) de cada um dos níveis. Para isso, faça uma função extra que receba um tier e retorne uma estrutura do tipo Jogador com os dados do líder.

e) Faça a busca de um jogador pelo nome digitado. A busca deve ser feita por uma função adicional que recebe o nome e retorna os dados de vitorias, derrotas, tier e pontos via referência.

f) Utilizando uma função recursiva, calcule a soma de todas as partidas (vitorias e derrotas) de todos os jogadores.

Cada um dos itens de B a E deve ser implementada em uma função diferente.
Não é permitido o uso de variáveis globais.
Nas funções extras, caso necessário, utilize parâmetros adicionais.
1- bronze    2- prata    3- ouro    4- platina    5 - diamante


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum rank {bronze, prata, ouro, platina, diamante};

typedef struct
{
    char nome[10];
    int vitorias;
    int derrotas;
    int tier;
    int pontos;
} Jogador;

void receberJogadores(Jogador* player)
{
    for (size_t i = 0; i < 2; i++)
    {
        printf("\n\n\tDIGITE OS DADOS DO JOGADOR:\n");
        printf("Nome: ");
        setbuf(stdin, NULL);
        fgets((player + i)->nome, 10, stdin);
        (player + i)->nome[strcspn((player + i)->nome, "\n")] = '\0';

        do{
            printf("Quantidade de vitorias: ");
            scanf("%d", &player[i].vitorias);
        }while(player[i].vitorias < 0);
        
        do{
            printf("Quantidade de derrotas: ");
            scanf("%d", &player[i].derrotas);
        }while(player[i].derrotas < 0);
        
        do{
            printf("\n\t0 - Bronze\n\t1 - Prata\n\t2 - Ouro\n\t3 - Platina\n\t4 - Diamante");
            printf("\n\nTier: ");
            scanf("%d", &player[i].tier);
        }while(player[i].tier < 0);

        do{
            printf("Quantidade de pontos: ");
            scanf("%d", &player[i].pontos);
        }while(player[i].pontos < 0);
    }
}

float winRate(int win, int lose)
{
    float win_rate;

    win_rate = (float) win / (win + lose) * 100;

    return win_rate;
}

void tabelaWinRate(Jogador* player)
{
    printf("\n");
    for (size_t i = 0; i < 2; i++)
    {
        printf("| %-10s", player[i].nome);
        printf("| %.2f %% |\n", winRate(player[i].vitorias, player[i].derrotas));
    }
}

void inicializarJogador(Jogador* player)
{
    strcpy(player->nome, "NONE\0");
    player->vitorias = 0;
    player->derrotas = 0;
    player->tier = 0;
    player->pontos = 0;
}

Jogador dadosTier(int tier, Jogador* player)
{
    Jogador jog;
    
    inicializarJogador(&jog);

    for (size_t i = 0; i < 2; i++)
    {
        if(player[i].tier == tier)
        {
            if(player[i].pontos > jog.pontos){
                jog = *(player + i);
            }
        }
    }
    return jog;
}

void tabelaLideres(Jogador* player)
{
    Jogador lideres[5];
    
    lideres[0] = dadosTier(bronze, player);
    lideres[1] = dadosTier(prata, player);
    lideres[2] = dadosTier(ouro, player);
    lideres[3] = dadosTier(platina, player);
    lideres[4] = dadosTier(diamante, player);

    printf("\n");
    for (size_t i = 0; i < 5; i++)
    {
        printf("| %-10s", lideres[i].nome);
        printf("| %-3d |", lideres[i].vitorias);
        printf("| %-3d |", lideres[i].derrotas);
        printf("| %.d |", lideres[i].tier);
        printf("| %-4d |\n", lideres[i].pontos);
    }
}

int dadosJogador(Jogador player)
{
    int dados[4];

    dados[0] = player.vitorias;
    dados[1] = player.derrotas;
    dados[2] = player.tier;
    dados[3] = player.pontos;

    return dados;
}

void buscarJogador(Jogador* player)
{
    char nome[10];

    printf("\nDigite o nome de um jogador: ");
    setbuf(stdin, NULL);
    fgets(nome, 10, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (size_t i = 0; i < 2; i++)
    {
        if(strcmp(nome, (player + i)->nome) == 0)
            {
                printf("\nVitorias: %d", (player + i)->vitorias);
                printf("\nDerrotas: %d", (player + i)->derrotas);
                switch ((player + i)->tier)
                {
                case bronze:
                    printf("\nTier: bronze");
                    break;
                
                case prata:
                    printf("\nTier: prata");
                    break;
                
                case ouro:
                    printf("\nTier: ouro");
                    break;
                
                case platina:
                    printf("\nTier: platina");
                    break;
                
                case diamante:
                    printf("\nTier: diamante");
                    break;
                
                }
                printf("\nPontos: %d\n", (player + i)->pontos);
            }
    }
}

int somarPartidas(int win, int lose)
{
    if (lose == 0)
        return win;
    else
        return 1 + somarPartidas(win, lose - 1);
}

void totalPartidas(Jogador* player)
{
    printf("\nTotal partidas\n");
    for (size_t i = 0; i < 2; i++)
    {
        printf("Jogador %i: %i\n", i, somarPartidas(player[i].vitorias, player[i].derrotas));
    }
    
}

int main(int argc, char const *argv[])
{
    Jogador jogadores[2];
    
    receberJogadores(jogadores);
    tabelaWinRate(jogadores);
    tabelaLideres(jogadores);
    buscarJogador(jogadores);
    totalPartidas(jogadores);

    return 0;
}

