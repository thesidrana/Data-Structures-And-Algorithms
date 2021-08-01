#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* right;
  Node* left;

  Node(int val){
    data = val;
    right = NULL;
    left = NULL;
  }
};
void zigzag(Node* root){
  if(root==NULL) return;
  stack<Node*> current;
  stack<Node*> next;
  current.push(root);
  bool lefttoright = true;
  while(!current.empty()){
    Node* node = current.top();
    current.pop();
    if(node){
      cout << node->data << " ";
      if(lefttoright){
        if(node->left) next.push(node->left);
        if(node->right) next.push(node->right);
      }
      else{
        if(node->right) next.push(node->right);
        if(node->left) next.push(node->left);
      }
    }
    if(current.empty()){
      lefttoright = !lefttoright;
      swap(current,next);
    }
  }
}

int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  zigzag(root);
  return 0;
}
