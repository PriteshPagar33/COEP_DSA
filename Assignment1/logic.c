#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void initializeADT(ArrayADT *adt, int size)
{
    adt->data = (int *)malloc(size * sizeof(int));
    if (!adt->data)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    adt->max_size = size;
    adt->current_size = 0;
}

void populateADT(ArrayADT *adt, int num_elements)
{
    if (num_elements > adt->max_size)
    {
        printf("Number of elements exceeds array size!\n");
        return;
    }
    for (int i = adt->current_size; i < num_elements; i++)
    {
        adt->data[i] = rand() % 100 + 1;
    }
    adt->current_size = num_elements;
}

void displayADT(ArrayADT *adt)
{
    if (adt->current_size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < adt->current_size; i++)
    {
        printf("%d ", adt->data[i]);
    }
    printf("\n");
}

void insertADT(ArrayADT *adt, int element, int position)
{
    if (adt->current_size >= adt->max_size)
    {
        printf("Array is full\n");
        return;
    }
    if (position < 0 || position > adt->current_size)
    {
        printf("Invalid position\n");
        return;
    }
    for (int i = adt->current_size; i > position; i--)
    {
        adt->data[i] = adt->data[i - 1];
    }
    adt->data[position] = element;
    adt->current_size++;
}

void deleteADT(ArrayADT *adt, int position)
{
    if (adt->current_size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    if (position < 0 || position >= adt->current_size)
    {
        printf("Invalid position.\n");
        return;
    }
    for (int i = position; i < adt->current_size - 1; i++)
    {
        adt->data[i] = adt->data[i + 1];
    }
    adt->current_size--;
    printf("Element deleted.\n");
}

int searchADT(ArrayADT *adt, int element)
{
    for (int i = 0; i < adt->current_size; i++)
    {
        if (adt->data[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void updateADT(ArrayADT *adt, int position, int new_element)
{
    if (position < 0 || position >= adt->current_size)
    {
        printf("Invalid position!\n");
        return;
    }
    adt->data[position] = new_element;
    printf("Element updated.\n");
}

int getMaxADT(ArrayADT *adt)
{
    int max = adt->data[0];
    for (int i = 1; i < adt->current_size; i++)
    {
        if (max < adt->data[i])
        {
            max = adt->data[i];
        }
    }
    return max;
}

int getMinADT(ArrayADT *adt)
{
    int min = adt->data[0];
    for (int i = 1; i < adt->current_size; i++)
    {
        if (min > adt->data[i])
        {
            min = adt->data[i];
        }
    }
    return min;
}

void reverseADT(ArrayADT *adt)
{
    int temp;
    for (int i = 0; i < adt->current_size / 2; i++)
    {
        temp = adt->data[i];
        adt->data[i] = adt->data[adt->current_size - i - 1];
        adt->data[adt->current_size - i - 1] = temp;
    }
    printf("Array reversed.\n");
}

void sortADT(ArrayADT *adt)
{
    int temp, min_idx;
    for (int i = 0; i < adt->current_size - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < adt->current_size; j++)
        {
            if (adt->data[j] < adt->data[min_idx])
            {
                min_idx = j;
            }
        }
        temp = adt->data[min_idx];
        adt->data[min_idx] = adt->data[i];
        adt->data[i] = temp;
    }
    printf("Array sorted.\n");
}

void appendADT(ArrayADT *adt, int element)
{
    if (adt->current_size == adt->max_size)
    {
        printf("Array is full.\n");
        return;
    }
    adt->data[adt->current_size++] = element;
    printf("Element appended.\n");
}
ArrayADT mergeADT(ArrayADT *adt1, ArrayADT *adt2)
{
    ArrayADT merged;
    initializeADT(&merged, adt1->current_size + adt2->current_size);
    for (int i = 0; i < adt1->current_size; i++)
    {
        appendADT(&merged, adt1->data[i]);
    }
    for (int i = 0; i < adt2->current_size; i++)
    {
        appendADT(&merged, adt2->data[i]);
    }
    printf("Arrays merged.\n");
    return merged;
}
void releaseADT(ArrayADT *adt)
{
    free(adt->data);
    adt->data = NULL;
    adt->max_size = 0;
    adt->current_size = 0;
    printf("Array memory released.\n");
}