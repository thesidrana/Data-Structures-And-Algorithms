/*
Given a Binary Tree of size N and an integer K. 
Print all nodes that are at distance k from root (root is considered at distance 0 from itself). 
Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.
*/

void compute(struct Node* root, int k, vector<int> &result){
    if(!root || k < 0) return;
    if(k==0){
        result.push_back(root->data);
        return;
    }    
    compute(root->left, k-1, result);
    compute(root->right, k-1, result);
}
vector<int> Kdistance(struct Node *root, int k)
{
  vector<int> result;
  compute(root, k , result);
  return result;
}
