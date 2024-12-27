#include <stdio.h> 
#include <stdlib.h> 
#include "header.h"

void initialize(TwoStack *s, int sizeA, int sizeB) { 
int totalSize = sizeA + sizeB; 
s->sizeA = sizeA; 
s->sizeB = sizeB; 
s->topA = -1;               
s->topB = sizeA;           
 
    s->array = (int *)malloc(totalSize * sizeof(int));  
} 
 
 
void pushStackA(TwoStack *s, int value) { 
    if (s->topA + 1 < s->sizeA) {  
        s->array[++s->topA] = value;  
    } else { 
        printf("Stack A Overflow!\n"); 
    } 
} 
 
 
void pushStackB(TwoStack *s, int value) { 
    if (s->topB < (s->sizeA + s->sizeB - 1)) {  
        s->array[++s->topB] = value;  
    } else { 
        printf("Stack B Overflow!\n"); 
    } 
} 
 
 
int popStackA(TwoStack *s) { 
    if (s->topA >= 0) {  
        return s->array[s->topA--];  
    } else { 
        printf("Stack A Underflow!\n"); 
        return -1;  
    } 
} 
 
 
int popStackB(TwoStack *s) { 
    if (s->topB >= s->sizeA) {  
        return s->array[s->topB--];  
    } else { 
        printf("Stack B Underflow!\n"); 
        return -1;  
    } 
} 
 
 
void displayStacks(TwoStack s) { 
    printf("Stack A: "); 
    for (int i = s.topA; i >= 0; i--) { 
        printf("%d\t", s.array[i]);  
    } 
    printf("\n"); 
 
    printf("Stack B: "); 
    for (int i = s.topB; i >= s.sizeA; i--) { 
        printf("%d\t", s.array[i]);  
    } 
    printf("\n"); 
} 