typedef struct Stack
{
    int capacity;
    int topIndex;
    int *elements;
} Stack;
void initialize(Stack *s, int capacity);
int isStackEmpty(Stack s);
int isStackFull(Stack s);
void push(Stack *s, int value);
int pop(Stack *s);
void display(Stack s);
void convertDecimalToBinary(int number);