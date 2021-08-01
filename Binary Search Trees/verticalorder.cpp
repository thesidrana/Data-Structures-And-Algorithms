#include<iostream>
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
//Function To find Minimum and maximum horizontal distance.
void findMinMax(Node* root, int *min, int *max, int hd){
  if(root==NULL) return;
  if(hd<(*min)) *min = hd;
  if(hd>(*max)) *max = hd;
  findMinMax(root->left,min,max,hd-1);
  findMinMax(root->right,min,max,hd+1);
}
//Function to print a vertical line.
void printVerticalLine(Node* root, int line_no, int hd){
  if(root==NULL) return;

  if(hd==line_no) cout << root->data << " ";
  printVerticalLine(root->left,line_no,hd-1);
  printVerticalLine(root->right,line_no,hd+1);
}
void verticalorder(Node* root){
  if(root==NULL) return;
  int min = 0, max = 0;
  findMinMax(root,&min,&max,0);
  for(int line_no = min; line_no <=max; line_no ++){
    printVerticalLine(root,line_no,0);
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
