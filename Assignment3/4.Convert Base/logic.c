#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void initialize(Stack *s, int capacity)
{
    s->capacity = capacity;
    s->topIndex = -1;
    s->elements = malloc(capacity * sizeof(int));
}
int isStackEmpty(Stack s)
{
    return s.topIndex == -1;
}
int isStackFull(Stack s)
{
    return s.topIndex == s.capacity - 1;
}
void push(Stack *s, int value)
{
    if (isStackFull(*s))
    {
        return;
    }
    s->elements[++s->topIndex] = value;
}

int pop(Stack *s)
{
    return s->elements[s->topIndex--];
}

void display(Stack s)
{
    for (int i = s.topIndex; i >= 0; i--)
    {
        printf("%d\t", s.elements[i]);
    }
    printf("\n");
}

void convertDecimalToBinary(int number)
{
    Stack s;
    initialize(&s, 32);

    while (number != 0)
    {
        push(&s, number % 2);
        number /= 2;
    }

    printf("Binary representation: ");
    display(s);

    free(s.elements);
}