typedef struct { 
int *arr;        
int size;       
int capacity;    
} MinHeap; 
MinHeap* createHeap(int cap); 
void insert(MinHeap *heap, int value); 
int removeMin(MinHeap *heap); 
void heapifyUp(MinHeap *heap, int index); 
void heapifyDown(MinHeap *heap, int index); 
void destroyHeap(MinHeap *heap); 