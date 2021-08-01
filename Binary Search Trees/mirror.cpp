#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int value){
    data = value;
    left = NULL;
    right = NULL;
  }
};

void levelOrder(Node* root){
  if(root==NULL) return;
  queue<Node*> Q;
  Q.push(root);
  while(!Q.empty()){
    Node* node = Q.front();
    cout << node->data << " ";
    Q.pop();

    if(node->left != NULL){
      Q.push(node->left);
    }
    if(node->right != NULL){
      Q.push(node->right);
    }
  }
  cout <<endl;
}

//Function to print mirror of a tree.

void mirror(Node* root){
  if(root==NULL) return;

  mirror(root->left);
  mirror(root->right);

  Node* temp = root->left;
  root->left = root->right;
  root->right = temp;
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(3);
  root->right = new Node(2);
  root->right->left = new Node(5);
  root->right->right = new Node(4);
  mirror(root);
  levelOrder(root);
  return 0;
}
