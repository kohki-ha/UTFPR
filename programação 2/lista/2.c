/**
 * @file 1.c
 * @author Thales Kohki Hasegawa (kohkihasegawa151@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
Usando a estrutura “atleta” do exercício anterior,
escreva um programa que leia os dados de cinco atletas
e os exiba por ordem de idade, do mais velho para o mais novo.
Dica: Procure pelo algoritmo BubbleSort no Google
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    char esporte[20];
    int idade;
    float altura;
} Atleta;

void lerAtleta(Atleta* atl)
{
    for (size_t i = 0; i < 5; i++)
    {
        printf("\n\nPreencha as informacoes do atleta %li\n\n", i + 1);
        printf("Nome: ");
        setbuf(stdin, NULL);
        fgets((atl + i)->nome, 30, stdin);

        printf("Esporte: ");
        setbuf(stdin, NULL);
        fgets((atl + i)->esporte, 20, stdin);

        printf("Idade: ");
        scanf("%d", &(atl + i)->idade);

        printf("Altura: ");
        scanf("%f", &(atl + i)->altura);
    }
    return;
}

int main(int argc, char const *argv[])
{
    Atleta atletas[5];
    Atleta aux;
    int i, j;

    lerAtleta(atletas);

    for ( i = 0; i < 5; i++)
    {
        for ( j = 0; j < 5 - 1; j++)
        {
            if (atletas[j].idade > atletas[j + 1].idade)
            {
                aux = atletas[j];
                atletas[j] = atletas[j + 1];
                atletas[j + 1] = aux;
            }
        }
        
    }
    
    for ( i = 4; i >= 0; i--)
    {
        printf("\n%s", atletas[i].nome);
    }
    

    return 0;
}
