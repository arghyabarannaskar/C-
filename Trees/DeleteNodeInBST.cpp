#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

void Delete(Node *root, int data){
    if(root == NULL)
        return;
    else if(data < root->data)
        Delete(root->left, data);
    else if(data > root->data)
        Delete(root->right, data);
    else{
        if(root->left == NULL && root->right == NULL)
            delete root;
        else if(root->left == NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else{
            Node *temp = FindMin(root->right);
            root->data = temp->data;
            Delete(root->right, temp->data);
        }
    }
}

Node * FindMin(Node *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

int main(){

    return 0;
}