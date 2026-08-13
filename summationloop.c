#include <stdio.h>

int main()
{
    int x, n;
    long long sum = 0;
    long long term = 1;

    printf("Enter x and n:");
    scanf("%d %d",&x,&n);

    for (int i = 0; i <= n; i++)
    {
        sum = sum + term;
        term = term * x;
    }

    printf("Sum = %lld\n",sum);

    return 0;
}
