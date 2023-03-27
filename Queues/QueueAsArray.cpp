#include<iostream>
using namespace std;
const int MAX = 10;

class queue{
    private:
        int arr[MAX];
        int front, rear;
    public:
        queue();
        void enQ(int item);
        int deQ();
};

//initializes data members
queue::queue(){
    front = -1;
    rear = -1;
}

//adds an element to the queue
void queue::enQ(int item){
    if(rear == MAX - 1){
        cout << "Queue is full" << endl;
        return;
    }

    rear++;
    arr[rear] = item;

    if(front == -1)
        front = 0;
}

//removes an element from the queue
int queue::deQ(){
    int data;

    if(front==-1){
        cout << "Queue is empty" << endl;
        return NULL;
    }
    data = arr[front];
    arr[front] = 0;
    if(front == rear)
        front = rear = -1;
    else 
       front++;
    return data;
}

int main(){
    queue q;
    q.enQ(34);

    return 0;
}