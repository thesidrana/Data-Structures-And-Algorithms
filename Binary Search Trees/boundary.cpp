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
void printLeaves(Node* root){
  if(root==NULL) return;

  printLeaves(root->left);

  if(!root->left && !root->right) cout << root->data << " ";

  printLeaves(root->right);
}

void printLeft(Node* root){

  if(root==NULL) return;
  if(root->left){
    cout << root->data << " ";
    printLeft(root->left);
  }
  else if(root->right){
    cout << root->data << " ";
    printLeft(root->right);
  }
}
void printRight(Node* root){
  if(root==NULL) return;
  if(root->right){
    printRight(root->right);
    cout << root->data << " ";
  }
  else if(root->left){
    printRight(root->left);
    cout << root->data << " ";
  }
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
  root->right->right->left = new Node(13);

  printLeft(root);
  printLeaves(root);
  printRight(root);
  return 0;
}
