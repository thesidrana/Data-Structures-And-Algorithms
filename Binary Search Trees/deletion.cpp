/*
Delete a node with given key
*/

Node* minValue(Node* node){
    Node* current = node;
    while(current && current->left){
        current = current->left;
    }
    return current;
}
Node *deleteNode(Node *root,  int X)
{
    if(root==NULL) return NULL;
    
    if(X < root->data){
        root->left = deleteNode(root->left, X);
    }
    else if (X > root->data){
        root->right = deleteNode(root->right, X);
    }
    else{
        if(!root->left && !root->right){
            return NULL;
        }
        else if(!root->left){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
