#include <stdio.h>
#include <limits.h>

int main()
{
    int n, k;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    int kth = 0;

    for (int count = 0; count < k; count++)
    {
        int minIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != INT_MAX &&
                (minIndex == -1 || a[i] < a[minIndex]))
            {
                minIndex = i;
            }
        }

        kth = a[minIndex];
        a[minIndex] = INT_MAX;
    }

    printf("Kth smallest element = %d\n", kth);

    return 0;
}
