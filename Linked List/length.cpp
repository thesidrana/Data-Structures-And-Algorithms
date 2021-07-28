#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};
void push(Node ** head, int new_data){
  Node* new_node = new Node();
  new_node -> data = new_data;
  new_node -> next = (*head);
  (*head) = new_node;
}
void printList(Node* head){
  while(head!=NULL){
    cout << head->data << "   ";
    head = head->next;
  }
  cout << endl;
}

int listLength(Node* head){
  int len = 0;
  while(head!=NULL){
    len++;
    head = head->next;
  }
  return len;
}

int recLength(Node *head){
  if(head==NULL){
    return 0;
  }
  else{
    return 1+ recLength(head->next);
  }
}

int main(){
  Node* head = new Node();
  head->data = 7;
  head->next = NULL;
  push(&head,6);
  push(&head,5);
  push(&head,4);
  push(&head,3);
  push(&head,2);
  push(&head,1);

  printList(head);
  cout << listLength(head) << endl;
  cout << recLength(head) << endl;
  return 0;
}
