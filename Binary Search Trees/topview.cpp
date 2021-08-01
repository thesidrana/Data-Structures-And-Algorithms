#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};
void getVerticalOrder(Node* root, int hd, map<int,vector<int>> &m){
  if(root==NULL) return;

  m[hd].push_back(root->data);
  getVerticalOrder(root->left,hd-1,m);
  getVerticalOrder(root->right,hd+1,m);
}
void topview(Node *root){
  if(root==NULL) return;
  map<int, vector<int>> m;
  int hd = 0;
  getVerticalOrder(root,hd,m);
  for(auto it = m.begin(); it != m.end(); it++){
    cout << it->second[0] << endl;
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

  topview(root);
  return 0;
}
