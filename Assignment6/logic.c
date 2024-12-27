#include <stdio.h>
#include <stdlib.h>
#include "header.h"

MinHeap *createHeap(int cap)
{
    MinHeap *heap = (MinHeap *)malloc(sizeof(MinHeap));
    heap->arr = (int *)malloc(cap * sizeof(int));
    heap->size = 0;
    heap->capacity = cap;
    return heap;
}

void insert(MinHeap *heap, int value)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap capacity exceeded.\n");
        return;
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

void heapifyUp(MinHeap *heap, int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap->arr[parent] > heap->arr[index])
    {
        int temp = heap->arr[parent];
        heap->arr[parent] = heap->arr[index];
        heap->arr[index] = temp;

        index = parent;
        parent = (index - 1) / 2;
    }
}

int removeMin(MinHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty.\n");
        return -1;
    }
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

void heapifyDown(MinHeap *heap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
    {
        smallest = left;
    }
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
    {
        smallest = right;
    }
    if (smallest != index)
    {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        heapifyDown(heap, smallest);
    }
}

void destroyHeap(MinHeap *heap)
{
    free(heap->arr);
    free(heap);
}