#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
  }
};

int getHeight(Node* root){
  if(root==NULL) return 0;
  int left_depth = getHeight(root->left);
  int right_depth = getHeight(root->right);

  if(left_depth > right_depth){
    return left_depth+1;
  }
  else{
    return right_depth+1;
  }
}
int main(){
  Node* root = new Node(1);
  Node* head = new Node(6);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  cout << getHeight(root) << endl;
  cout << getHeight(head) << endl;
  return 0;
}
