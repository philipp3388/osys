#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int main(int argc, char * argv[])
{
    int a, b;

    printf("Enter a first number:\n");
    scanf("%d", &a);

    printf("Enter a second number:\n");
    scanf("%d", &b);

    printf("Before: %d, %d\n", a, b);
    swap(&a, &b);
    printf("After: %d, %d\n", a, b);

    return 0;
}
