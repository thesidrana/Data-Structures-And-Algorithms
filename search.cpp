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

int search(Node *head, int key){
  if(head==NULL){
    cout << "Linked List does not exist" << endl;
    return -1;
  }
  else{
    if(head->data != key){
      return 1 + search(head->next,key);
    }
    else{
      return 0;
    }
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
  cout << "Present at Index: "<< search(head, 5) << endl;
  return 0;
}
