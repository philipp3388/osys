#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    while(1)
    {
        int *ptr = malloc(10000000);
        memset(ptr, 0, 4);
        sleep(1);
    }
    return 0;
}
