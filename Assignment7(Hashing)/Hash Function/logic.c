#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_VALUE -1

void initializeHashTable(HashTable *hashTable, int tableSize)
{
    hashTable->tableSize = tableSize;
    hashTable->elements = (int *)malloc(tableSize * sizeof(int));
    for (int i = 0; i < tableSize; i++)
    {
        hashTable->elements[i] = EMPTY_VALUE;
    }
}

int computeHash(int value, int tableSize)
{
    return value % tableSize;
}

void insertValue(HashTable *hashTable, int value)
{
    int index = computeHash(value, hashTable->tableSize);
    if (hashTable->elements[index] != EMPTY_VALUE)
    {
        printf("Collision occurred: Element already present at index %d\n", index);
        return;
    }
    else
    {
        hashTable->elements[index] = value;
    }
}

void deleteValue(HashTable *hashTable, int value)
{
    int index = computeHash(value, hashTable->tableSize);
    if (hashTable->elements[index] == EMPTY_VALUE)
    {
        printf("Element not present in the hash table\n");
        return;
    }
    else
    {
        hashTable->elements[index] = EMPTY_VALUE;
    }
}

void displayHashTable(HashTable *hashTable)
{
    printf("Index\tData\n");
    for (int i = 0; i < hashTable->tableSize; i++)
    {
        if (hashTable->elements[i] == EMPTY_VALUE)
        {
            printf("%d\t--\n", i);
        }
        else
        {
            printf("%d\t%d\n", i, hashTable->elements[i]);
        }
    }
}
