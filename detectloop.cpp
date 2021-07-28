#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void push(Node** head, int new_data){
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node -> next = (*head);
  (*head) = new_node;
}
void printList(Node* head){
  if(head==NULL){
    return;
  }
  while(head!=NULL){
    cout << head->data << "     ";
    head = head->next;
  }
  cout<< endl;
}
bool detectloop(Node*head){
  Node* slow = head;
  Node* fast = head;
  while(fast!=NULL && fast->next!=NULL){
    fast = fast->next->next;
    slow = slow->next;
    if(fast->data == slow->data){
      return true;
    }
  }
  return false;
}
int main(){
  Node* head = new Node();
  head->data = 9;
  head->next=NULL;
  push(&head,8);
  push(&head,7);
  push(&head,6);
  // push(&head,9);
  // push(&head,8);
  // push(&head,7);
  // push(&head,6);
  // push(&head,9);
  printList(head);
  cout << detectloop(head) <<endl;
  return 0;
}
