#include<iostream>
using namespace std;

class linkedList{
    private:
    struct node{
        int data;
        node *next;
    } * head;

    public:
        linkedList();
        void addatbeg(int data);
        void reverse();
        void display();
        ~linkedList();
};

linkedList::linkedList(){
    head = NULL;
}

void linkedList::addatbeg(int data){
    node *temp;
    temp = new node;
    temp->data = data;
    temp->next = head;
    head = temp;
}

void linkedList::reverse(){
    node *prev , *curr, *next;
    prev = NULL;
    curr = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void linkedList::display(){
    node *curr;
    curr = head;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

linkedList:: ~linkedList(){
    node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    linkedList L;
    L.addatbeg(1);    
    L.addatbeg(2);    
    L.addatbeg(3);    
    L.addatbeg(4);    
    L.addatbeg(5);
    L.display();
    L.reverse();
    L.display();

    return 0;
}