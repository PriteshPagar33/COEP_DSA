typedef struct Array
{
    int totalSize;
    int usedSize;
    int *elements;
} Array;

void initArray(Array *array, int totalSize);
void insertElements(Array *array);
void bubbleSort(Array *array);
void display(Array *array);
