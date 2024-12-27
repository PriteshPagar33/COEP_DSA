#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void initBST(BST *tree)
{
    tree->root = NULL;
}
Node *createNode(const char *month)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        strcpy(newNode->month, month);
        newNode->left = newNode->right = newNode->parent = NULL;
    }
    return newNode;
}

void insertNode(BST *tree, const char *month)
{
    Node *newNode = createNode(month);
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        return;
    }

    if (tree->root == NULL)
    {
        tree->root = newNode;
        printf("Inserted root node: %s\n", month);
        return;
    }

    Node *parent = NULL, *current = tree->root;
    while (current != NULL)
    {
        parent = current;
        if (strcmp(month, current->month) < 0)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;
    if (strcmp(month, parent->month) < 0)
        parent->left = newNode;
    else
        parent->right = newNode;

    printf("Inserted node: %s\n", month);
}

void removeNode(BST *tree, const char *month)
{
    Node *nodeToDelete = searchNode(tree->root, month);
    if (nodeToDelete == NULL)
    {
        printf("Node not found: %s\n", month);
        return;
    }

    if (nodeToDelete->left == NULL || nodeToDelete->right == NULL)
    {
        Node *child = (nodeToDelete->left) ? nodeToDelete->left : nodeToDelete->right;

        if (nodeToDelete->parent == NULL)
        {
            tree->root = child;
        }
        else if (nodeToDelete == nodeToDelete->parent->left)
        {
            nodeToDelete->parent->left = child;
        }
        else
        {
            nodeToDelete->parent->right = child;
        }

        if (child != NULL)
            child->parent = nodeToDelete->parent;
        free(nodeToDelete);
        printf("Node removed: %s\n", month);
    }
    else
    {
        Node *successor = findMin(nodeToDelete->right);
        strcpy(nodeToDelete->month, successor->month);
        removeNode(tree, successor->month);
    }
}

Node *searchNode(Node *root, const char *month)
{
    while (root != NULL && strcmp(root->month, month) != 0)
    {
        if (strcmp(month, root->month) < 0)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

Node *findMin(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
void traverseInOrder(Node *root)
{
    if (root != NULL)
    {
        traverseInOrder(root->left);
        printf("%s ", root->month);
        traverseInOrder(root->right);
    }
}
void destroyTree(Node *node)
{
    if (node == NULL)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    free(node);
}
void menu()
{
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Initialize Tree\n");
    printf("2. Insert Node\n");
    printf("3. Remove Node\n");
    printf("4. Display Tree (In-Order Traversal)\n");
    printf("5. Destroy Tree\n");
    printf("6. Exit\n");
}