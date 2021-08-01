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

void levelOrder(Node* root){
  if(root==NULL) return ;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    Node* n = q.front();
    cout << n->data << " ";
    q.pop();
    if(n->left!=NULL) q.push(n->left);
    if(n->right!=NULL) q.push(n->right);
  }
  cout <<endl;
}


 int main(){
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   root->left->left = new Node(4);
   root->left->right = new Node(5);
   root->right->right = new Node(6);
   levelOrder(root);
   return 0;
 }
