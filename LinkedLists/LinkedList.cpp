#include<iostream>
using namespace std;

class linkedlist{
    private:
    //structure containing data part and link part
    struct node{
        int data;
        node *next;
    } * head; // p is head;

    public:
        linkedlist();
        void append(int num);
        void addatbeg(int num);
        void addafter(int loc, int num);
        void addAt(int num, int pos);
        void reverse();
        void display();
        int count();
        void del(int num);
        void sortascending();
        ~linkedlist();
};

//initializes data member
linkedlist::linkedlist(){
    head = NULL;
}

//adds a node at the end of a linked list
void linkedlist::append(int num){
    node *temp, *curr;
    temp = new node;
    temp->data = num;
    temp->next = NULL;

    //if the list is empty, create first node
    if(head == NULL){
        head = temp;
    }
    else{
        //go to last node
        curr = head;
        while(curr->next != NULL)
            curr = curr->next;

        //add node at the end
        curr->next = temp;
    }
}

//adds a new node at the beginning of the linked list 
void linkedlist::addatbeg(int num){
    node *temp = new node;
    temp->data = num;
    temp->next = head;
    head = temp;
}

//adds a new node after the specified number of nodes
void linkedlist::addafter(int loc, int num){
    node *temp, *curr;
    curr = head;
    
    //skip to desired portion
    for (int i = 1; i < loc ;i++){ //i denotes the node we are entering
        curr = curr->next;         // if we entered 1, curr is now curr->next i.e. curr is pointing to 2...if entered 2 curr is not pointing 3
                                //when i is equal to loc, it would not enter the loop anymore and curr is pointing to desired location
        // if end of linked list is encountered
        if(curr == NULL){
            cout << "\nthere are less than " << loc << " elements in list" << endl; //first checking if node exists at position
            return;
        }
    }//at the end of the loop curr will point to the node after which we wish to add new node//and it is null or not is checked at the last iteration of the loop

    //insert new node
    temp = new node;    //memory allocation later...first check if value exists at given position...if not then 
                        //unnecessary memory allocation
    temp->data = num;
    temp->next = curr->next;
    curr->next = temp;
}


//displays the contents of the linked list
void linkedlist::display(){
    node *curr = head;
    //traverse the entire linked list
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//counts the number of nodes present in a linked list
int linkedlist::count(){
    int c = 0;
    node *curr = head;
    while(curr != NULL){
        c++;
        curr = curr->next;
    }
    return c;
}

//deletes the specified node from the linked list
void linkedlist::del(int num){
    node *prev, *curr;
    curr = head;
    while(curr != NULL){
        if(curr->data == num){
            //if node to be deleted is the first node in the linked list
            if(curr == head)
                head = curr->next;

            //delete the intermediate nodes in the linked list
            else
                prev->next = curr->next;
            
            //free the memory occupied by the node
            delete curr; //this line is common for if and else
            return;
        }
        //traverse the linked list till the last node is reached

            //old points to the previous node
            prev = curr;                              //FIRST HERE IF node to be deleted is not the head node
            //go to the next node
            curr = curr->next;

    }
        cout << "Element " << num << " not found" << endl;
}

void linkedlist::reverse(){
    node *prev = NULL, *curr, *next;
    curr = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

//sorts a linked list in ascending order
void linkedlist::sortascending(){  //My own logic
    node *curr, *nextNode;
    int temp;
    curr = head;
    while(curr->next != nullptr){
        nextNode = curr->next;
        while(nextNode != NULL){
            if(curr->data > nextNode->data){
                temp = curr->data;
                curr->data = nextNode->data;
                nextNode->data = temp;
            }
            nextNode = nextNode->next;
        }
        curr = curr->next;
    }
}

//deallocates memory
linkedlist::~linkedlist(){
    node *q;
    while(head != NULL){
        q = head->next;
        delete head;
        head = q;
    }
}

int main(){
    linkedlist L;
    L.append(13);
    L.append(45);
    L.append(86);
    L.append(47);
    L.append(56);
    cout << "Linked list after appending: " << endl;
    L.display();
    L.del(86);
    L.display();
    L.reverse();
    L.display();
    L.sortascending();
    L.display();

    return 0;
}