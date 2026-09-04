#include <stdio.h>

// Function to sort a bucket using Insertion Sort
void insertionSort(float bucket[], int n)
{
    int i, j;
    float key;

    for (i = 1; i < n; i++)
    {
        key = bucket[i];
        j = i - 1;

        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

// Bucket Sort function
void bucketSort(float arr[], int n)
{
    float bucket[10][100];
    int count[10] = {0};
    int i, j, k = 0, index;

    // Put elements into buckets
    for (i = 0; i < n; i++)
    {
        index = (int)(arr[i] * 10);

        if (index == 10)
            index = 9;

        bucket[index][count[index]++] = arr[i];
    }

    // Sort each bucket
    for (i = 0; i < 10; i++)
    {
        insertionSort(bucket[i], count[i]);
    }

    // Combine all buckets
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < count[i]; j++)
        {
            arr[k++] = bucket[i][j];
        }
    }
}

int main()
{
    float arr[100];
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements (0 to 1):\n");

    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }

    printf("\n");

    return 0;
}
