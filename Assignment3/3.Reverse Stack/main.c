#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(void)
{
    char inputString[30];
    int choice;
    while (1)
    {
        printf("Choose an option:\n");
        printf("1. Reverse a string\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a string (max 29 characters): ");
            scanf(" %[^\n]s", inputString);
            reverseString(inputString);
            break;
        case 2:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
