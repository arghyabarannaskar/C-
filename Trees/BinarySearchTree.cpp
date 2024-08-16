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
        void locate(Node *curr, Node **par, Node **x, bool *found, int num);

    public:
        btree();
        void insert(int num);
        void display();
        void remove(int num);
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
        (*curr)->left = NULL;
        (*curr)->data = num;
        (*curr)->right = NULL;
    }else{
        if(num < (*curr)->data){
            buildtree(&((*curr)->left), num);
        }else{
            buildtree(&((*curr)->right), num);
        }
    }
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

void btree::remove(int num){
    bool found = false;
    Node *parent = NULL, *x = NULL, *xsucc;
    locate(root, &parent, &x, &found, num);

    if(x->left && x->right){
        parent = x;
        xsucc = x->right;
        while(xsucc->left){
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->data = xsucc->data;
        x = xsucc;
    }

    if(x->left == NULL && x->right == NULL){
        if(parent->left == x){
            parent->left = NULL;
        }else{
            parent->right = NULL;
        }
        delete x;
        return;
    }

    if(x->left == NULL && x->right != NULL){
        if(parent->left == x){
            parent->left = x->right;
        }else{
            parent->right = x->right;
        }

        delete x;
        return;
    }

    if(x->left != NULL && x->right == NULL){
        if(parent->left == x){
            parent->left = x->left;
        }else{
            parent->right = x->left;
        }
        delete x;
        return;
    }
}

void btree::locate(Node *root, Node **par, Node **x, bool *found, int num){
    Node *curr = root;
    while(curr){
        if(curr->data == num){
            *x = curr;
            *found = true;
            return;
        }
        *par = curr;
        if(num< curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

btree::~btree(){
    del(root);
}

void btree::del(Node *curr){
    if(curr){
        del(curr->left);
        del(curr->right);
        delete curr;
    }
}

int main(){
    btree bt;
    bt.insert(20);
    bt.insert(15);
    bt.insert(25);
    bt.insert(10);
    bt.insert(30);
    bt.insert(20);

    bt.display();
    cout << endl;
    bt.remove(25);
    bt.remove(20);
    bt.display();

    return 0;
}