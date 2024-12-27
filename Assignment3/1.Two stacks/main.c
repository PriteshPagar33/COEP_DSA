#include <stdio.h> 
#include <stdlib.h> 
#include "header.h"

int main(void)
{
    TwoStack stacks;
    initialize(&stacks, 5, 5);
    pushStackA(&stacks, 10);
    pushStackA(&stacks, 15);
    pushStackB(&stacks, 20);
    pushStackB(&stacks, 25);
    displayStacks(stacks);
    printf("Popped from Stack A: %d\n", popStackA(&stacks));
    printf("Popped from Stack B: %d\n", popStackB(&stacks));
    displayStacks(stacks);
    free(stacks.array);
    return 0;
}