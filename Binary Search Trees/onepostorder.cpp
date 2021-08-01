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
  stack<Node*> s;
  do{
    while(root){
    if(root->right) s.push(root->right);
    s.push(root);
    root = root->left;
  }
  root = s.top();
  s.pop();
  if(root->right and root->right==s.top()){
    //Node* node = s.top();
    s.pop();
    s.push(root);
    root = root->right;
  }
  else{
    cout << root->data << "   ";
    root= NULL;
  }
 }while(!s.empty());
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
