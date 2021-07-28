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
int midpoint(Node* head){
  Node* slow = head;
  Node* fast = head;
  while(fast!=NULL && fast->next!=NULL){
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow->data;
}
int main(){
  Node* head = new Node();
  head->data = 9;
  head->next=NULL;
  push(&head,8);
  push(&head,7);
  push(&head,6);
  push(&head,5);
  push(&head,4);
  push(&head,3);
  push(&head,2);
  push(&head,1);
  printList(head);
  cout << "Midpoint is" << endl;
  int mid = midpoint(head);
  cout << mid<< endl;
  return 0;
}
