#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float vetor[10];

    for (size_t i = 0; i < 10; i++)
    {
        printf("vetor [%li]: %p\n",i, (vetor + i));
    }

    return 0;
}
