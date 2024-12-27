#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    CircularQueue queue;
    Record record;

    initializeQueue(&queue);

    printf("Enter name and age (e.g. John 30). Type 'exit' to stop input:\n");

    while (1)
    {
        printf("Enter name and age: ");
        char input[100];
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "exit\n") == 0)
        {
            break;
        }

        sscanf(input, "%s %u", record.name, &(record.age));

        if (!isQueueFull(&queue))
        {
            enqueue(&queue, record);
        }
        else
        {
            printf("Queue is full! Cannot add more records.\n");
        }
    }
    printf("\nRecords in the queue:\n");
    while (!isQueueEmpty(&queue))
    {
        record = dequeue(&queue);
        printf("%s %u\n", record.name, record.age);
    }
    return 0;
}