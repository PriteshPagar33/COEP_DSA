#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void initializeQueue(CircularQueue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}
int isQueueFull(CircularQueue *queue)
{
    return 0;
}
int isQueueEmpty(CircularQueue *queue)
{
    return queue->front == NULL;
}

void enqueue(CircularQueue *queue, Record data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL)
    {
        queue->front = newNode;
        queue->rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        newNode->next = queue->front;
        queue->rear = newNode;
    }
}

Record dequeue(CircularQueue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Queue is empty, cannot dequeue.\n");
        Record emptyRecord = {"", 0};
        return emptyRecord;
    }

    Node *temp = queue->front;
    Record data = temp->data;

    if (queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }

    free(temp);
    return data;
}

void displayQueue(CircularQueue queue)
{
    if (isQueueEmpty(&queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    Node *current = queue.front;
    do
    {
        printf("Name: %s, Age: %u\n", current->data.name, current->data.age);
        current = current->next;
    } while (current != queue.front);
}