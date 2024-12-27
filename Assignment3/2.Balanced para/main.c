#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
    Stack s;
    initialize(&s, 16);
    int choice;
    char character;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Push Character\n");
        printf("2. Validate Parentheses\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a character to push: ");
            scanf(" %c", &character);
            push(&s, character);
            break;
        case 2:
        {
            Stack temp = s;
            int result = validateParentheses(&temp);
            if (result == 1)
            {
                printf("Valid parentheses\n");
            }
            else
            {
                printf("Invalid parentheses\n");
            }
        }
        break;
        case 3:
            display(s);
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeStack(&s);
    return 0;
}