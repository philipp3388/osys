#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a;
    float b;
    double c;

    printf("Maximum INT value: %u\n", INT_MAX);
    printf("Maximum FLOAT value: %f\n", FLT_MAX);
    printf("Maximum DOUBLE value: %f\n", DBL_MAX);

    printf("sizeof INT: %lu\n", sizeof(a));
    printf("sizeof FLOAT: %lu\n", sizeof(b));
    printf("sizeof DOUBLE: %lu\n", sizeof(c));

    return 0;
}
