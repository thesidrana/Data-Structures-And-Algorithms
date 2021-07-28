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

void reverse(Node ** head){
  Node* prev = NULL;
  Node* nextn = NULL;
  if(head==NULL){
    cout << "Does not exist";
  }
  while((*head)!=NULL){
    nextn = (*head)->next;
    (*head)->next = prev;
    prev = (*head);
    (*head) = nextn;
  }
  *head = prev;
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
  reverse(&head);
  printList(head);
  return 0;
}
