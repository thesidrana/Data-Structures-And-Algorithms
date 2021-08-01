#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  int hd;
  Node* left;
  Node* right;

  Node(int val){
    data = val;
    hd = 0;
    left = NULL;
    right = NULL;
  }
};

void bottomview(Node *root){
  if(root==NULL) return;
  //Horizontal Distance of root
  int hd = 0;
  //Map to store different horizontal levels
  map<int, int> m;
  //Queue for level order traversal
  queue<Node*> q;
  root->hd = hd;
  q.push(root);
  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    hd = temp->hd;
    //Always add the most recent occurance
    // at one horizonatal level
    m[hd] = temp->data;
    if(temp->left){
      temp->left->hd = hd-1;
      q.push(temp->left);
    }
    if(temp->right){
      temp->right->hd = hd+1;
      q.push(temp->right);
    }
  }
  for(auto it = m.begin(); it!=m.end();it++){
    cout << it->second << " ";
  }
}
int main(){
  Node* root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(22);
  root->left->left = new Node(5);
  root->left->right = new Node(3);
  root->left->right->left = new Node(10);
  root->right->left = new Node(4);
  root->left->right->right = new Node(14);
  root->right->right = new Node(25);

  bottomview(root);
  return 0;
}
