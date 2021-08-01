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
void topview(Node* root){
  if(root==NULL) return;
  //Create empty queue and map
  queue<Node*> q;
  map<int,int> m;
  int hd=0;
  root->hd = hd;
  //Push root into queue
  q.push(root);

  while(!q.empty()){
    //Horizontal Distance  = horizontal Distance of root
    hd = root->hd;
    //If current node is the first in it's vertical line, add it to the map
    if(m.count(hd)==0)
      m[hd] = root->data;
      //if left exists, reduce it's HD by 1 and push it to queue
    if(root->left){
      root->left->hd = hd-1;
      q.push(root->left);
    }
    //if right exists, increase it's HD by 1 and push it to queue
    if(root->right){
      root->right->hd = hd+1;
      q.push(root->right);
    }
    //Pop queue and set root as next in queue
    q.pop();
    root = q.front();
  }
  for(auto i =m.begin(); i!=m.end(); i++){
    cout << i->second << " ";
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
