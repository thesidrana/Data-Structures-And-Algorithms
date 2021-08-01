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
void getdiagonalview(Node* root,int diag_no, map<int,vector<int>> &m){
  if(root==NULL) return;
  m[diag_no].push_back(root->data);
  if(root->left) getdiagonalview(root->left,diag_no+1,m);
  if(root->right) getdiagonalview(root->right,diag_no,m);
}
void diagonalview(Node* root){
  if(root==NULL) return;
  int diag_no = 0;
  map<int,vector<int>> m;
  getdiagonalview(root,diag_no,m);
  for(auto it = m.begin(); it!=m.end(); it++){
    for(int i = 0;i<it->second.size();i++){
      cout << it->second[i] <<" ";
    }
    cout << endl;
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
  root->right->right->left = new Node(1);

  diagonalview(root);
  return 0;
}
