#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef enum
{
    BRASILEIRO,
    ESTRANGEIRO
} Nascionalidade;

typedef union {
    char cpf[15];
    char passaporte[10];
} Documento;

typedef struct
{
    char nome[30];
    int idade;
    float peso;
    Data nascimento;
    Nascionalidade nascionalidade;
    Documento doc;
} Cadastro;

int main(int argc, char const *argv[])
{
    Cadastro pessoas[5];

    for (size_t i = 0; i < 5; i++)
    {
        printf("\nDigite o nome: ");
        fgets(pessoas[i].nome, 30, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("Digte o peso: ");
        scanf("%f", &pessoas[i].peso);

        printf("Digite a data de nascimento (dd/mm/aaaa): ");
        scanf("%d/%d/%d", &pessoas[i].nascimento.dia, 
               &pessoas[i].nascimento.mes, &pessoas[i].nascimento.ano);

        printf("Digite 0 para brasileiro ou 1 para estrangeiro: ");
        scanf("%i", &pessoas[i].nascionalidade);
        setbuf(stdin, NULL);

        switch (pessoas[i].nascionalidade)
        {
        case BRASILEIRO:
            printf("Digite o CPF: ");
            fgets(pessoas[i].doc.cpf, 15, stdin);
            pessoas[i].doc.cpf[strcspn(pessoas[i].doc.cpf, "\n")] = '\0';
            break;
        
        case ESTRANGEIRO:
            printf("Digite o passaporte: ");
            fgets(pessoas[i].doc.passaporte, 10, stdin);
            pessoas[i].doc.passaporte[strcspn(pessoas[i].doc.passaporte, "\n")] = '\0';
            break;
        }
    }

    for (size_t i = 0; i < 5; i++)
    {
        printf("\nNome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("Data de nascimento: %d/%d/%d\n", pessoas[i].nascimento.dia,
                pessoas[i].nascimento.mes, pessoas[i].nascimento.ano);

        switch (pessoas[i].nascionalidade)
        {
        case BRASILEIRO:
            printf("CPF: %s", pessoas[i].doc.cpf);
            break;
        
        case ESTRANGEIRO:
            printf("CPF: %s\n\n", pessoas[i].doc.passaporte);
            break;
        }
    }
    
    
    return 0;
}
