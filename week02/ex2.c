#include <stdio.h>
#include <string.h>

char *strrev(char *str)
{
    if (!str || ! *str) return str;

    int i = strlen(str) - 1;
    int j = 0;
    char sym;

    while (i > j)
    {
        sym = str[i];
        str[i--] = str[j];
        str[j++] = sym;
    }

    return str;
}

int main()
{
    char str[256];
    printf("Enter a string:\n");
    gets(str);

    strrev(str);

    printf("Reverse of the string:\n%s\n", str);

    return 0;
}
