#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main()
{
    BST tree;
    initBST(&tree);

    int choice;
    char month[10];

    do
    {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            initBST(&tree);
            printf("Tree initialized.\n");
            break;
        case 2:
            printf("Enter month to insert: ");
            scanf("%s", month);
            insertNode(&tree, month);
            break;
        case 3:
            printf("Enter month to remove: ");
            scanf("%s", month);
            removeNode(&tree, month);
            break;
        case 4:
            printf("In-order traversal: ");
            traverseInOrder(tree.root);
            printf("\n");
            break;
        case 5:
            destroyTree(tree.root);
            tree.root = NULL;
            printf("Tree destroyed.\n");
            break;
        case 6:
            printf("Exiting program.\n");
            destroyTree(tree.root);
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
