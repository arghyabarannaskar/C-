//Back-end complete function Template for C++

int ksmallestElementSumRec(Node *root, int k, int &count) 
{ 
    // Base cases 
    if (root == NULL) 
        return 0; 
    if (count > k) 
        return 0; 
  
    // Compute sum of elements in left subtree 
    int res = ksmallestElementSumRec(root->left, k, count); 
    if (count >= k) 
        return res; 
  
    // Add root's data 
    res += root->data; 
  
    // Add current Node 
    count++; 
    if (count >= k) 
      return res; 
  
    // If count is less than k, return right subtree Nodes 
    return res + ksmallestElementSumRec(root->right, k, count); 
}

int sum(Node *root, int k)
{
    int count = 0; 
    return ksmallestElementSumRec(root, k, count); 
}