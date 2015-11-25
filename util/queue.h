struct qnode {
        int data;
        struct qnode *next;
};

struct queue{
        struct qnode *front,*rear;
};


struct queue *create_queue(void);
void enqueue(struct queue *q,int data);
struct qnode *dequeue(struct queue *q);


