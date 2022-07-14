#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    printf("Foram passados %d argumentos\n", argc);

    for (size_t i = 0; i < argc; i++)
    {
        printf("O arg. %d eh: %s\n", i, argv[i]);
    }
    
    return 0;
}
