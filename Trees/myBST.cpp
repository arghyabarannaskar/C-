#include<iostream>
using namespace std;

struct Node {
    Node* left;
    int data;
    Node* right;
};

class btree {
private:
    Node* root;

    void buildtree(Node** curr, int num);
    void inorder(Node* curr);
    void del(Node* curr);
    void rem(Node *curr, int num);
    void locate(Node *curr, Node **parent, Node **x, bool* found, int num);

public:
    btree();
    void insert(int num);
    void remove(int num);
    void display();
    void search(int num);
    ~btree();
};

btree::btree() {
    root = NULL;
}

void btree::insert(int num) {
    buildtree(&root, num);
}

void btree::buildtree(Node** curr, int num) {
    if (*curr == NULL) {
        (*curr) = new Node;
        (*curr)->data = num;
        (*curr)->left = NULL;
        (*curr)->right = NULL;
    }
    else {
        if (num < ((*curr)->data))
            buildtree(&((*curr)->left), num);
        else
            buildtree(&((*curr)->right), num);
    }
}

void btree::display() {
    inorder(root);
}

void btree::inorder(Node* curr) {
    if (curr != NULL) {
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
}

void btree::search(int num){
    Node *curr = root;
    bool found = false;
    while(curr != NULL){
        if(num == curr->data){
            found = true;
            break;
        }
        else if(num<curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if(found)
        cout << "Data found..." << endl;
    else
        cout << "Data not found..." << endl;
}

btree::~btree() {
    del(root);
}

void btree::del(Node* curr) {
    if (curr != NULL) {
        del(curr->left);
        del(curr->right);
    }
    delete curr;
}

void btree::remove(int num){
    cout << endl
         << "root = " << root << endl;
    Node *curr = root, *parent = NULL, *x = NULL, *xsucc;
    bool found;
    locate(curr, &parent, &x, &found, num);
    cout << endl
         << "root = " << root << endl;

    if(!found){
        cout << "Data not found!" << endl;
        return;
    }else{
        cout << "Data = "<<num<<"found and ready to be deleted..." << endl<<" x = "<<x<<" x->data = "<<x->data;
    }

    if(x->left != NULL && x->right !=NULL){
        xsucc = x->right;
        while(xsucc->left != NULL){
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->data = xsucc->data;
        x = xsucc;
    }

    if(x->left == NULL && x->right == NULL){
        if(parent->left == x)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete x;
        cout << endl
         << "root = " << root << endl;
        return;
    }

    if(x->left == NULL && x->right != NULL){
        if(parent->left == x)
            parent->left = x->right;
        else
            parent->right = x->right;
        delete x;
        return;
    }

    if(x->left != NULL && x->right == NULL){
        if(parent->left == x)
            parent->left = x->left;
        else
            parent->right = x->left;
        delete x;
        return;
    }
}

void btree::locate(Node *curr, Node **par, Node **x, bool *found, int num){ //this fn stores the to be deleted node's address in (*x) 
    *found = false;                                                         // and to be deleted node's parent's address in (*par)
    while(curr!= NULL){
        if(num == curr->data){
            *found = true;
            *x = curr;
            return;
        }
        *par = curr;
        if(num<curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
}


int main() {
    btree bt;
    bt.insert(10);
    bt.insert(6);
    bt.insert(3);
    bt.insert(15);
    bt.insert(18);
    bt.display();
    bt.search(13);
    bt.remove(15);
    bt.display();

    return 0;
}