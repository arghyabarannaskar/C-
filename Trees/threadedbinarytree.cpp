#include<iostream>
using namespace std;

class ttree{
    private:
    struct Node{
        bool left;
        Node *leftchild;
        int data;
        Node *rightchild;
        bool right;
    } * th_head;

    public:
        ttree();
        void insert(int num);
        void inorder();
};

//initialises data member
ttree::ttree(){
    th_head = NULL;
}

//inserts a node in a threaded binary tree
void ttree::insert(int num){
    Node *head = th_head, *curr, *z;
    //allocating a new node
    z = new Node;
    z->left = true; //indicates a thread
    z->data = num; //assign new data
    z->right = true; //indicates a thread

    //if tree is empty
    if(th_head == NULL){
        head = new Node;

        //entire tree is treated as left sub-tree of head node
        head->left = false;

        head->leftchild = z;//z becomes leftchild of the head node
        head->data = -9999; // no data
        head->rightchild = head; //right link points to head node
        head->right = false;

        th_head = head;
        z->leftchild = head;
        z->rightchild = head;
    }
    else { //if tree is non-empty
        curr = head->leftchild;

        //traverse till we reach head
        while(curr != head){
            if(num < curr->data){
                //check for a thread
                if(curr->left != true)
                    curr = curr->leftchild;
                else{
                    z->leftchild = curr->leftchild;
                    curr->leftchild = z;
                    curr->left = false;
                    z->right = true;
                    z->rightchild = curr;
                    return;
                }
            }else{
                if(curr->data<num){
                    if(curr->right != true)
                        curr = curr->rightchild;
                    else{
                        z->rightchild = curr->rightchild;
                        curr->rightchild = z;
                        curr->right = false;
                        z->left = true;
                        z->leftchild = curr;
                        return;
                    }
                }
            }
        }
    }
}


//traverse the threaded binary tree in in-order

void ttree::inorder(){
    Node *p;
    p = th_head->leftchild;

    while(p != th_head){
        while(p->left == false)
            p = p->leftchild;

        cout << p->data << "\t";

        while(p->right == true){
            p = p->rightchild;
            if(p == th_head)
                break;

            cout << p->data << "\t";
        }
        p = p->rightchild;
    }
}

int main(){
    ttree th;
    th.insert(21);
    th.insert(54);
    th.insert(1);
    th.insert(1213);
    th.insert(574);
    th.insert(24);
    th.insert(465);
    th.insert(15);

    cout << "Threaded binary tree: " << endl;
    th.inorder();

    return 0;
}