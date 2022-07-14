#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct{
    float posicao_x;
    float posicao_y;
} Coordenada;

int main(int argc, char const *argv[])
{
    float distancia;

    Coordenada ponto[1];
    
    for (size_t i = 0; i < 2; i++)
    {
        printf("Digite a coordenada X do ponto [%i]: ", i);
        scanf("%f", &ponto[i].posicao_x);

        printf("Digite a coordenada Y do ponto [%i]: ", i);
        scanf("%f", &ponto[i].posicao_y);
    }

    distancia = sqrt(pow(ponto[1].posicao_x - ponto[0].posicao_x, 2) + pow(ponto[1].posicao_y - ponto[0].posicao_y, 2));

    printf("\nDistancio entre os dois pontos: %.2f\n\n", distancia);
    

    return 0;
}
