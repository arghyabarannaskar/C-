#include<iostream>
using namespace std;

class stack{
    private:
    struct node{
        int data;
        node *next;
    } * top;

    public:
        stack();
        void push(int item);
        int pop();
        ~stack();
};

//initializes data member
stack::stack(){
    top = NULL;
}

//adds a new node to the stack as linked list
void stack::push(int item){
    node *temp = new node;
    if(temp == NULL)
        cout << "Stack is full" << endl;
    temp->data = item;
    temp->next = top;
    top = temp;
}

//pops an element from the stack
int stack::pop(){
    if(top == NULL){
        cout << "Stack is empty" << endl;
        return NULL;
    }

    node *temp = top;
    int data = top->data;
    top = top->next;

    delete temp;
    return data;
}

//deallocates memory
stack::~stack(){
    if(top == NULL)
        return;
    node *temp;
    while(top != NULL){
        temp = top;
        top = top->next;
        delete temp;
    }
}

int main(){
    stack s;
    s.push(5);

    return 0;
}