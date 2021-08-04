/*
Given a Binary Tree with all unique values and two nodes value n1 and n2. 
The task is to find the lowest common ancestor of the given two nodes. 
We may assume that either both n1 and n2 are present in the tree or none of them is present. 
*/
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL) return NULL;
       if(root->data == n1 || root->data==n2){
           return root;
       }
       Node* left_lca = lca(root->left, n1, n2);
       Node* right_lca = lca(root->right, n1, n2);
       if(left_lca && right_lca) return root;
       return (left_lca != NULL)? left_lca : right_lca;
    }
};
