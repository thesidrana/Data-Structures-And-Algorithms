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
void reverseLevelOrder(Node* root){
  if(root==NULL) return;
  queue<Node*> q;
  stack<Node*> s;
  q.push(root);
  while(!q.empty()){
    Node* n = q.front();
    s.push(n);
    q.pop();
    if(n->right!=NULL){
      q.push(n->right);
    }
    if(n->left!=NULL){
      q.push(n->left);
    }
  }
  while(!s.empty()){
    Node* n = s.top();
    cout << n->data << "    ";
    s.pop();
  }
  cout << endl;
}
int main(){
  Node* root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  reverseLevelOrder(root);
  return 0;

}
