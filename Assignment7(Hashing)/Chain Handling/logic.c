#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define EMPTY_VALUE -1

void initializeHashTable(HashTable *hashTable, int tableSize)
{
    hashTable->size = tableSize;
    hashTable->buckets = (Node *)malloc(tableSize * sizeof(Node));
    for (int index = 0; index < tableSize; index++)
    {
        hashTable->buckets[index].data = EMPTY_VALUE;
        hashTable->buckets[index].next = NULL;
    }
}

int calculateHash(int value, int tableSize)
{
    return value % tableSize;
}

void insertValue(HashTable *hashTable, int value)
{
    int bucketIndex = calculateHash(value, hashTable->size);
    if (hashTable->buckets[bucketIndex].data == EMPTY_VALUE)
    {
        hashTable->buckets[bucketIndex].data = value;
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = hashTable->buckets[bucketIndex].next;
        hashTable->buckets[bucketIndex].next = newNode;
    }
}

void deleteValue(HashTable *hashTable, int value)
{
    int bucketIndex = calculateHash(value, hashTable->size);
    if (hashTable->buckets[bucketIndex].data == EMPTY_VALUE)
    {
        printf("Element not present in Hash Table\n");
    }
    else
    {
        Node *currentNode = &hashTable->buckets[bucketIndex];
        Node *previousNode = NULL;
        while (currentNode != NULL)
        {
            if (currentNode->data == value)
            {
                if (previousNode == NULL)
                {
                    if (currentNode->next == NULL)
                    {
                        hashTable->buckets[bucketIndex].data = EMPTY_VALUE;
                        break;
                    }
                    Node *toDelete = currentNode->next;
                    currentNode->data = currentNode->next->data;
                    currentNode->next = currentNode->next->next;
                    free(toDelete);
                    break;
                }
                else
                {
                    previousNode->next = currentNode->next;
                    free(currentNode);
                    break;
                }
            }
            else
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
    }
}

void displayHashTable(HashTable *hashTable)
{
    printf("Bucket Index\tValues\n");
    for (int index = 0; index < hashTable->size; index++)
    {
        if (hashTable->buckets[index].data == EMPTY_VALUE)
        {
            printf("%d\t--\n", index);
        }
        else
        {
            Node *currentNode = &hashTable->buckets[index];
            printf("%d\t", index);
            while (currentNode != NULL)
            {
                printf("%d -> ", currentNode->data);
                currentNode = currentNode->next;
            }
            printf("\n");
        }
    }
}
