#include <stdio.h>
#include <stdlib.h>

float calcularMedia(float n[3], char op){
    float calculo;
    switch (op)
    {
    case 'A':
    case 'a':
        calculo = (n[0] + n[1] + n[2]) / 3;
        break;
    
    case 'P':
    case 'p':
        calculo = (n[0] * 5 + n[1] * 3 + n[2] * 2) / (5 + 3 + 2);
        break;

    case 'S':
    case 's':
        calculo = n[0] + n[1] + n[2];
        break;
    }
    return calculo;
}

int main(int argc, char const *argv[])
{
    float notas[3], calculo;
    char opcao;

    for (size_t i = 0; i < 3; i++)
    {
        printf("\nDigite a nota %i: ", i);
        scanf("%f", &notas[i]);
    }

    setbuf(stdin, NULL);
    printf("Escolha uma operacao para ser realizada com as notas:\n\tA - Media aritmetica\n\tP - Media ponderada\n\tS - Soma");
    scanf("%c", &opcao);

    calculo = calcularMedia(notas, opcao);

    switch (opcao)
    {
    case 'A':
    case 'a':
        printf("\nMedia arritmetica: %.2f", calcularMedia(notas, opcao));
        break;
    
    case 'P':
    case 'p':
        printf("\nMedia ponderada: %.2f", calcularMedia(notas, opcao));
        break;

    case 'S':
    case 's':
        printf("\nSoma das notas: %.2f", calcularMedia(notas, opcao));
        break;
    }
    
    return 0;
}
