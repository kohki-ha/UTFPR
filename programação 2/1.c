#include <stdio.h>
#include <stdlib.h>

int calcular(int a, int b, char c)
{
    if(c == 'X' || c == 'x')
        return a * b;
    
    if(c == 'S' || c == 's')
        return a + b;
}

int main(int argc, char const *argv[])
{
    int n1, n2;
    char letra;

    printf("Digite um numero: ");
    scanf("%d", &n1);

    printf("Digite outro numero: ");
    scanf("%d", &n2);

    setbuf(stdin, NULL);
    printf("Digite uma letra: ");
    scanf("%c", &letra);

    printf("O retorno da funcao foi o valor: %d", calcular(n1, n2, letra));

    return 0;
}
