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
int getHeight(Node *root){
  if(root==NULL) return 0 ;
  int left_height = getHeight(root->left);
  int right_height = getHeight(root->right);
  return max(left_height,right_height)+1;
}
int getDiameter(Node* root){
  if(root==NULL) return 0;
  int left_height = getHeight(root->left);
  int right_height = getHeight(root->right);

  int left_diameter = getDiameter(root->left);
  int right_diameter = getDiameter(root->right);

  return max(max(left_diameter, right_diameter), left_height + right_height +1);
}
int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  cout << getDiameter(root) << endl;
  return 0;
}
