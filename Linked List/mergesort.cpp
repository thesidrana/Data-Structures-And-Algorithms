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
void split(Node* start, Node** ll1, Node** ll2){
  Node* slow = start;
  Node* fast = start->next;
  while(fast!=NULL){
    fast= fast->next;
    if(fast!=NULL){
      slow= slow->next;
      fast=fast->next;
    }
  }
  *ll1 = start;
  *ll2 = slow->next;
  slow->next = NULL;
}
Node* merge(Node* ll1, Node* ll2){
  Node* new_node = NULL;
  if(ll1==NULL) return ll2;
  if(ll2==NULL) return ll1;
  if(ll1->data <= ll2->data){
    new_node = ll1;
    new_node->next = merge(ll1->next,ll2);
  }
  else{
    new_node = ll2;
    new_node->next = merge(ll1,ll2->next);
  }
  return new_node;
}
void mergesort(Node** head){
  Node* temp = (*head);
  Node* ll1;
  Node* ll2;
  if(temp==NULL || temp->next == NULL){
    return;
  }
  split(temp,&ll1,&ll2);
  mergesort(&ll1);
  mergesort(&ll2);
  *head = merge(ll1,ll2);
  return;
}

int main(){
  Node* head = new Node();
  head->data = 7;
  head->next = NULL;
  push(&head,9);
  push(&head,6);
  push(&head,11);
  push(&head,5);
  push(&head,4);
  push(&head,1);
  push(&head,8);
  push(&head,2);

  printList(head);
  mergesort(&head);
  printList(head);
  return 0;
}
