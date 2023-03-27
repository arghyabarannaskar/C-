#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class binaryTree{
    private:
        Node *root;

        Node *createNode(int num);
        void inorder(Node *curr);

    public:
        binaryTree();
        void insert(int num);
        void display();
};

binaryTree::binaryTree(){
    root = NULL;
}

Node* binaryTree::createNode(int num){
    Node *temp = new Node(num);
    if(temp == NULL)
        cout << "Memory error" << endl;
    return temp;
}

void binaryTree::insert(int num){
    if(root == NULL){
        root = createNode(num);
        return;
    }

    queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }else{
            temp->left = createNode(num);
            return;
        }

        if(temp->right != NULL)
            q.push(temp->right);
        else{
            temp->right = createNode(num);
            return;
        }
    }
}

void binaryTree::display(){
    inorder(root);
}

void binaryTree::inorder(Node *curr){
    if(curr != NULL){
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
}

int main(){
    binaryTree bt;
    bt.insert(21);
    bt.insert(54);
    bt.insert(354);
    bt.insert(27);
    bt.insert(65);

    bt.display();

    return 0;
}