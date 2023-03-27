#include <iostream>
using namespace std;

struct btreenode{
    btreenode *leftchild;
    int data;
    btreenode *rightchild;
};

class btree
{
private:
    btreenode *root;

    void inorder(btreenode *sr);
    void preorder(btreenode *sr);
    void postorder(btreenode *sr);
    void insert(btreenode **sr, int);
    bool search(struct btreenode *, int);
    void locate(btreenode **sr, int num, btreenode **par, btreenode **x, bool *found);
    void rem(btreenode **sr, int num);
    void del(btreenode *sr);
    int findheight(btreenode *curr);
    int max(int a, int b);

public:
    btree();
    void peek(){
        cout << root->data << endl;
    }
    void buildtree(int num);
    void display();
    bool searchbst(int);
    int height();
    void remove(int num);
    ~btree();
};

btree::btree(){   //initializes data members
    root = NULL;
}

//calls insert to build tree
void btree::buildtree(int num){
    insert(&root, num);
}

//inserts a new node in a binary search tree
void btree::insert(btreenode **sr, int num){
    if(*sr == NULL){
        *sr = new btreenode;
        (*sr)->leftchild = NULL;
        (*sr)->data = num;
        (*sr)->rightchild = NULL;
    }else{
        if(num < (*sr)->data)
            insert(&((*sr)->leftchild), num);
        else
            insert(&((*sr)->rightchild), num);
    }
}

//calls inorder() to traverse tree
void btree::display(){
    cout << endl
         << "Inorder: ";
    inorder(root);
    cout << endl
         << "Preorder: ";
    preorder(root);
    cout << endl
         << "Postorder: ";
    postorder(root);
}

//traverse BST in Left-Root-Right fashion
void btree::inorder(btreenode *curr){
    if(curr != NULL){
        inorder(curr->leftchild);
        cout << curr->data << "\t";
        inorder(curr->rightchild);
    }
}

//traverse BST in Root-left-Right fashion
void btree::preorder(btreenode *curr){
    if(curr != NULL){
        cout << curr->data << "\t";
        preorder(curr->leftchild);
        preorder(curr->rightchild);
    }
}

//traverse BST in Left-Right-Root fashion
void btree::postorder(btreenode *curr){
    if(curr!= NULL){
        postorder(curr->leftchild);
        postorder(curr->rightchild);
        cout << curr->data << "\t";
    }
}

bool btree::searchbst(int num){
    bool flag;
    flag = search(root, num);
    return flag;
}

//search BST
bool btree::search(struct btreenode *curr, int num){
    while(curr != NULL){
        if(num == curr->data)
            return true;
        else if(num < curr->data)
            curr = curr->leftchild;
        else
            curr = curr->rightchild;
    }
    return false;
}

//calls rem to delete node
void btree::remove(int num){
    rem(&root, num);
}

//deletes a node from the BSt
void btree::rem(btreenode **curr, int num){
    bool found;                      // after returning from locate() bool = true means node is found else node is not found
    btreenode *parent, *x, *xsucc;   // after returning from locate, x = node to be deleted 

    //if tree is empty
    if(*curr == NULL){
        cout << endl
             << "Tree is empty";
        return;
    }

    parent = x = NULL;

    //call to search function to find the node to be deleted
    locate(curr, num, &parent, &x, &found);

    //if the node to be deleted is not found
    if(found == false){
        cout << endl
             << "Data to be deleted, not found";
        return;
    }

    //if the node to be deleted has two children
    if(x->leftchild != NULL && x->rightchild != NULL){   //if node to be delted has two children
        parent = x;
        xsucc = x->rightchild;          //inorder successor of target node will always be at the right

        while(xsucc->leftchild != NULL){  //trying to reach the leftmost node in the right subtree of target
            parent = xsucc;
            xsucc = xsucc->leftchild;
        }

        x->data = xsucc->data;  //when inorder successor is found data of inorder successor is copied to target
        x = xsucc;   //x is getting deleted in the next if statement becoz at this stage x is the target who has no children and parent points to the parent of x
    }

    //if the node to be deleted has no child
    if(x->leftchild == NULL && x->rightchild == NULL){   //at this state even the previous state x gets deleted
        if(parent->rightchild ==x)
            parent->rightchild = NULL;
        else
            parent->leftchild = NULL;
        delete x;
        return;
    }

    //if the node to be deleted has only rightchild
    if(x->leftchild == NULL && x->rightchild != NULL){
        if(parent->leftchild ==x)
            parent->leftchild = x->rightchild;
        else
            parent->rightchild = x->rightchild;

        delete x;
        return;
    }

    //if the node to be deleted has only left child
    if(x->leftchild != NULL && x->rightchild == NULL){
        if(parent->leftchild == x)
            parent->leftchild = x->leftchild;
        else
            parent->rightchild = x->leftchild;
        delete x;
        return;
    }
}


int btree::max(int a, int b){
    return (a >= b) ? a : b;
}

int btree::height(){
    int height = findheight(root);
    return height;
}

int btree::findheight(btreenode *curr){
    if(curr == NULL)
        return -1;
    int leftheight, rightheight;
    leftheight = findheight(curr->leftchild);
    rightheight = findheight(curr->rightchild);

    return max(leftheight, rightheight) + 1;
}

//returns the address of the node to be deleted, address of its parent 
//and whether the node is found or not 
void btree::locate(btreenode **curr, int num, btreenode **par, btreenode **x, bool *found){
    btreenode *q;
    q = *curr;
    *found = false;
    *par = NULL;

    while(q != NULL){
        //if the node to be deleted is found
        if(q->data == num){
            *found = true;
            *x = q;
            return;
        }

        *par = q;
        if(q->data >num)
            q = q->leftchild;
        else
            q = q->rightchild;
    }
}

//calls del to deallocate memory
btree::~btree(){
    del(root);
}

//deletes nodes of a BST
void btree::del(btreenode *curr){
    if(curr != NULL){
        del(curr->leftchild);
        del(curr->rightchild);
    }
    delete curr;
}

int main(){
    btree bt;
    int i, a[] = {20, 17, 6, 18, 8, 5, 7, 10, 13};
    bool flag;
    for (i = 0; i <= 8; i++)
        bt.buildtree(a[i]);
    cout << endl
         << "BST after insertion: ";
    bt.display();
    bt.peek();

    flag = bt.searchbst(13);
    if(flag == true)
        cout << endl
             << "Node 13 found in BST";
        else
            cout << endl
                 << "Node 13 not found in BST";

        bt.remove(10);
        cout << endl
             << "BST after deleting 10:";
        bt.display();

        bt.remove(14);
        cout << endl
             << "BST after deleting 14:";
        bt.display();

        bt.remove(8);
        cout << endl
             << "BST after deleting 8:";
        bt.display();
        bt.remove(7);
        bt.display();
        int h = bt.height();
        cout << "The height of the tree is " << h << endl;

        return 0;
}