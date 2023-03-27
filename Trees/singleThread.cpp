#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    bool rightThread;
};

Node * leftMost(Node *n){
    if(n == NULL)
        return NULL;
    while(n->left != NULL)
        n = n->left;
    return n;
}

void inOrder(Node * root){
    Node *cur = leftMost(root);
    while(cur!= NULL){
        cout << cur->data << " ";
        if(cur->rightThread) //if thread exists, then go to inorder successor
            cur = cur->right;
        else //else go to the left most child of the right subtree
            cur = leftMost(cur->right);
    }
}