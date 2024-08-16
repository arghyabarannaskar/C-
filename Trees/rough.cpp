#include<iostream>
using namespace std;

struct btreenode{
    btreenode *left;
    int data;
    btreenode *right;
};

class btree{
    private:
        btreenode *root;
        void buildtree(btreenode **root, int data);
        void inorder(btreenode *root);
        void locate(btreenode *root, btreenode **par, btreenode **x, bool *found, int data);
        void del(btreenode *root);

    public:
        int height(){
            return getHeight(root);
        }
        int getHeight(btreenode *root);
        btree();
        void insert(int data);
        void display();
        void remove(int data);
        ~btree();
};

btree::btree(){
    root = NULL;
}

void btree::insert(int data){
    buildtree(&root, data);
}

void btree::buildtree(btreenode **curr, int data){
    if((*curr) == NULL){
        (*curr) = new btreenode;
        (*curr)->data = data;
        (*curr)->left = NULL;
        (*curr)->right = NULL;
        return;
    }else if(data < (*curr)->data){
        buildtree(&((*curr)->left), data);
    }else
        buildtree(&((*curr)->right), data);
}

void btree::display(){
    cout << endl;
    inorder(root);
}

void btree::inorder(btreenode *root){
    if(root){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void btree::locate(btreenode *root, btreenode **parent, btreenode **x, bool *found, int data){
    btreenode *curr = root;
    *found = false;

    while(curr){
        if(curr->data == data){
            *found = true;
            *x = curr;
            return;
        }

        *parent = curr;

        if(data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void btree::remove(int data){
    bool found = false;
    btreenode *parent = NULL, *x = NULL, *xsucc = NULL;
    locate(root, &parent, &x, &found, data);
    if(!found){
        cout << "Data is not present.. Aborting...";
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

    if(x->left == NULL && x->right== NULL){
        if(x == parent->left)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete x;
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
        if(x == root){
            btreenode *temp = root;
            root = root->left;
            delete temp;
            return;
        }
        if(parent->left == x)
            parent->left = x->left;
        else
            parent->right = x->left;
        delete x;
        return;
    }
}

void btree::del(btreenode *root){
    if(root){
        del(root->left);
        del(root->right);
        delete root;
    }
}

int btree::getHeight(btreenode *root){
    if(root == NULL)
        return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

btree::~btree(){
    del(root);
}

int main(){
    btree tree;
    tree.insert(20);
    tree.insert(30);
    tree.insert(10);
    tree.insert(25);
    tree.insert(15);

    cout << "Height of the tree is: " << tree.height() << endl;

    tree.display();
    tree.remove(25);
    tree.display();
    tree.remove(30);
    tree.display();
    tree.remove(20);
    tree.display();

    return 0;
}