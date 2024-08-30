#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int postOrderSuccessor(TreeNode<int> *root, int M)
{
    // Write your code here.
    TreeNode<int> *curr = root, *temp;
    stack<TreeNode<int> *> st;
    vector<int> post;

    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }else{
            temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                post.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top(); st.pop();
                    post.push_back(temp->val);
                }
            }else curr = temp;
        }
    }

    int n = post.size();
    for(int i = 0; i<n; i++){
        if(post[i] == M){
            if(i < n-1) return post[i+1];
            break;
        }
    }

    return -1;
}