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
void leaflevelutil(Node* root, int level, unordered_map<int,vector<Node*>> &m){
  if(root==NULL) return;
  if(!root->left &&  !root->right){
    m[level].push_back(root);
  }
  leaflevelutil(root->left,level-1, m);
  leaflevelutil(root->right,level-1, m);
}
bool leaflevel(Node* root){
  if(root==NULL) return true;
  unordered_map<int, vector<Node*>> m;
  int level = 0;
  leaflevelutil(root,level,m);
  if(m.size()>1){
    return false;
  }
  return true;
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
  root->right->left = new Node(11);
  root->right->right->left = new Node(13);
  cout << leaflevel(root) << endl;
  return 0;
}
