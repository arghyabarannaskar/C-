#include<iostream>
using namespace std;

class linklist{
    private:
    struct dnode{
        dnode *prev;
        int data;
        dnode *next;
    } * head;

    public:
        linklist();
        void d_append(int num);
        void d_addatbeg(int num);
        void d_addafter(int loc, int num);
        void d_dispay();
        int d_count();
        void d_delete(int i);
        ~linklist();
};

linklist::linklist(){ //initializes data member
    head = NULL;
}

//adds a new node at the end of the doubly linked list
void linklist::d_append(int num){
    dnode *temp, *curr;
    curr = head;
    temp = new dnode;
    temp->prev = NULL;
    temp->data = num;
    temp->next = NULL;
    if(head == NULL)
        head = temp;
    else{
        while(curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
        temp->prev = curr;
    }
}

//adds a new node at the beginning of the linked list
void linklist::d_addatbeg(int num){
    dnode *temp;
    temp = new dnode;
    temp->data = num;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

//adds a new node after the specified number of nodes
void linklist::d_addafter(int loc, int num){
    dnode *curr, *temp;
    curr = head;
    for (int i = 1; i < loc;i++){
        curr = curr->next;
        if(curr == NULL){
            cout << "There are less than " << loc << " elements" << endl;
            return;
        }
    }

    temp = new dnode;
    temp->data = num;
    if(curr->next == NULL){ //in case curr->next is NULL there will be no curr->next->prev so...
        temp->next = NULL;
        temp->prev = curr;
        curr->next = temp;
        return;
    }
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = temp;
    temp->prev = curr;
}

//displays the contents of the linked list
void linklist::d_dispay(){
    dnode *curr = head;
    //traverse the entire linked list
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

//counts the number of nodes present in the linked list
int linklist::d_count(){
    int count = 0;
    dnode *curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }

    return count;
}

//deletes the specified node from the doubly linked list
void linklist::d_delete(int num){
    dnode *curr = head;
    while(curr!= NULL){
        if(curr->data == num){
            if (curr == head){
                head = head->next;
                head->prev = NULL;
            }
            else{
                if(curr->next == NULL)
                    curr->prev->next = NULL;
                else{
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
            }
            delete curr;
            return;
        }
        curr = curr->next;
    }
    cout << num << " not found" << endl;
}

//deallocates memory
linklist::~linklist(){
    dnode *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        delete head;
    }
}

int main(){

    linklist l;
    l.d_append(11);
    l.d_append(2);
    l.d_append(174);
    l.d_append(99);
    l.d_append(12);
    l.d_dispay();

    cout << "No. of elements: " << l.d_count() << endl;
    l.d_addatbeg(33);
    cout << "Elements in DLL after addition at the beginning: ";
    l.d_dispay();
    cout << "No. of elements: " << l.d_count() << endl;
    l.d_addafter(4, 66);
    cout << "Elements in DLL after addition at given position: " << endl;
    l.d_dispay();
    cout << "No. of elements: " << l.d_count() << endl;
    l.d_delete(174);
    cout << "Elements in DLL after deletion: " << endl;
    l.d_dispay();
    l.d_addafter(6, 26);
    cout << "Elements in DLL after addition at given position: " << endl;
    l.d_dispay();

    return 0;
}