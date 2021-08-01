#include<bits/stdc++.h>
using namespace std;

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
void getVerticalOrder(Node* root, int hd, map<int, vector<int>> &m){
  if(root==NULL) return;
  //Preorder traversal
  m[hd].push_back(root->data);

  getVerticalOrder(root->left,hd-1,m);
  getVerticalOrder(root->right,hd+1,m);
}
void verticalorder(Node* root){
  map <int, vector<int>> m;
  int hd = 0;
  getVerticalOrder(root,hd,m);
  map<int, vector<int>> :: iterator it;
  //Map has stored the nodes according to their vertical distances
  for(auto it = m.begin(); it!=m.end();it++){
    for(int i=0; i<it->second.size();i++){
      cout << it->second[i] << " ";
    }
    cout << endl;
  }
}
int main(){
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  verticalorder(root);
  return 0;
}
