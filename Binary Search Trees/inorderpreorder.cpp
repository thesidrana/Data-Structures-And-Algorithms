/*
CONSTRUCT BINARY TREE USING GIVEN INORDER AND PREORDER TRAVERSALS
*/

class Solution{
    public:
    
    int preIndex = 0;
    Node* buildTree(int in[],int pre[], int ie, int is = 0)
    {
        if(is > ie-1) return NULL;
        
        Node* root = new Node(pre[preIndex++]);
        
        int inIndex;
        for(int i=is;i<ie;i++)
        {
            if(in[i]==root->data)
            {
                inIndex=i;
                break;
            }
        }
        
        root->left=buildTree(in,pre,inIndex,is);
        root->right=buildTree(in,pre,ie,inIndex+1);
        
        return root;
    }
};
