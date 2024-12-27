typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct HashTable {
    int size;
    Node* buckets;
} HashTable;

void initializeHashTable(HashTable* hashTable, int capacity);
int hashFunction(int value, int capacity);
void insertValue(HashTable* hashTable, int value);
void deleteValue(HashTable* hashTable, int value);
void displayHashTable(HashTable* hashTable);
