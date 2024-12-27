#include "header.h"

int main() {
    HashTable hashTable;
    initializeHashTable(&hashTable, 10);

    insertValue(&hashTable, 99);
    insertValue(&hashTable, 22);
    insertValue(&hashTable, 33);
    insertValue(&hashTable, 44);
    insertValue(&hashTable, 88);
    insertValue(&hashTable, 55);

    displayHashTable(&hashTable);

    deleteValue(&hashTable, 22);
    deleteValue(&hashTable, 88);

    displayHashTable(&hashTable);

    return 0;
}
