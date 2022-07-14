#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float matriz[3][3];

    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("Endereço matriz [%li][%li]: %p", i, j, ((matriz + i)+ j));
            printf("\n");
        }
    }

    return 0;
}
