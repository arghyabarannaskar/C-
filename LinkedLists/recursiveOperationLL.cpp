#include<iostream>
using namespace std;

class linklist{
    private:
    struct node{
        int data;
        node *next;
    } * head;

    public:
        linklist();
        void add(int num);
        void addatend(node **ptr, int num);
        void display();
        int length();
        int getlength(node *ptr);
        int operator == (linklist & l);
        int compare(node *ptr1, node *ptr2);
        void copy(linklist &l);
        void duplicate(node *ptr1, node **ptr2);
        ~linklist();
};

linklist::linklist(){
    head = NULL;
}
void linklist::add(int num){
    addatend(&head, num);
}

//adds a new node at the end of the linked list
void linklist::addatend(node **ptr, int num){
    if(*ptr == NULL){    //finding the last node and new node is added there
        (*ptr) = new node;
        (*ptr)->data = num;
        (*ptr)->next = NULL;
    }else
        addatend(&((*ptr)->next), num);
}

void linklist::display(){
    node *curr = head;
    //traverse the entire linked list
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int linklist::length(){
    return getlength(head);
}

//counts the number of nodes in a linked list
int linklist::getlength(node *curr){
    int l;
    //if list is empty or if NULL is encountered
    if(curr == NULL)
        return 0;
    else{
        //go to next node
        l = 1 + getlength(curr->next);
        return (l);
    }
}

//calls compare
int linklist::operator == (linklist &l){
    return compare(head, l.head);
}

//compares 2 linked lists and returns 1 if linked lists are equal and 0 if unequal
int linklist:: compare(node *q, node *r){ //takes the address of the head nodes of two linked lists as parameter
    if(q == NULL && r == NULL) //if data of all previous node are equal after the last node control reaches here
        return 1;       //both are empty linked lists and therefore equal
    else{
        if (q == NULL || r == NULL)      //the previous condition didn't satisfy so both are not null, so now checking if one of them is null
            return 0;      //both are not null but one of them is ...therefore not equal
        else if(q->data != r->data)    //none of them are empty that's why control reached here
            return 0;                  //if the data of the current nodes are not equal means linked lists are not equal
        else
            return compare(q->next, r->next);  //else compare the next nodes
    }
}

//calls to copy to copy a linked list into another
void linklist::copy(linklist &l){
    duplicate(l.head, head);
}

//copies a linked list into another
void linklist::duplicate(node *ptr1, node *ptr2){ //copying ptr1 into ptr2
    if(ptr1 != NULL){
        ptr2 = new node;
        ptr2->data = ptr1->data;
        ptr2->next = NULL;
        duplicate(ptr1->next, ptr2->next);
    }
}

//deallocates memory
linklist::~linklist(){
    node *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    linklist l1;
    l1.add(1);
    l1.add(2);
    l1.add(3);
    l1.add(4);
    l1.display();
    cout << "Length of linked list: " << l1.length() << endl;

    // linklist l2;
    // l2.add(1);
    // l2.add(2);
    // l2.add(3);
    // l2.display();
    // if (l1 == l2)
    //     cout << "both linked list are equal" << endl;
    // else
    //     cout << "both linked lists are different" << endl;

    // linklist l3;
    // l3.copy(l1);
    // l3.display();

    return 0;
}