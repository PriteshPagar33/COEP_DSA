typedef struct TwoStack
{
    int topA;
    int topB;
    int sizeA;
    int sizeB;
    int *array;
} TwoStack;
void initialize(TwoStack *s, int sizeA, int sizeB);
void pushStackA(TwoStack *s, int value);
void pushStackB(TwoStack *s, int value);
int popStackA(TwoStack *s);
int popStackB(TwoStack *s);
void displayStacks(TwoStack s);