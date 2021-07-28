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
  new_node -> next = *head;
  *head = new_node;
}

void insertAfter(Node* head, int prev_data, int new_data){

  Node* temp = head;

  while(temp!=NULL){
      if(temp->data == prev_data){
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = temp->next;
        temp->next = new_node;
        return;
      }
      temp = temp->next;
  }
}
void insertBefore(Node* head, int after_data, int new_data){

  Node* temp = head;

  while(temp!=NULL){
      if(temp->next->data == after_data){
        Node* new_node = new Node();
        new_node->data = new_data;
        new_node->next = temp->next;
        temp->next = new_node;
        return;
      }
      temp = temp->next;
  }
}
void printList(Node* head)
{
  while(head!=NULL){
    cout << head->data << "   ";
    head = head->next;
  }
  cout << endl;
}
void insertAtEnd(Node* head, int new_data){

  Node* temp = head;

  while(temp->next!=NULL){
      temp = temp->next;
  }

  Node* new_node = new Node();
  new_node -> data = new_data;
  temp ->next = new_node;
  new_node -> next = NULL;
}
int main(){
  Node* head = NULL;
  Node* second = NULL;
  Node* third = NULL;

  head = new Node();
  second = new Node();
  third = new Node();

  head -> data = 1;
  head -> next = second;
  second -> data = 2;
  second -> next = third;
  third -> data = 3;
  third -> next = NULL;

  push(&head, 0);
  printList(head);

  insertAfter(head,2,4);
  printList(head);

  insertBefore(head,3,1);
  printList(head);

  insertAtEnd(head,5);
  printList(head);

  return 0;

}
