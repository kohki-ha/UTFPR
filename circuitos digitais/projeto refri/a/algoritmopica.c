#include <stdlib.h>
#include <stdio.h>

int valor, contador_unidade, contador_dezena, contador_centena, contador_milhares;
char display1, display2, display3, display4;

int main ()
{

printf("Digite o valor: ");
scanf("%d", &valor);

while(valor>0){
    if (valor <= 9)
    {
        valor = valor - 1;
        contador_unidade++;

    }else if(valor <= 99)
    {

        valor = valor - 10;
        contador_dezena++;

    }else if(valor <= 999)
    {

        valor = valor - 100;
        contador_centena++;

    }else if(valor <= 9999)
    {

        valor = valor - 1000;
        contador_milhares++;

    }
}
switch(contador_unidade) 
{

    case 0:
        display1 = 0;
        break;
    case 1:
        display1 = 1;
        break;
    case 2:
        display1 = 2;
        break;
    case 3:
        display1 = 3;
        break;
    case 4:
        display1 = 4;
        break;
    case 5:
        display1 = 5;
        break;
    case 6:
        display1 = 6;
        break;
    case 7:
        display1 = 7;
        break;
    case 8:
        display1 = 8;
        break;
    case 9:
        display1 = 9;
        break;
    default:
    break;

}
switch(contador_dezena) 
{

    case 0:
        display2 = 0;
        break;
    case 1:
        display2 = 1;
        break;
    case 2:
        display2 = 2;
        break;
    case 3:
        display2 = 3;
        break;
    case 4:
        display2 = 4;
        break;
    case 5:
        display2 = 5;
        break;
    case 6:
        display2 = 6;
        break;
    case 7:
        display2 = 7;
        break;
    case 8:
        display2 = 8;
        break;
    case 9:
        display2 = 9;
        break;
    default:
    break;

}
switch(contador_centena) 
{

    case 0:
        display3 = 0;
        break;
    case 1:
        display3 = 1;
        break;
    case 2:
        display3 = 2;
        break;
    case 3:
        display3 = 3;
        break;
    case 4:
        display3 = 4;
        break;
    case 5:
        display3 = 5;
        break;
    case 6:
        display3 = 6;
        break;
    case 7:
        display3 = 7;
        break;
    case 8:
        display3 = 8;
        break;
    case 9:
        display3 = 9;
        break;
    default:
    break;

}
switch(contador_milhares) 
{

    case 0:
        display4 = 0;
        break;
    case 1:
        display4 = 1;
        break;
    case 2:
        display4 = 2;
        break;
    case 3:
        display4 = 3;
        break;
    case 4:
        display4 = 4;
        break;
    case 5:
        display4 = 5;
        break;
    case 6:
        display4 = 6;
        break;
    case 7:
        display4 = 7;
        break;
    case 8:
        display4 = 8;
        break;
    case 9:
        display4 = 9;
        break;
    default:
    break;
}

printf("\n\nO primeiro display mostraria um %d\n", display1);
printf("O segundo display mostraria um %d\n", display2);
printf("O terceiro display mostrara um %d\n", display3);
printf("O quarto display mostrara um %d\n\n", display4);
return 0;
}