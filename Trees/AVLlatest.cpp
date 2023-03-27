#include<iostream>
using namespace std;

struct Node{
    int data, height;
    Node *left_child;
    Node *right_child;
};



class avl{
    public:
        Node *node = NULL;
        int get_height(Node *root){
            if(root == NULL)
                return -1;
            return root->height;
        }

        int max(int a, int b){
            if(a>=b)
                return a;
            return b;
        }

        int get_balance_factor(Node *root){
            if(root == NULL)
                return 0;
            return (get_height(root->left_child) - get_height(root->right_child));
        }

        Node *LL_rotation(Node *root){
            Node *child = root->left_child;
            root->left_child = child->right_child;
            child->right_child = root;
            root->height = max(get_height(root->left_child), get_height(root->right_child)) + 1;
            child->height = max(get_height(child->left_child), get_height(child->right_child)) + 1;
            return child;
        }

        Node *RR_rotation(Node *root){
            Node *child = root->right_child;
            root->right_child = child->left_child;
            child->left_child = root;
            root->height = max(get_height(root->left_child), get_height(root->right_child)) + 1;
            child->height = max(get_height(child->left_child), get_height(child->right_child)) + 1;
            return child;
        }

        Node * insert(Node *root, int data){
            if(root == NULL){
                root = new Node;
                root->data = data;
                root->left_child = NULL;
                root->right_child = NULL;
                root->height = 0;
                return root;
            }
            if(data <= root->data)
                root->left_child = insert(root->left_child, data);
            else
                root->right_child = insert(root->right_child, data);

            root->height = max(get_height(root->left_child), get_height(root->right_child)) + 1;
            int b = get_balance_factor(root);

            if(b>1){
                if(get_balance_factor(root->left_child)==1){
                    root = LL_rotation(root);
                }else{
                    root->left_child = RR_rotation(root->left_child);
                    root = LL_rotation(root);
                }
            }
            else if(b < -1){
                if(get_balance_factor(root->right_child) == -1){
                    root = RR_rotation(root);
                }else{
                    root->right_child = LL_rotation(root->right_child);
                    root = RR_rotation(root);
                }
            }
            return root;
        }

        void preorder(Node *root){
            if(root != NULL){
                
                cout << root->data << " ";
                preorder(root->left_child);
                preorder(root->right_child);
            }
        }

        Node *minValue(Node *root){
            while(root->left_child)
                root = root->left_child;
            return root;
        }

        Node *deleteNode(Node *root, int data){
            if(root == NULL)
                return root;
            if(data < root->data)
                root->left_child = deleteNode(root->left_child, data);
            else if(data > root->data)
                root->right_child = deleteNode(root->right_child, data);
            else{
                if(root->left_child == NULL && root->right_child == NULL){
                    delete root;
                    return NULL;
                }else if(root->left_child == NULL || root->right_child == NULL){
                    Node *temp = root->left_child ? root->left_child : root->right_child;
                    delete root;
                    return temp;
                }

                Node *temp = minValue(root->right_child);
                root->data = temp->data;
                root->right_child = deleteNode(root->right_child, root->data);
            }
            return root;
        }
};


int main(){

        avl tree;
        tree.node = tree.insert(tree.node, 100);
        tree.node = tree.insert(tree.node, 15);
        tree.node = tree.insert(tree.node, 10);
        tree.node = tree.insert(tree.node, 25);
        tree.node = tree.insert(tree.node, 30);
        tree.node = tree.insert(tree.node, 63);
        tree.node = tree.insert(tree.node, 37);
        tree.node = tree.insert(tree.node, 19);
        tree.node = tree.insert(tree.node, 27);

        cout <<endl<< "Preorder traversal of this tree: ";
        tree.preorder(tree.node);

        tree.node = tree.deleteNode(tree.node, 37);
        cout <<endl<< "Preorder traversal of this tree: ";
        tree.preorder(tree.node);
        tree.node = tree.deleteNode(tree.node, 63);
        cout <<endl<< "Preorder traversal of this tree: ";
        tree.preorder(tree.node);

        return 0;
}