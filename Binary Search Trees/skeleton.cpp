#include<iostream>
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

 int main(){
   Node* root = new Node(1);
   root->left = new Node(2);
   root->right = new Node(3);
   node->left>left = new Node(4);
   node->left>right = new Node(5);
   node->right->right = new Node(6);

   return 0;
 }
