#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "login.h"

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    
    Personagem *personagens = malloc(10 * sizeof(Personagem));

    login();

    menu(personagens);

    return 0;
}
