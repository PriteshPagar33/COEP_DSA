typedef struct Record
{
    char name[16];
    unsigned int age;
} Record;
typedef struct Node
{
    Record data;
    struct Node *next;
} Node;
typedef struct CircularQueue
{
    Node *front;
    Node *rear;
} CircularQueue;
void initializeQueue(CircularQueue *queue);
void enqueue(CircularQueue *queue, Record data);
int isQueueFull(CircularQueue *queue);
int isQueueEmpty(CircularQueue *queue);
Record dequeue(CircularQueue *queue);
void displayQueue(CircularQueue queue);