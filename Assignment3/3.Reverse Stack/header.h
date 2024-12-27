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
void insertAtBottom(Stack *s, char value);
void reverseString(char str[]);
void reverse(Stack *s);