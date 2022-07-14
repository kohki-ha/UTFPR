#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[20];
    char curso[20];
    float nota[3];
    float media;
    char situacao[10]
} Aluno;


int main(int argc, char const *argv[])
{
    int i;
    Aluno aluno;

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, 20, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("Digite o curso: ");
    fgets(aluno.curso, 20, stdin);
    aluno.curso[strcspn(aluno.curso, "\n")] = '\0';
    setbuf(stdin, NULL);

    for(i = 0; i < 4; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &aluno.nota[i]);
    }

    aluno.media = (aluno.nota[0] + aluno.nota[1] + aluno.nota[2] + aluno.nota[3]) / 4;

    printf("\nA media do aluno eh %.2f", aluno.media);

    if(aluno.media >= 7)
        strcpy(aluno.situacao, "Aprovado");
    else if(aluno.media < 3)
        strcpy(aluno.situacao, "Reprovado");
    else
        strcpy(aluno.situacao, "Exame");
        
    printf("\nO aluno esta %s\n", aluno.situacao);

    return 0;
}
