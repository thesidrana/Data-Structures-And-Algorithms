#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void push(Node** head, int new_data){
  Node* new_node = new  Node();
  new_node -> data = new_data;
  new_node->next = (*head);
  (*head) = new_node;
}

int pop(Node** head){
  Node* first = (*head);
  (*head) = (*head)->next;
  return first->data;
}

void printstack(Node* head){
  while(head!=NULL){
    cout << head->data << endl;
    head = head->next;
  }
  cout << endl;
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
  cout << "After pushing all elements : " << endl;
  printstack(head);
  cout << "Popping once" << endl;
  pop(&head);
  printstack(head);
  cout << "Popping twice" << endl;
  pop(&head);
  printstack(head);
  cout << "Popping thrice" << endl;
  pop(&head);
  printstack(head);
  return 0;
}
