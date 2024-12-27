#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void initialize(Stack *s, int capacity)
{
    s->capacity = capacity;
    s->topIndex = -1;
    s->elements = malloc(capacity * sizeof(char));
}

void push(Stack *s, char value)
{
    if (s->topIndex + 1 < s->capacity)
    {
        s->elements[++s->topIndex] = value;
    }
    else
    {
        printf("Stack Overflow!\n");
    }
}

char pop(Stack *s)
{
    if (s->topIndex >= 0)
    {
        return s->elements[s->topIndex--];
    }
    else
    {
        printf("Stack Underflow!\n");
        return '\0';
    }
}

void display(Stack s)
{
    printf("Stack elements: ");
    for (int i = s.topIndex; i >= 0; i--)
    {
        printf("%c ", s.elements[i]);
    }
    printf("\n");
}

char getClosingMatch(char b)
{
    switch (b)
    {
    case '}':
        return '{';
    case ']':
        return '[';
    case ')':
        return '(';
    default:
        return '\0';
    }
}

int isStarting(char b)
{
    return (b == '{' || b == '[' || b == '(');
}

int isClosing(char b)
{
    return (b == '}' || b == ']' || b == ')');
}

int validateParentheses(Stack *s)
{
    Stack temp;
    initialize(&temp, s->capacity);

    while (s->topIndex != -1)
    {
        char currentChar = pop(s);

        if (isStarting(currentChar))
        {
            push(&temp, currentChar);
        }
        else if (isClosing(currentChar))
        {

            if (temp.topIndex != -1 && temp.elements[temp.topIndex] == getClosingMatch(currentChar))
            {
                pop(&temp);
            }
            else
            {
                return 0;
            }
        }
    }
    return (temp.topIndex == -1) ? 1 : 0;
}
void freeStack(Stack *s)
{
    free(s->elements);
}