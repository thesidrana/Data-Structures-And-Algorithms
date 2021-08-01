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
void leftview(Node* root){
  if(root==NULL) return ;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int n = q.size();
    for(int i = 1;i<=n;i++){
      Node* temp = q.front();
      q.pop();
      if(i==n){
        cout << temp->data << endl;
      }
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
  }
}

int main(){
  /*
          4
        /   \
      2      5
    /  \      \
  1    3       6

  */
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  leftview(root);
  return 0;
}
