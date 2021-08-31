#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pyr(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 2 * n - 1; j++)
        {
            if (j > (2 * n - 1) / 2 - i && j < (2 * n - 1) / 2 + i)
                printf("%c", '*');
            else
                printf("%c", ' ');
        }

        printf("\n");
    }
}

int main(int argc, char * argv[])
{
    int n = atoi(argv[1]);

    pyr(n);

    return 0;
}
