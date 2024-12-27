typedef struct Node
{
    char month[10];
    struct Node *left, *right, *parent;
} Node;
typedef struct BST
{
    Node *root;
} BST;
// Function prototypes
void initBST(BST *tree);
Node *createNode(const char *month);
void insertNode(BST *tree, const char *month);
void removeNode(BST *tree, const char *month);
Node *searchNode(Node *root, const char *month);
void traverseInOrder(Node *node);
Node *findMin(Node *node);
void destroyTree(Node *node);
void menu();
