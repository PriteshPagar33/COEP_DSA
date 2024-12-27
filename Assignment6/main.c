#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <number.txt>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Error opening file");
        return 1;
    }

    int count = 0, num;
    while (fscanf(file, "%d", &num) != EOF)
    {
        count++;
    }
    rewind(file);

    MinHeap *heap = createHeap(count);

    while (fscanf(file, "%d", &num) != EOF)
    {
        insert(heap, num);
    }
    fclose(file);
    printf("Sorted numbers:\n");
    while (heap->size > 0)
    {
        printf("%d ", removeMin(heap));
    }
    printf("\n");
    destroyHeap(heap);
    return 0;
}