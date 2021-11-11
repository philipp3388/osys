#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>

int main() 
{
    char* dev[] = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, O_RDONLY);
    FILE *f = fopen("ex3.txt", "w+");
    struct input_event event;
    
    read(fd, &event, sizeof(struct input_event));
    read(fd, &event, sizeof(struct input_event));

    printf("Press Q to exit!\n");
    
    int cap = 0;
    int pe = 0;
    int hw = 0;
    
    fprintf(f, "Shortcuts:\nP + E -> I passed the exam!\nC + A + P -> Get some cappuccino!\nH + W -> You have some homework to do!\n");
    
    while(true) 
    {
        read(fd, &event, sizeof(struct input_event));
    
        if(event.type != 4 && event.code != EV_SYN) 
        {
            if (event.value == 0)
                continue;
                if (event.code == 46) cap = 1, pe = 0, hw = 0;
                else if (event.code == 30 && cap == 1) cap = 2, pe = 0, hw = 0;
                else if (event.code == 25) 
                {
                    if (cap == 2) fprintf(f, "Get some cappuccino!\n");
                    pe = 1;
                    hw = 0;
                    cap = 0;
                } 
                else if (event.code == 18 && pe == 1) 
                {
                    fprintf(f, "I passed the exam!\n");
                    pe = 0, hw = 0, cap = 0;
                } 
                else if (event.code == 35) hw = 1, pe = 0, cap = 0;
                else if (event.code == 17 && hw == 1) 
                {
                    fprintf(f, "You have some homework to do!\n");
                    pe = 0, hw = 0, cap = 0;
                } 
                else if (event.code == 16) return 0;
                else pe = 0, hw = 0, cap = 0;
        }
    }
    
    return 0;
}