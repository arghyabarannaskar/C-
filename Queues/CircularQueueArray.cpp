#include<iostream>
using namespace std;
const int MAX = 8;

class queue{
    private:
        int arr[MAX];
        int front, rear;
    
    public:
        queue();
        void enQ(int item);
        int deQ();
        void display();
};

//initializes data member
queue::queue(){
    front = rear = -1;
    for (int i = 0; i < MAX;i++)
        arr[i] = 0;
}

//adds an element to the queue
void queue::enQ(int item){
    if((rear == MAX - 1 && front == 0) || (rear + 1 == front)){
        cout << "Queue is full" << endl;
        return;
    }

    if(rear == MAX - 1)
        rear = 0;
    else
        rear++;
    arr[rear] = item;

    if(front == -1)
        front = 0;
}

//removes an element from the queue
int queue::deQ(){
    int data;

    if(front == -1){
        cout << "Queue is empty" << endl;
        return NULL;
    }

    data = arr[front];
    arr[front] = 0;
    
    if(front == rear){    //implies this is the last element in the queue. after popping it queue will be empty
        front = rear = -1;
    }
    else{
        if(front == MAX-1)
            front = 0;
        else
            front++;
    }
    return data;
}

//displays element in a queue
void queue::display(){
    for (int i = 0; i < MAX;i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){

    return 0;
}