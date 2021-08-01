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
void inorder(Node* root){
  //Base condition
  if(root==NULL) return;
  //Creating empty stack
  stack<Node*> s;
  //Set current at roor
  Node* current = root;
  //Breaks if current is null and stack is empty
  while(current!=NULL || !s.empty()){
    //Traverse to left-most child of current. After this point, current is NULL
    while(current!=NULL){
      //Push current
      s.push(current);
      //Traverse to left most element. It will be at TOS when loop ends.
      current = current->left;
    }
    //Print tos and pop it. Then set current at right of popped item.
    Node* node = s.top();
    s.pop();
    cout << node->data << "   ";
    current = node->right;
  }
}

int main(){
  Node* root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(5);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->right = new Node(6);

  inorder(root);
  return 0;
}
