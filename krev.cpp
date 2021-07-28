#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void push(Node** head, int new_data){
  Node* new_node = new Node();
  new_node -> data = new_data;
  new_node -> next = (*head);
  (*head) = new_node;
}
void printList(Node* head){
  if(head==NULL){
    return;
  }
  while(head!=NULL){
    cout<< head->data << "  " ;
    head = head->next;
  }
  cout << endl;
}
Node* krev(Node* head, int key){
  if(!head){
    return NULL;
  }
  Node* current = head;
  Node* prev = NULL;
  Node* next = NULL;
  int count = 0;

  while(current!=0 && count <key){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }
  if(next!=NULL){
    head->next = krev(next,key);
  }
  return prev;
}
int main(){
  Node * head = new Node();
  head->data = 8;
  head->next = NULL;
  push(&head,7);
  push(&head,6);
  push(&head,5);
  push(&head,4);
  push(&head,3);
  push(&head,2);
  push(&head,1);
  printList(head);
  cout << "The value for k is 3" <<endl;
  cout << "Array after reversal is:" <<endl;
  head = krev(head,3);
  printList(head);
  return 0;
}
