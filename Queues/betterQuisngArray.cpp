#include<iostream>
using namespace std;

class queue{
    public:
        int *arr;
        int size, front, rear;
        unsigned cap;   //cap is the upper limit
};

queue * createQueue(unsigned cap){  
    queue *q = new queue();
    q->cap = cap;
    q->front = q->size = 0;

    q->rear = cap - 1;
    q->arr = new int[(q->cap * sizeof(int))];
    return q;
}

int isFull(queue *q){
    return (q->size == q->cap);
}

int isEmpty(queue *q){
    return (q->size == 0);
}

void enqueue(queue *q, int item){
    if(isFull(q))
        return;
    q->rear = (q->rear + 1) % q->cap;
    q->arr[q->rear] = item;
    q->size = q->size + 1;
    cout << item << " enqueued to queue" << endl;
}

int dequeue(queue *q){
    if(isEmpty(q))
        return INT_MIN;
    int item = q->arr[q->front];
    q->front = (q->front + 1)% q->cap;
    q->size = q->size - 1;
    return item;
}

int front(queue *q){
    if(isEmpty(q))
        return INT_MIN;
    return q->arr[q->front];
}

int rear(queue *q){
    if(isEmpty(q))
        return INT_MIN;
    return q->arr[q->rear];
}

void deleteQueue(queue *q){
    delete q->arr;
    delete q;
}

int main(){
    queue *q = createQueue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    cout << dequeue(q) << " dequeued from queue" << endl;
    cout << "front: " << front(q) << endl;
    cout << "rear: " << rear(q) << endl;

    deleteQueue(q);
    return 0;
}