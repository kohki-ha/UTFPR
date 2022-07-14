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
Elabore uma função que receba como parâmetro um valor 
inteiro n e gere como saída um triângulo lateral formado 
por asteriscos conforme o exemplo a seguir, em que usamos n = 4:
*
**
***
****
***
**
*
*/

#include <stdlib.h>
#include <stdio.h>

void triangulo(int n)
{
    int i, j;

    for (i = 0; i <= n; i++)
    {
        for ( j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
    
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
            printf("*");
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int n;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    triangulo(n);

    return 0;
}
