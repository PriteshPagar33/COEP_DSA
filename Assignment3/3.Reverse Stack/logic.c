#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void initialize(Stack *s, int capacity)
{
    s->capacity = capacity;
    s->topIndex = -1;
    s->elements = malloc(capacity * sizeof(char));
}

void push(Stack *s, char value)
{
    if (s->topIndex < s->capacity - 1)
    {
        s->elements[++s->topIndex] = value;
    }
}

char pop(Stack *s)
{
    if (s->topIndex >= 0)
    {
        return s->elements[s->topIndex--];
    }
    return '\0';
}

void display(Stack s)
{
    for (int i = s.topIndex; i >= 0; i--)
    {
        printf("%c", s.elements[i]);
    }
    printf("\n");
}

void insertAtBottom(Stack *s, char value)
{
    if (s->topIndex == -1)
    {
        push(s, value);
        return;
    }
    char temp = pop(s);
    insertAtBottom(s, value);
    push(s, temp);
}
void reverseString(char str[])
{
    int length = strlen(str);
    Stack s;
    initialize(&s, length);
    for (int i = length - 1; i >= 0; i--)
    {
        push(&s, str[i]);
    }
    reverse(&s);
    printf("Reversed string: ");
    display(s);
}
void reverse(Stack *s)
{
    if (s->topIndex == -1)
    {
        return;
    }
    char temp = pop(s);
    reverse(s);
    insertAtBottom(s, temp);
}