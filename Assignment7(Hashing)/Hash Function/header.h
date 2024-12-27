typedef struct HashTable {
    int tableSize;
    int* elements;
} HashTable;

void initializeHashTable(HashTable* hashTable, int tableSize);
int calculateHash(int value, int tableSize);
void insertValue(HashTable* hashTable, int value);
void deleteValue(HashTable* hashTable, int value);
void displayHashTable(HashTable* hashTable);
