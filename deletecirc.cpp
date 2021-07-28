#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;

  Node(int value){
    data = value;
    next = NULL;
  }
};
void insert(Node** head, int data){
  Node* temp = (*head)->next;
  while(temp!=(*head)){
    temp = temp->next;
  }

  temp->next = new Node(data);
  free(temp);
}
void printList(Node *head){
  if(!root) return;
  while(head){
    cout << head->data <<" ";
    head = head->next;
  }
}
int main(){
  Node* root = new Node(1);
}
