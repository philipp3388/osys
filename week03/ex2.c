#include <stdio.h>

void swap(int *a, int *b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

void bubble_sort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j+1]);
}

int main()
{
    int n;
    int arr[256];

    printf("Enter size of array:\n");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bubble_sort(n, arr);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    printf("\n");

    return 0;
}
