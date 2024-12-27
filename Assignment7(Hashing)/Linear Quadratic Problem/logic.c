#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define EMPTY_SLOT -1

void initializeHashTable(HashTable *hashTable, int capacity)
{
    hashTable->capacity = capacity;
    hashTable->elements = (int *)malloc(capacity * sizeof(int));
    for (int i = 0; i < capacity; i++)
    {
        hashTable->elements[i] = EMPTY_SLOT;
    }
    return;
}

int computeHash(int value, int capacity)
{
    return value % capacity;
}

void insertWithLinearProbing(HashTable *hashTable, int value)
{
    int originalIndex = computeHash(value, hashTable->capacity);
    int currentIndex = originalIndex;
    for (int i = 1; i < hashTable->capacity; i++)
    {
        if (hashTable->elements[currentIndex] == EMPTY_SLOT)
        {
            hashTable->elements[currentIndex] = value;
            printf("Element inserted successfully\n");
            return;
        }
        else
        {
            currentIndex = (originalIndex + i) % hashTable->capacity;
        }
    }
    printf("No empty slot available to insert\n");
    return;
}

void deleteWithLinearProbing(HashTable *hashTable, int value)
{
    int originalIndex = computeHash(value, hashTable->capacity);
    int currentIndex = originalIndex;
    for (int i = 0; i < hashTable->capacity; i++)
    {
        if (hashTable->elements[currentIndex] == value)
        {
            hashTable->elements[currentIndex] = EMPTY_SLOT;
            printf("Element deleted successfully\n");
            return;
        }
        else
        {
            currentIndex = (originalIndex + i) % hashTable->capacity;
        }
    }
    printf("Element not found\n");
    return;
}

void insertWithQuadraticProbing(HashTable *hashTable, int value)
{
    int originalIndex = computeHash(value, hashTable->capacity);
    int currentIndex = originalIndex;
    for (int i = 1; i < hashTable->capacity; i++)
    {
        if (hashTable->elements[currentIndex] == EMPTY_SLOT)
        {
            hashTable->elements[currentIndex] = value;
            printf("Element inserted successfully\n");
            return;
        }
        else
        {
            currentIndex = (originalIndex + (i * i)) % hashTable->capacity;
        }
    }
    printf("No empty slot available to insert\n");
    return;
}

void deleteWithQuadraticProbing(HashTable *hashTable, int value)
{
    int originalIndex = computeHash(value, hashTable->capacity);
    int currentIndex = originalIndex;
    for (int i = 0; i < hashTable->capacity; i++)
    {
        if (hashTable->elements[currentIndex] == value)
        {
            hashTable->elements[currentIndex] = EMPTY_SLOT;
            printf("Element deleted successfully\n");
            return;
        }
        else
        {
            currentIndex = (originalIndex + (i * i)) % hashTable->capacity;
        }
    }
    printf("Element not found\n");
    return;
}

void displayHashTable(HashTable *hashTable)
{
    printf("Index\tData\n");
    for (int i = 0; i < hashTable->capacity; i++)
    {
        if (hashTable->elements[i] == EMPTY_SLOT)
        {
            printf("%d\t--\n", i);
        }
        else
        {
            printf("%d\t%d\n", i, hashTable->elements[i]);
        }
    }
    return;
}
