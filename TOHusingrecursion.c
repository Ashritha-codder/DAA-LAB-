#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
/* Base condition:
    If there is only one disk, directly move it
*/
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

/*   Step 1:
     Move the top (n-1) disks from source to auxiliary
     Destination rod is used as a temporary rod
*/

     towerOfHanoi(n - 1, source, destination, auxiliary);

/*   Step 2:
     Move the largest disk (disk n) from source to destination
*/     
     printf("Move disk %d from %c to %c\n", n, source, destination);

/*  Step 3:
    Move the (n-1) disks from auxiliary to destination
    Source rod is used as a temporary rod
*/  
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
