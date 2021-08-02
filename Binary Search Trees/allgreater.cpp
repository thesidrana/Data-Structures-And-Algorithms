/*
Given a BST, modify it so that all greater values in the given BST are added to every node.
*/

void update_sum(Node* root, int* sum){
    if(root==NULL) return;
    update_sum(root->right, sum);
    *sum = root->data + (*sum);
    root->data = (*sum);
    update_sum(root->left, sum);
}
Node* modify(Node *root)
{
    int sum=0;
    update_sum(root, &sum);
    return root;
}
