#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char disciplinas[3][15];
    char concatenar[4] = " - ";
    float notas[3];
    FILE* arq;

    arq = fopen("notas_alunos.txt", "a");
    if(arq == NULL)
    {
        printf("\nErro ao abrir o arquivo\n");
        exit(1);
    }

    for (size_t i = 0; i < 3; i++)
    {
        printf("\nDigite a disciplina %i: ", i + 1);
        setbuf(stdin, NULL);
        fgets(disciplinas[i], 15, stdin);
        disciplinas[i][strcspn(disciplinas[i], "\n")] = '\0';

        printf("Digite a nota dessa disciplina: ");
        scanf("%f", &notas[i]);
    }
    
    for (size_t i = 0; i < 3; i++)
    {
        strcat(disciplinas[i], concatenar);
    }

    for (size_t i = 0; i < 3; i++)
    {
        fprintf(arq, "%s%.2f\n", disciplinas[i], notas[i]);
    }

    fclose(arq);

    return 0;
}
