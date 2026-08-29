#include <stdio.h>

#define SIZE 100

int main()
{
    int a[SIZE], hash[SIZE] = {0};
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        hash[a[i]]++;
    }

    printf("\nFrequency of elements:\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hash[i] > 0)
            printf("%d -> %d\n", i, hash[i]);
    }

    return 0;
}
