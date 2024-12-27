#include "header.h"

int main() {
    // Linear probing
    // HashTable hashTableLinear;
    // initializeHashTable(&hashTableLinear, 10);
    // insertWithLinearProbing(&hashTableLinear, 15);
    // insertWithLinearProbing(&hashTableLinear, 20);
    // insertWithLinearProbing(&hashTableLinear, 25);
    // insertWithLinearProbing(&hashTableLinear, 22);
    // insertWithLinearProbing(&hashTableLinear, 12);
    // insertWithLinearProbing(&hashTableLinear, 122);
    // insertWithLinearProbing(&hashTableLinear, 92);
    // displayHashTable(&hashTableLinear);
    // deleteWithLinearProbing(&hashTableLinear, 122);
    // displayHashTable(&hashTableLinear);

    // Quadratic probing
    HashTable hashTableQuadratic;
    initializeHashTable(&hashTableQuadratic, 10);
    insertWithQuadraticProbing(&hashTableQuadratic, 15);
    insertWithQuadraticProbing(&hashTableQuadratic, 20);
    insertWithQuadraticProbing(&hashTableQuadratic, 25);
    insertWithQuadraticProbing(&hashTableQuadratic, 22);
    insertWithQuadraticProbing(&hashTableQuadratic, 12);
    insertWithQuadraticProbing(&hashTableQuadratic, 122);
    insertWithQuadraticProbing(&hashTableQuadratic, 92);
    displayHashTable(&hashTableQuadratic);
    deleteWithQuadraticProbing(&hashTableQuadratic, 20);
    displayHashTable(&hashTableQuadratic);

    return 0;
}
