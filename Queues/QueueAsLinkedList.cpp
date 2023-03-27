#include<iostream>
using namespace std;

class queue{
    private:
    struct node{
        int data;
        node *next;
    } * front, *rear;

    public:
        queue();
        void enQ(int item);
        int deQ();
        ~queue();
};

//initialises data member
queue::queue(){
    front = rear = NULL;
}

//adds an element to the queue
void queue::enQ(int item){
    node *temp = new node;

    if(temp == NULL){
        cout << "Queue is full" << endl;
        return;
    }

    temp->data = item;
    temp->next = NULL;

    if(front == NULL){
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp;
}

//removes an element from the queue
int queue::deQ(){
    if(front == NULL){
        cout << "Queue is empty" << endl;
        return;
    }

    node *temp = new node;
    int data;
    data = front->data;
    temp = front;
    front = front->next;
    delete temp;
    return data;
}

//deallocates memory
queue::~queue(){
    if(front == NULL)
        return;
    node *temp;
    while(front != NULL){
        temp = front;
        front = front->next;
        delete temp;
    }
}

int main(){
    queue q;
    q.enQ(5);
    q.enQ(7);

    return 0;
}