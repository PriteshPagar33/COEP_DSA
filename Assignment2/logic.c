#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void init_ASCII(ASCIIList *list) { 
    list->head = NULL; 
    list->tail = NULL; 
} 
 
 
Node* create_node(int digit) { 
    Node *new_node = (Node *)malloc(sizeof(Node)); 
    if (!new_node) { 
        printf("Memory allocation failed!\n"); 
        exit(1); 
    } 
    new_node->digit = digit; 
    new_node->prev = NULL; 
    new_node->next = NULL; 
    return new_node; 
} 
 
 
void ASCII_of(ASCIIList *list, char character) { 
    int ascii_value = (int)character; 
    int digits[10]; 
    int count = 0; 
 
     
    while (ascii_value > 0) { 
        digits[count++] = ascii_value % 10; 
        ascii_value /= 10; 
    } 
 
     
    for (int i = count - 1; i >= 0; i--) { 
        Node *new_node = create_node(digits[i]); 
        if (list->head == NULL) { 
            list->head = new_node; 
            list->tail = new_node; 
        } else { 
            list->tail->next = new_node; 
            new_node->prev = list->tail; 
            list->tail = new_node; 
        } 
    } 
} 
 
 
void traverse_ASCII(ASCIIList *list) { 
    if (list->head == NULL) { 
        printf("The list is empty.\n"); 
        return; 
    } 
    Node *current = list->head; 
    while (current != NULL) { 
        printf("%d ", current->digit); 
        current = current->next; 
    } 
    printf("\n"); 
} 
 
 
void destroy_ASCII(ASCIIList *list) { 
    Node *current = list->head; 
    while (current != NULL) { 
        Node *temp = current; 
        current = current->next; 
        free(temp); 
    } 
    list->head = NULL; 
    list->tail = NULL; 
    printf("List destroyed.\n"); 
}