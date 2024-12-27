#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    ArrayADT adt;
    initializeADT(&adt, MAX_CAPACITY);
    int choice, element, position;
    ArrayADT adt2, mergedADT;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Populate Array with Random Elements\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Element\n");
        printf("5. Search Element\n");
        printf("6. Update Element\n");
        printf("7. Find Maximum\n");
        printf("8. Find Minimum\n");
        printf("9. Reverse Array\n");
        printf("10. Sort Array\n");
        printf("11. Append Element\n");
        printf("12. Merge Two Arrays\n");
        printf("13. Release Array Memory\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of elements to populate: ");
            int num_elements;
            scanf("%d", &num_elements);
            populateADT(&adt, num_elements);
            break;
        case 2:
            displayADT(&adt);
            break;
        case 3:
            printf("Enter element to insert and position: ");
            scanf("%d %d", &element, &position);
            insertADT(&adt, element, position);
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteADT(&adt, position);
            break;
        case 5:
            printf("Enter element to search: ");
            scanf("%d", &element);
            position = searchADT(&adt, element);
            if (position != -1)
                printf("Element %d found at position %d\n", element, position);
            else
                printf("Element not found.\n");
            break;
        case 6:
            printf("Enter position and new element: ");
            scanf("%d %d", &position, &element);
            updateADT(&adt, position, element);
            break;
        case 7:
            printf("Maximum Element: %d\n", getMaxADT(&adt));
            break;
        case 8:
            printf("Minimum Element: %d\n", getMinADT(&adt));
            break;
        case 9:
            reverseADT(&adt);
            break;
        case 10:
            sortADT(&adt);
            break;
        case 11:
            printf("Enter element to append: ");
            scanf("%d", &element);
            appendADT(&adt, element);
            break;
        case 12:
            printf("Initializing and populating second array.\n");
            initializeADT(&adt2, 50);
            populateADT(&adt2, adt2.max_size);
            mergedADT = mergeADT(&adt, &adt2);
            printf("Merged Array:\n");
            displayADT(&mergedADT);
            releaseADT(&mergedADT);
            break;
        case 13:
            releaseADT(&adt);
            break;
        case 14:
            printf("Exiting...\n");
            releaseADT(&adt);
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 14);

    return 0;
}