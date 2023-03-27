#include<iostream>
#include<queue>
using namespace std;

struct Node{
    Node *left;
    char data;
    Node *right;
};

void levelOrder(Node *root){
    if(root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    while(!Q.empty()){
        Node *current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL)
            Q.push(current->left);
        if(current->right != NULL)
            Q.push(current->right);
        Q.pop();
    }
}

int main(){

    return 0;
}