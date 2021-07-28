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
void printList(Node* head){
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
void deleteAtStart(Node** head){
  (*head) = (*head)->next;
}
void deleteFromEnd(Node * head){
  Node * temp = (head);
  while(temp->next->next!=NULL){
    temp = temp->next;
  }
  temp->next = NULL;
}
void deleteKey(Node* head, int key){
  Node *temp = head;
  Node *prev = NULL;
  //For the first element
  if(temp!=NULL && temp->data==key){
    head = temp->next;
    delete temp;
    return;
  }
  //If key is not the first element
  else{
    while(temp!=NULL && temp->data!=key){
      prev = temp;
      temp = temp->next;
    }
    if(temp==NULL){
      return;
    }
    else{
      prev->next = temp->next;
      delete temp;
    }
  }
}
void deleteIndex(Node* head, int ind){
  Node* temp = head;
  Node* prev = NULL;
  for(int i =0;i<=ind;i++){
    prev = temp;
    temp = temp->next;
  }
  prev->next = temp->next;
  delete temp;
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
  insertAfter(head,2,4);
  insertBefore(head,3,1);
  insertAtEnd(head,5);
  cout << "List after Insertion : " << endl;
  printList(head);

  cout << "Deleting from the Beginning : " << endl;
  deleteAtStart(&head);
  printList(head);

  cout << "Deleting from the End : " << endl;
  deleteFromEnd(head);
  printList(head);

  cout << "Deleting 3 : " << endl;
  deleteKey(head,3);
  printList(head);

  cout << "Deleting Index 2" << endl;
  deleteIndex(head,2);
  printList(head);

  return 0;

}
