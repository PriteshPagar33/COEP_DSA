#include "header.h"

int main() {
    HashTable hashTable;
    initializeHashTable(&hashTable, 10);

    insertValue(&hashTable, 88);
    insertValue(&hashTable, 99);
    insertValue(&hashTable, 55);
    insertValue(&hashTable, 12);

    displayHashTable(&hashTable);

    deleteValue(&hashTable, 55);
    displayHashTable(&hashTable);

    return 0;
}
