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
void postorder(Node* root){
  if(root==NULL) return;
  stack <Node*> s;
  stack <Node*> t;

  s.push(root);
  while(!s.empty()){
    Node  * node = s.top();
    s.pop();
    t.push(node);

    if(node->left!=NULL) s.push(node->left);
    if(node->right!=NULL) s.push(node->right);
  }

  while(!t.empty()){
    Node* node = t.top();
    t.pop();
    cout << node->data << "   ";
  }
}

int main(){
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  postorder(root);
  return 0;
}
