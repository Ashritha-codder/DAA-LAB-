#include <stdio.h>

#define SIZE 100

int main()
{
    int a[SIZE], hash[SIZE] = {0};
    int n, T;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target value: ");
    scanf("%d", &T);

    for (int i = 0; i < n; i++)
    {
        int need = T - a[i];

        if (need >= 0 && need < SIZE && hash[need] == 1)
        {
            printf("Pair found: %d + %d = %d\n", need, a[i], T);
            return 0;
        }

        if (a[i] >= 0 && a[i] < SIZE)
            hash[a[i]] = 1;
    }

    printf("No pair found\n");

    return 0;
}
