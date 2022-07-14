#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE* arq;
    char nome_arq[20], _char;
    int cont_letras[26];

    printf("Digite o nome do arquivo: ");
    fgets(nome_arq, 20, stdin);
    nome_arq[strcspn(nome_arq, "\n")] = '\0';

    arq = fopen(nome_arq, "r");

    if(arq == NULL)
    {
        printf("Erro ao abrir o arquivo...");
        exit(1);
    }

    for (size_t i = 0; i < 26; i++)
    {
        cont_letras[i] = 0;
    }
    

    while((_char =fgetc(arq)) != EOF)
    {
        if(_char == 'a' || _char == 'A')
            cont_letras[0]++;
        if(_char == 'b' || _char == 'B')
            cont_letras[1]++;
        if(_char == 'c' || _char == 'C')
            cont_letras[2]++;
        if(_char == 'd' || _char == 'D')
            cont_letras[3]++;
        if(_char == 'e' || _char == 'E')
            cont_letras[4]++;
        if(_char == 'f' || _char == 'F')
            cont_letras[5]++;
        if(_char == 'g' || _char == 'G')
            cont_letras[6]++;
        if(_char == 'h' || _char == 'H')
            cont_letras[7]++;
        if(_char == 'i' || _char == 'I')
            cont_letras[8]++;
        if(_char == 'j' || _char == 'J')
            cont_letras[9]++;
        if(_char == 'k' || _char == 'K')
            cont_letras[10]++;
        if(_char == 'l' || _char == 'L')
            cont_letras[11]++;
        if(_char == 'm' || _char == 'M')
            cont_letras[12]++;
        if(_char == 'n' || _char == 'N')
            cont_letras[13]++;
        if(_char == 'o' || _char == 'O')
            cont_letras[14]++;
        if(_char == 'p' || _char == 'P')
            cont_letras[15]++;
        if(_char == 'q' || _char == 'Q')
            cont_letras[16]++;
        if(_char == 'r' || _char == 'R')
            cont_letras[17]++;
        if(_char == 's' || _char == 'S')
            cont_letras[18]++;
        if(_char == 't' || _char == 'T')
            cont_letras[19]++;
        if(_char == 'u' || _char == 'U')
            cont_letras[20]++;
        if(_char == 'v' || _char == 'V')
            cont_letras[21]++;
        if(_char == 'w' || _char == 'W')
            cont_letras[22]++;
        if(_char == 'x' || _char == 'X')
            cont_letras[23]++;
        if(_char == 'y' || _char == 'Y')
            cont_letras[24]++;
        if(_char == 'z' || _char == 'Z')
            cont_letras[25]++;
    }

    printf("Letra a: %i vezes.\n", cont_letras[0]);
    printf("Letra b: %i vezes.\n", cont_letras[1]);
    printf("Letra c: %i vezes.\n", cont_letras[2]);
    printf("Letra d: %i vezes.\n", cont_letras[3]);
    printf("Letra e: %i vezes.\n", cont_letras[4]);
    printf("Letra f: %i vezes.\n", cont_letras[5]);
    printf("Letra g: %i vezes.\n", cont_letras[6]);
    printf("Letra h: %i vezes.\n", cont_letras[7]);
    printf("Letra i: %i vezes.\n", cont_letras[8]);
    printf("Letra j: %i vezes.\n", cont_letras[9]);
    printf("Letra k: %i vezes.\n", cont_letras[10]);
    printf("Letra l: %i vezes.\n", cont_letras[11]);
    printf("Letra m: %i vezes.\n", cont_letras[12]);
    printf("Letra n: %i vezes.\n", cont_letras[13]);
    printf("Letra o: %i vezes.\n", cont_letras[14]);
    printf("Letra p: %i vezes.\n", cont_letras[15]);
    printf("Letra q: %i vezes.\n", cont_letras[16]);
    printf("Letra r: %i vezes.\n", cont_letras[17]);
    printf("Letra s: %i vezes.\n", cont_letras[18]);
    printf("Letra t: %i vezes.\n", cont_letras[19]);
    printf("Letra u: %i vezes.\n", cont_letras[20]);
    printf("Letra v: %i vezes.\n", cont_letras[21]);
    printf("Letra w: %i vezes.\n", cont_letras[22]);
    printf("Letra x: %i vezes.\n", cont_letras[23]);
    printf("Letra y: %i vezes.\n", cont_letras[24]);
    printf("Letra z: %i vezes.\n", cont_letras[25]);

    fclose(arq);

    return 0;
}
