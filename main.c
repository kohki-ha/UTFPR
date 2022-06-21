#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#include "login.h"

/*
Ao sair do programa, todos os dados devem ser salvos em arquivos binários no
HD e recarregados novamente ao iniciar. Caso os arquivos não existam, eles
devem ser criados e uma mensagem de boas vindas deve ser apresentada ao
usuário;
*/

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    
    Personagem *personagens = malloc(10 * sizeof(Personagem));

    login();

    menu(personagens);

    return 0;
}
