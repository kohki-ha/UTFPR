#include <stdio.h>
#include <stdlib.h>

char conceito(float m){
    if(m >= 9 && m <= 10)
        return 'A';
    else if(m >= 7 && m < 9)
        return 'B';
    else if(m >= 5 && m < 7)
        return 'C';
    else
        return 'D';
}

int main(int argc, char const *argv[])
{
    float notas[3], media;
    
    for (size_t i = 0; i < 3; i++)
    {
        printf("\nDigite a nota %i: ", i);
        scanf("%f", &notas[i]);
    }

    media = (notas[0] + notas[1] + notas[2]) / 3;
    
    printf("\nO conceito referen a media das notas eh: %c\n", conceito(media));
    
    return 0;
}
