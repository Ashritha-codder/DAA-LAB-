#include <stdio.h>
#include <math.h>

int main()
{
    int x, n;
    long long sum;

    printf("Enter x and n: ");
    scanf("%d %d", &x, &n);

    if (x == 1)
        sum = n + 1;
    else
        sum = (pow(x, n + 1) - 1) / (x - 1);

    printf("Sum = %lld\n", sum);

    return 0;
}
