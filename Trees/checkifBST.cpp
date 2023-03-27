//Each node in a binary tree has maximum two children.
//Binary Search Tree: a binary tree in which for each node, value of all the nodes in the left subtree is lesser or equal and value of all nodes in right subtree is greater
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

bool IsSubTreeLesser(Node* root, int value){
    if(root == NULL)
        return true;
    if(root->data < value && IsSubTreeLesser(root->left, value) && IsSubTreeLesser(root->right, value))
        return true;
    return false;
}

bool IsSubTreeGreater(Node* root, int value){
    if(root == NULL)
        return true;
    if(root->data> value && IsSubTreeGreater(root->left, value) && IsSubTreeGreater(root->right, value))
        return true;
    return false;
}

bool IsbinarySearchTree(Node* root){
    if(root == NULL)
        return true;
    if(IsSubTreeLesser(root->left, root->data) && IsSubTreeGreater(root->right, root->data) && IsbinarySearchTree(root->left) && IsbinarySearchTree(root->right))
        return true;
    return false;
}

int main(){
    cout << NULL << endl;

    return 0;
}