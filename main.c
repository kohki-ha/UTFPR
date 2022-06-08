#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#define MAX 31

typedef struct
{
    int id;
    int nivel_classe;
    float bonus_status;
    char nome_classe[MAX];
    char arma[MAX];
    char capacete[MAX];
    char manto[MAX];
    char peitoral[MAX];
    char calca[MAX]; //calça
    char bota[MAX];
} Classe;

typedef struct
{
    int id;
    int nivel_personagem;
    int chance_critico;
    int reputacao;
    int penetracao_armadura;
    float velocidade;
    float dano_fisico;
    float dano_magico;
    float armadura_fisica;
    float armadura_magica;
    Classe classe;
} Status;

typedef struct
{
    int id;
    int idade;
    int genero;
    float altura;
    char nick_name[MAX];
    char historia_personagem[MAX];
    char raca[MAX]; //raça
    Status status;
} Personagem;

int main(int argc, char const *argv[])
{
    Personagem *personagens = malloc(10 * sizeof(Personagem));

    menu(personagens);


    return 0;
}
