#include<iostream>
using namespace std;
const int MAX = 10;

class stack{
    private:
        int arr[MAX];
        int top;
    public:
        stack();
        void push(int item);
        int pop();
};

//initialises data member
stack::stack(){
    top = -1;
}

//adds an element to the stack
void stack::push(int item){
    if(top == MAX - 1){
        cout << "Stack is full" << endl;
        return;
    }
    top++;
    arr[top] = item;
}

//extracts an element from the stack
int stack::pop(){
    if(top == -1){
        cout << "Stack is empty" << endl;
        return NULL;
    }
    int del = arr[top--];
    return del;
}

int main(){
    stack s;
    s.push(2);

    return 0;
}