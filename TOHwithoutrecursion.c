#include <stdio.h>

#define MAX 100

int stack[MAX][4];
int top = -1;

void push(int n, char source, char auxiliary, char destination)
{
    top++;
    stack[top][0] = n;
    stack[top][1] = source;
    stack[top][2] = auxiliary;
    stack[top][3] = destination;
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    push(n, 'A', 'B', 'C');

    while (top >= 0)
    {
        int disks = stack[top][0];
        char source = stack[top][1];
        char auxiliary = stack[top][2];
        char destination = stack[top][3];

        top--;
	
	if (disks == 0) {
		printf("move disk from %c to %c\n",source,destination);
	}
        else if (disks == 1)
        {
            printf("Move disk 1 from %c to %c\n",
                   source, destination);
        }
        else
        {
            // Second recursive call
            push(disks - 1, auxiliary, source, destination);

            // Move largest disk
            push(0, source, auxiliary, destination);

            // First recursive call
            push(disks - 1, source, destination, auxiliary);
        }
    }

    return 0;
}
