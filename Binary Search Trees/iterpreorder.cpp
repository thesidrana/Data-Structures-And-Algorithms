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
void preorder(Node* root){

    if(root==NULL) return;

    stack<Node*> S;
    S.push(root);

    while(!S.empty()){
      Node* node = S.top();
      cout << node->data <<"  ";
      S.pop();
      if(node->right) S.push(node->right);
      if(node->left) S.push(node->left);
    }
}

int main(){
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  preorder(root);
  return 0;
}
