/*
Given a linked list in the fomr of a binary tree,
flatten it to a singly linked list such that left points to NULL
and right points to the next node in preorder traversal
*/

 void flatten(Node* root){
        if(!root || !root->left && !root->right){
            return;
        }
        if(root->left){
            flatten(root->left);
            Node* temp = root->right;
            root->right = root->left;
            root->left = NULL;
            Node* t = root->right;
            while(t->right){
                t = t->right;
            }
            t->right = temp;
        }
        flatten(root->right);
    }
