#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n = 228;

    pid_t pid = fork();
        
    if (pid == 0)
    {
        printf("Hello from child ");
        printf("[%d - %d]\n", (int) pid, n);
        
        exit(0);
    }
    else
    {
        printf("Hello from parent ");
        printf("[%d - %d]\n", (int) pid, n);
        
        exit(0);
    }
    
    return 0;
}
