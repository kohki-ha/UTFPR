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
Faça uma função que receba um inteiro N como parâmetro. 
Calcule e retorne o resultado da seguinte série S:
    S = 2/5 + 5/5 + 10/6 + ... + (N² + 1)/(N + 3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float serieS(int n)
{
    float s;

    for (size_t i = 0; i <= n; i++)
    {
        s = s + ((pow(n, 2) + 1) / (n + 3));
    }

    return s;
    
}

int main(int argc, char const *argv[])
{
    int n;

    printf("Digite o valor de N: ");
    scanf("%d", &n);

    printf("Resultado da serie S: %.2f\n", serieS(n));

    return 0;
}
