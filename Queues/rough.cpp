#include<iostream>
using namespace std;
 
struct Node{
    int data;
    Node *leftchild;
    Node *rightchild;
};

class btree{
    private:
        Node *root;
        void buildtree(Node **curr, int data);
        void inorder(Node *curr);
        void postorder(Node *curr);
        void del(Node *curr);
        void locate(Node *curr, Node **par, Node **x, bool *found, int num);

    public:
        btree();
        void insert(int data);
        void display();
        void porder();
        void remove(int num);
        ~btree();
};

btree::btree(){
    root = NULL;
}

void btree::insert(int data){
    buildtree(&root, data);
}

void btree::buildtree(Node **curr, int data){
    if(*curr == NULL){
        (*curr) = new Node;
        (*curr)->data = data;
        (*curr)->leftchild = NULL;
        (*curr)->rightchild = NULL;
    }else if(data <= (*curr)->data){
        buildtree(&((*curr)->leftchild), data);
    }else{
        buildtree(&((*curr)->rightchild), data);
    }
}

void btree::display(){
    inorder(root);
}

void btree::inorder(Node *curr){
    if(curr != NULL){
        inorder(curr->leftchild);
        cout << curr->data << " ";
        inorder(curr->rightchild);
    }
}

void btree::porder(){
    postorder(root);
}

void btree::postorder(Node *curr){
    if(curr != NULL){
        postorder(curr->leftchild);
        postorder(curr->rightchild);
        cout << curr->data << " ";
    }
}

void btree::remove(int num){
    bool found;
    Node *parent, *x, *xsucc;
    locate(root, &parent, &x, &found, num);
    if(!found){
        cout << "Node doesn't exist"<<endl;
        return;
    }
    if(x->leftchild != NULL && x->rightchild != NULL){
        xsucc = x->rightchild;
        parent = x;
        while(xsucc->leftchild != NULL){
            parent = xsucc;
            xsucc = xsucc->leftchild;
        }
        x->data = xsucc->data;
        x = xsucc;
    }

    if(x->leftchild == NULL && x->rightchild == NULL){
        if(parent->leftchild == x)
            parent->leftchild = NULL;
        else
            parent->rightchild = NULL;
        delete x;
        return;
    }

    if(x->leftchild != NULL && x->rightchild == NULL){
        if(parent->leftchild == x)
            parent->leftchild = x->leftchild;
        else
            parent->rightchild = x->leftchild;
        delete x;
        return;
    }

    if(x->leftchild == NULL && x->rightchild != NULL){
        if(parent->leftchild == x)
            parent->leftchild = x->rightchild;
        else
            parent->leftchild = x->rightchild;
        delete x;
        return;
    }
}

void btree::locate(Node *curr, Node **par, Node **x, bool *found, int num){
    *found = false;
    while(curr != NULL){
        if(curr->data == num){
            *x = curr;
            *found = true;
            return;
        }

        *par = curr;
        if(num< curr->data)
            curr = curr->leftchild;
        else
            curr = curr->rightchild;
    }
}

btree::~btree(){
    del(root);
}

void btree::del(Node *curr){
    if(curr != NULL){
        del(curr->leftchild);
        del(curr->rightchild);
        delete curr;
    }
}

int main(){
    btree bt;
    bt.insert(20);
    bt.insert(15);
    bt.insert(10);
    bt.insert(25);
    bt.insert(30);

    bt.display();

    bt.remove(15);
    cout << endl;
    bt.display();

    return 0;
}