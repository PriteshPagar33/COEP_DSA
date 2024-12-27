typedef struct Stack
{
    int capacity;
    int topIndex;
    char *elements;
} Stack;
void initialize(Stack *s, int capacity);
void push(Stack *s, char value);
char pop(Stack *s);
void display(Stack s);
int getclosingMatch(char b);
int isStarting(char b);
int isClosing(char b);
int validateParentheses(Stack *s);
void freeStack(Stack *s);