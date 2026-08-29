#include <stdio.h>

#define SIZE 10

int hashtable[SIZE];

int intialise()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i] = -1;
    }
    return 0;
}

int hashfunction(int Key)
{
    return Key % SIZE;
}

void insert(int Key)
{
    int index = hashfunction(Key);
    int start = index;

    while (hashtable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if (index == start)
        {
            printf("Hash Table is full\n");
            return;
        }
    }

    hashtable[index] = Key;
}

int search(int Key)
{
    int index = hashfunction(Key);
    int start = index;

    while (hashtable[index] != -1)
    {
        if (hashtable[index] == Key)
            return index;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return -1;
}

void display()
{
    printf("Hash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashtable[i] == -1)
            printf("%d -> Empty\n", i);
        else
            printf("%d -> %d\n", i, hashtable[i]);
    }
}

int main()
{
    intialise();

    insert(10);
    insert(20);
    insert(25);
    insert(35);
    insert(15);

    display();

    int Key = 25;
    int result = search(Key);

    if (result != -1)
        printf("\n%d found at index %d\n", Key, result);
    else
        printf("\n%d not found\n", Key);

    return 0;
}
