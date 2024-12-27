#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() { 
ASCIIList list1; 
init_ASCII(&list1); 
 
    int choice; 
    char character; 
 
    do { 
        printf("\n--- ASCII Linked List Menu ---\n"); 
        printf("1. Create ASCII Linked List\n"); 
        printf("2. Traverse the List\n"); 
        printf("3. Destroy the List\n"); 
        printf("4. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter a character: "); 
                scanf(" %c", &character);  
                ASCII_of(&list1, character); 
                break; 
            case 2: 
                traverse_ASCII(&list1); 
                break; 
            case 3: 
                destroy_ASCII(&list1); 
                break; 
            case 4: 
                printf("Exiting...\n"); 
                destroy_ASCII(&list1); 
                break; 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } while (choice != 4); 
 
    return 0; 
} 