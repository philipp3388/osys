#include <stdlib.h>
#include <stdio.h>

struct frame
{
    int age;
    int number;
};


struct frame *frames;

int hit = 0, miss = 0;
int num = 128;


void update(int next, int n)
{
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        if (frames[i].number == -1)
        {
            m = i;
            break;
        }

        else if (frames[i].age < frames[m].age)
            m = i;

        frames[i].age = frames[i].age >> 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (frames[i].number == next)
        {
            frames[i].age = frames[i].age | num;
            hit++;
            return;
        }
    }

    frames[m].age = num;
    frames[m].number = next;
    miss++;
}


int main()
{
    FILE *input;
    input = fopen("input.txt", "r");

    int n;
    scanf("%d", &n);

    frames = malloc(sizeof(struct frame) * n);

    for (int i = 0; i < n; i++)
    {
        frames[i].number = -1;
        frames[i].age = 0;
    }

    int next;
    while (fscanf(input, "%d", &next) != EOF)
    {
        update(next, n);
        printf("%d\n", next);
    }

    printf("hits: %d\nmisses: %d\nratio: %f\n", hit, miss, (double)hit/miss);

    return 0;
}
