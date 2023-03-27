#include<iostream>
using namespace std;
class Node
{
public:
    int data, height;
    Node* left_child;
    Node* right_child;
};

class avl {
public:
    Node* node = NULL;

    int get_height(Node* root) {
        if (root == NULL)
            return -1;
        return (root->height);
    }

    int get_balance_factor(Node* root) {
        if (root == NULL)
            return 0;
        return (get_height(root->left_child) - get_height(root->right_child));
    }

    // Clockwise Rotation
    Node* LL_rotation(Node* root) {
        Node* child = root->left_child;
        root->left_child = child->right_child;
        child->right_child = root;
        root->height = max(get_height(root->left_child), get_height(root->right_child)) + 1;
        child->height = max(get_height(child->left_child), get_height(child->right_child)) + 1;
        return child;
    }

    // Anti-Clockwise Rotation
    Node* RR_rotation(Node* root) {
        Node* child = root->right_child;
        root->right_child = child->left_child;
        child->left_child = root;
        root->height = max(get_height(root->left_child), get_height(root->right_child)) + 1;
        child->height = max(get_height(child->left_child), get_height(child->right_child)) + 1;
        return child;
    }

    // Pre-order traversal of the tree
    void pre_order(Node* root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            pre_order(root->left_child);
            pre_order(root->right_child);
        }
    }

    // AVL Insertion
    Node* insert(Node* root, int new_data)
    {
        // BST Insertion Logic
        if (root == NULL) {
            root = new Node;
            root->data = new_data;
            root->left_child = NULL;
            root->right_child = NULL;
            root->height = 0;
            return root;
        }
        if (root->data < new_data)
            root->right_child = insert(root->right_child, new_data);
        else
            root->left_child = insert(root->left_child, new_data);

        // Balance Factor Check
        root->height = max(get_height(root->left_child), get_height(root->right_child)) + 1;
        int b = get_balance_factor(root);

        // Checking if the node insertion results in Left heavy or Right heavy nodes.
        if (b > 1) {
            // LL Rotation Case
            if (get_balance_factor(root->left_child) == 1) {
                root = LL_rotation(root);
            }
            // LR Rotation Case
            else {
                root->left_child = RR_rotation(root->left_child);
                root = LL_rotation(root);
            }
        }
        else if (b < -1) {
            // RR Rotation Case
            if (get_balance_factor(root->right_child) == -1) {
                root = RR_rotation(root);
            }
            // RL Rotation Case
            else {
                root->right_child = LL_rotation(root->right_child);
                root = RR_rotation(root);
            }
        }
        return root;
    }

    Node* minValue_Node(Node* root) {
        Node* curr = root;
        while (curr->left_child != NULL)
            curr = curr->left_child;
        return curr;
    }
    Node* deleteNode(Node* root, int key);
    ~avl();
    void del(Node* root);
};

Node* avl::deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left_child = deleteNode(root->left_child, key);
    else if (key > root->data)
        root->right_child = deleteNode(root->right_child, key);
    else {
        if ((root->left_child == NULL) || (root->right_child == NULL)) {  //either one child or no child
            Node* temp = root->left_child ? root->left_child : root->right_child;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp; //copy the contents of non-empty child
            delete temp;
        }
        else {
            Node* temp = minValue_Node(root->right_child);
            root->data = temp->data; //copy inorder successor's data to this node
            root->right_child = deleteNode(root->right_child, temp->data);
        }
    }

    if (root == NULL) //means the root had no children in the "either one child or no child" sectuion
        return root;
    root->height = 1 + max(get_height(root->left_child), get_height(root->right_child));
    int b = get_balance_factor(root);
    //if this node be
    if (b > 1) {
        // LL Rotation Case
        if (get_balance_factor(root->left_child) == 1) {
            root = LL_rotation(root);
        }
        // LR Rotation Case
        else {
            root->left_child = RR_rotation(root->left_child);
            root = LL_rotation(root);
        }
    }
    else if (b < -1) {
        // RR Rotation Case
        if (get_balance_factor(root->right_child) == -1) {
            root = RR_rotation(root);
        }
        // RL Rotation Case
        else {
            root->right_child = LL_rotation(root->right_child);
            root = RR_rotation(root);
        }
    }
    return root;
}

avl::~avl() {
    del(node);
}

void avl::del(Node* root) {
    if (root) {
        del(root->left_child);
        del(root->right_child);
        delete root;
    }
}

int main()
{
    avl tree;
    tree.node = tree.insert(tree.node, 10);
    tree.node = tree.insert(tree.node, 20);
    tree.node = tree.insert(tree.node, 30);
    tree.node = tree.insert(tree.node, 40);
    tree.node = tree.insert(tree.node, 50);
    tree.node = tree.insert(tree.node, 60);
    cout << "Pre-order Traversal of the AVL Tree is : ";
    tree.pre_order(tree.node);
    return 0;
}