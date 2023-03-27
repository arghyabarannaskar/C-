#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

class btree{
    private:
        Node *root;
        void buildtree(Node **curr, int num);
        void inorder(Node *curr);
        void del(Node *curr);
        void locate(Node *curr, Node **par, Node **x, bool *found, int data);

    public:
        btree();
        void display();
        void insert(int num);
        void remove(int data);
        ~btree();
};

btree::btree(){
    root = NULL;
}

void btree::insert(int num){
    buildtree(&root, num);
}

void btree::buildtree(Node **curr, int num){
    if(*curr == NULL){
        *curr = new Node;
        (*curr)->data = num;
        (*curr)->left = NULL;
        (*curr)->right = NULL;
    }

    if(num<(*curr)->data)
        buildtree(&((*curr)->left), num);

    if(num> (*curr)->data)
        buildtree(&((*curr)->right), num);
}

void btree::display(){
    inorder(root);
}

void btree::inorder(Node *curr){
    if(curr){
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
}

void btree::remove(int data){
    bool found;
    Node *parent, *x, *xsucc;
    locate(root, &parent, &x, &found, data);
    if(!found){
        cout << "value doesn't exist" << endl;
        return;
    }

    if(x->left != NULL && x->right != NULL){
        xsucc = x->right;
        parent = x;
        while(xsucc->left){
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->data = xsucc->data;
        x = xsucc;
    }

    if(x->left == NULL && !x->right){
        if(parent->left == x)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete x;
        return;
    }

    if(x->left && !x->right){
        if(parent->left == x)
            parent->left = x->left;
        else
            parent->right = x->left;
        delete x;
        return;
    }

    if(!x->left && x->right){
        if(parent->left == x)
            parent->left = x->right;
        else
            parent->right = x->right;
        delete x;
        return;
    }
}

void btree::locate(Node *curr, Node **p, Node **x, bool *f, int data){
    *f = false;
    *p = NULL;
    while(curr){
        if(data == curr->data){
            *f = true;
            *x = curr;
            return;
        }
        *p = curr;
        if(data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

btree::~btree(){
    del(root);
}

void btree::del(Node *curr){
    if(curr != NULL){
        del(curr->left);
        del(curr->right);
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