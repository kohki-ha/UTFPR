#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"


int main(int argc, char const *argv[])
{
    Personagem *personagens = malloc(10 * sizeof(Personagem));

    menu(personagens);


    return 0;
}
