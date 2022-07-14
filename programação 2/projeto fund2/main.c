#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char const *argv[])
{

    Personagem *personagens = malloc(10 * sizeof(Personagem));

    login();

    iniciar_programa(personagens);

    return 0;
}
