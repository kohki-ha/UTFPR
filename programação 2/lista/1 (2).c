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
Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, 
seu esporte, idade e altura. Agora, escreva um programa que leia os dados de cinco atletas. 
Calcule e exiba os nomes do atleta mais alto e do mais velho
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

float maiorAltura(Atleta* atl)
{
    float maior = 0;

    for (size_t i = 0; i < 5; i++)
        if ((atl + i)->altura > maior)
            maior = (atl + i)->altura;
    
    return maior;
}

void atletaMaiorAltura(Atleta* atl, float maior)
{
    for (size_t i = 0; i < 5; i++)
        if ((atl + i)->altura == maior)
            printf("\n\nAtleta com maior altura: %s\n", (atl + i)->nome);

    return;
}

int maiorIdade(Atleta* atl)
{
    int maior = 0;

    for (size_t i = 0; i < 5; i++)
        if ((atl + i)->idade > maior)
            maior = (atl + i)->idade;

    return maior;
}

void atletaMaiorIdade(Atleta* atl, float maior)
{
    for (size_t i = 0; i < 5; i++)
        if ((atl + i)->idade == maior)
            printf("\nAtleta com maior idade: %s\n", (atl + i)->nome);

    return;
}

int main(int argc, char const *argv[])
{
    Atleta atletas[5];
    float maior_altura;
    int maior_idade;

    lerAtleta(atletas);

    maior_altura = maiorAltura(atletas);
    maior_idade = maiorIdade(atletas);

    atletaMaiorAltura(atletas, maior_altura);
    atletaMaiorIdade(atletas, maior_idade);


    return 0;
}