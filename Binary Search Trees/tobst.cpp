#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;
  int hd;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};
int countNodes(Node* root){
  if(root==NULL) return 0;
  return countNodes(root->left)+countNodes(root->right)+1;
}
void storeInorder(Node* root, vector<int> inorder, int* index_ptr){
  if(root==NULL) return;
  storeInorder(root->left, inorder, index_ptr);
  inorder[*index_ptr] = node->data;
  (*index_ptr)++;
  storeInorder(root->right, inorder, index_ptr);
}
void toBST(Node* root){
  if(root==NULL) return;
  int n = countNodes(root);
  int* arr = new int[n];
  int i = 0;
  storeInorder(root,arr,&i);
  qsort(arr, n,sizeof(arr[0]), compare);


}
int main(){
  Node* root = new Node(8);
  root->left = new Node(3);
  root->right = new Node(10);
  root->left->left = new Node(1);
  root->left->right = new Node(6);
  root->left->right->left = new Node(4);
  root->left->right->right = new Node(7);
  root->right->right = new Node(14);
  root->right->left = new Node(11);
  root->right->right->left = new Node(13);
  cout << leaflevel(root) << endl;
  return 0;
}
