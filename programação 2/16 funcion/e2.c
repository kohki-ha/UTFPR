#include <stdio.h>
#include <stdlib.h>

float pesoIdeal(char c, float altura){
    if(c == 'H' || c == 'h')
        return (72.7 * altura) - 58;
    else
        return (62.1 * altura) - 44.7;
}

int main(int argc, char const *argv[])
{
    char sexo;
    float altura;

    printf("Digite: \nH - para homem;\nM - para mulher\n");
    scanf("%c", &sexo);

    printf("\nDigite a altura: ");
    scanf("%f", &altura);

    printf("\nO peso ideal eh: %.2f", pesoIdeal(sexo, altura));

    return 0;
}
