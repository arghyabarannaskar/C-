struct Node
{                                     //Author's Solution below
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if (!root)  return res;
        
        map<int, int> M;
        queue<pair<Node*, int>> Q;
        Q.push({root, 0});
        
        while (!Q.empty()) {
            Node *node = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            
            if (M.find(col) == M.end()) {
                M[col] = node->data;
            }
            
            if (node->left) {
                Q.push({node->left, col - 1});
            }
            
            if (node->right) {
                Q.push({node->right, col + 1});
            }
        }
        
        for (auto i : M) {
            res.push_back(i.second);
        }
        
        return res;
    }

};






/*Author's Solution:*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        // base case
        if(root == NULL){
            return ans;
        }
    
        Node *temp = NULL;
        //creating empty queue for level order traversal.
        queue<pair<Node *, int>> q;
        //creating a map to store nodes at a particular horizontal distance.
        map<int, int> mp;
    
        q.push({root, 0});
        while(!q.empty())
        {
    
            temp = q.front().first;
            int d = q.front().second;
            q.pop();
            
            //storing temp->data in map.
            if(mp.find(d) == mp.end()){
                mp[d] = temp->data;
            }
            
            //if left child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->left){
                q.push({temp->left, d-1});
            }
            //if right child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->right){
                q.push({temp->right, d+1});
            }
        }
        //traversing the map and storing the nodes in list 
        //at every horizontal distance.
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        //returning the output list.
        return ans;
    }
};













