#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

int hashfunction(int key)
{
    return key % SIZE;
}

void initialise()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

void insert(int key)
{
    int index = hashfunction(key);

    for (int i = 0; i < SIZE; i++)
    {
        int newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1)
        {
            hashTable[newIndex] = key;
            printf("%d inserted at index %d\n", key, newIndex);
            return;
        }
    }

    printf("Hash table is full!\n");
}

void display()
{
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
        {
            printf("%d -> Empty\n", i);
        }
        else
        {
            printf("%d -> %d\n", i, hashTable[i]);
        }
    }
}

int main()
{
    initialise();

    insert(10);
    insert(20);
    insert(25);
    insert(35);
    insert(45);
    insert(55);

    display();

    return 0;
}
