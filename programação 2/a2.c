#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dist(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main(int argc, char const *argv[])
{
    printf("%.1f", dist(0, 0, 1, 1));

    return 0;
}
