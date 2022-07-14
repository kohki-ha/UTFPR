#include <stdio.h>
#include <stdlib.h>

int prim_quad(float x, float y)
{
    if(x > 0 && y > 0)
        return 1;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    printf("%d", prim_quad(0.5, 2.1));

    return 0;
}
