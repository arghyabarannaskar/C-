#include<iostream>
using namespace std;

void postorder(TreeNode *root){
    TreeNode *curr = root, *temp;

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
                while(!st.empty() && temp == st.top()->right){ //while dry running this be very careful...curr is still NULL
                    temp = st.top(); st.pop();                 // we are working with 'temp' here and not 'curr'
                    post.push_back(temp->val);
                }
            }else curr = temp;
        }
    }
}

int main(){

    return 0;
}