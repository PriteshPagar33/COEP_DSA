typedef struct HashTable {
    int capacity;
    int* elements;
} HashTable;

void initializeHashTable(HashTable* hashTable, int tableSize);
int computeHash(int value, int tableSize);
void insertWithLinearProbing(HashTable* hashTable, int value);
void deleteWithLinearProbing(HashTable* hashTable, int value);
void insertWithQuadraticProbing(HashTable* hashTable, int value);
void deleteWithQuadraticProbing(HashTable* hashTable, int value);
void displayHashTable(HashTable* hashTable);
