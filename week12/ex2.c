#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>


void _exit() 
{
    exit(0);
}

int main() 
{
    char path[] = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int keyboard = open(path, O_RDONLY);
    
    struct input_event event;
    FILE* output = fopen("ex2.txt", "w");
    signal(SIGINT, _exit);

    while (free)
    {
        read(keyboard, &e, sizeof(event));

        if (event.type == 1)
        {
            if (event.value == 1) fprintf(output, "PRESSED %x (%d)\n", event.code, event.code);
            else if (event.value == 0) fprintf(output, "RELEASED  %x (%d)\n", event.code, event.code);
                
            fflush(output);
        }
    }
    
    return 0;
}
