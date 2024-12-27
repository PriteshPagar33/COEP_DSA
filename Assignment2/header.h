typedef struct Node { 
int digit; 
struct Node *prev; 
struct Node *next; 
} Node; 
typedef struct { 
Node *head; 
Node *tail; 
} ASCIIList; 
void init_ASCII(ASCIIList *list); 
void ASCII_of(ASCIIList *list, char character); 
void traverse_ASCII(ASCIIList *list); 
void destroy_ASCII(ASCIIList *list); 
Node* create_node(int digit);