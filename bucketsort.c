#include <stdio.h>

void bucketSort(int arr[], int n)
{
    int i, j, k;
    int max = arr[0];

    // Find maximum element
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int bucket[max + 1];

    // Initialize buckets
    for (i = 0; i <= max; i++)
        bucket[i] = 0;

    // Store elements in buckets
    for (i = 0; i < n; i++)
        bucket[arr[i]]++;

    // Copy elements back to array
    k = 0;

    for (i = 0; i <= max; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            arr[k] = i;
            k++;
        }
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
