#include<iostream>
using namespace std;

struct Node{
    int data, height;
    Node *left_child, *right_child;
};

class avl{
    public:
        Node *root = nullptr;

        int getHeight(Node *root){
            if(root == NULL)
                return -1;
            return max(getHeight(root->left_child), getHeight(root->right_child)) + 1;
        }

        int get_balance_factor(Node * root){
            if(root == NULL )
                return 0;
            return getHeight(root->left_child) - getHeight(root->right_child);
        }

        Node *LL_rotation(Node *root){
            Node *child = root->left_child;
            root->left_child = child->right_child;
            child->right_child = root;
            root->height = max(getHeight(root->left_child), getHeight(root->right_child)) + 1;
            child->height = max(getHeight(child->left_child), getHeight(child->right_child)) + 1;
            return child;
        }

        Node *RR_rotation(Node *root){
            Node *child = root->right_child;
            root->right_child = child->left_child;
            child->left_child = root;
            root->height = max(getHeight(root->left_child), getHeight(root->right_child)) + 1;
            child->height = max(getHeight(child->left_child), getHeight(child->right_child)) + 1;
            return child;
        }

        Node *insert(Node *root, int num){
            if(root == NULL){
                root = new Node;
                root->data = num;
                root->height = 0;
                root->left_child = root->right_child = NULL;
                return root;
            }

            if(num<root->data)
                root->left_child = insert(root->left_child, num);
            else
                root->right_child = insert(root->right_child, num);

            root->height = max(getHeight(root->left_child), getHeight(root->right_child)) + 1;

            int b = get_balance_factor(root);

            if(b>1){
                if(get_balance_factor(root->left_child) == 1){
                    root = LL_rotation(root);
                }else{
                    root->left_child = RR_rotation(root->right_child);
                    root = LL_rotation(root);
                }
            }
            else if(b<-1){
                if(get_balance_factor(root->right_child) == -1){
                    root = RR_rotation(root);
                }
                else {
                    root->right_child = LL_rotation(root->right_child);
                    root = RR_rotation(root);
                }
            }

            return root;
        }

        void preorder(Node *root){
            if(root){
                cout << root->data << " ";
                preorder(root->left_child);
                preorder(root->right_child);
            }
        }
};

int main(){
        avl tree;
        tree.root = tree.insert(tree.root, 10);
        tree.root = tree.insert(tree.root, 20);
        tree.root = tree.insert(tree.root, 30);
        tree.root = tree.insert(tree.root, 40);
        tree.root = tree.insert(tree.root, 50);

        tree.preorder(tree.root);

        return 0;
}