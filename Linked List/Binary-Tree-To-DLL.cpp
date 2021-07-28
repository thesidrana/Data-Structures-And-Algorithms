Node* head, *prev;
    void convert(Node* root){
        if(!root) return;
        convert(root->left);
        if(prev==NULL){
            head = root;
        }
        else{
            root->left = prev;
            prev->right = root; 
        }
        prev = root;
        convert(root->right);
    }
    Node * bToDLL(Node *root)
    {
        head = NULL;
        prev = NULL;
        convert(root);
        return head;
    }
