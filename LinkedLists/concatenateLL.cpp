#include<iostream>
using namespace std;

class linklist{
    private:
    //structure containing 
    struct node{
        int data;
        node *next;
    } * head;

    public:
        linklist();
        void append(int num);
        void concat(linklist &l);
        void display();
        int count();
        ~linklist();
};

//initializes data members
linklist::linklist(){
    head = NULL;
}

//adds a node at the end of a linked list
void linklist::append(int num){
    node *curr;
    curr = head;

    //if the list is empty, create first node
    if(curr == NULL){
        curr = new node;
        head = curr;
    }else{
        //go to last node
        while(curr->next != NULL)
            curr = curr->next;
        //add node at the end
        curr->next = new node;
        curr = curr->next;
    }
    //assign data to the last node
    curr->data = num;
    curr->next = NULL;
}

//concatenates two linked lists
void linklist::concat(linklist &l){
    node *curr;

    //if the first linked list is empty
    if(head == NULL)
        this->head = l.head;
    else{
        //if both linked lists are non-empty
        if(l.head != NULL){
            //points to the starting of the first list
            curr = this->head;
            //traverse the entire first linked list
            while(curr->next != NULL)
                curr = curr->next;

            //concatenates the second list after the first
            curr->next = l.head;
        }
    }
    l.head = NULL;
}

//displays the contest of the linked list
void linklist::display(){
    node *curr = head;
    while(curr!= NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//counts the number of nodes present int the linked list
int linklist::count(){
    int c = 0;
    node *curr = head;

    //traverse the entire linked list
    while(curr != NULL){
        c++;
        curr = curr->next;
    }
    return c;
}

//deallocates memory
linklist::~linklist(){
    node *temp;
    while(head!= NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    linklist l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    cout << "Elements in the 1st linked list: " << endl;
    l1.display();
    cout << "No. of elements in 1st linked list: " << l1.count() << endl;
    linklist l2;
    l2.append(5);
    l2.append(6);
    l2.append(7);
    l2.append(8);
    cout << "Elements in 2nd linked list: " << endl;
    l2.display();
    cout << "No. of elements in 2nd linked list: " << l2.count() << endl;
    //the result obtained after concatenation is in the first list
    l1.concat(l2);
    cout << "Elements in 1st linked list after concatenation: " << endl;
    l1.display();

    return 0;
}