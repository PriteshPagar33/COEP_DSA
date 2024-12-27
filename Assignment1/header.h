typedef struct
{
    int *data;
    int max_size;
    int current_size;
} ArrayADT;
#define MAX_CAPACITY 100

void initializeADT(ArrayADT *adt, int size);
void populateADT(ArrayADT *adt, int num_elements);
void displayADT(ArrayADT *adt);
void insertADT(ArrayADT *adt, int element, int position);
void deleteADT(ArrayADT *adt, int position);
int searchADT(ArrayADT *adt, int element);
void updateADT(ArrayADT *adt, int position, int new_element);
int getMaxADT(ArrayADT *adt);
int getMinADT(ArrayADT *adt);
void reverseADT(ArrayADT *adt);
void sortADT(ArrayADT *adt);
void appendADT(ArrayADT *adt, int element);
ArrayADT mergeADT(ArrayADT *adt1, ArrayADT *adt2);
void releaseADT(ArrayADT *adt);