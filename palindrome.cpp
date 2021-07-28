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

Node* reverse(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* prev = NULL;
  Node* next = NULL;
  while(head!=NULL){
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

bool isPalindrome(Node* head, Node* prev){
  while(head!=NULL){
    if(head->data==prev->data){
      head=head->next;
      prev=prev->next;
    }
    else{
      return false;
    }
  }
  return true;
}

int main(){
  Node* head = new Node();
  head->data = 7;
  head->next = NULL;
  push(&head,6);
  push(&head,5);
  push(&head,5);
  push(&head,6);
  push(&head,7);

  printList(head);
  Node * prev = reverse(head);
  cout << isPalindrome(head,prev);
  return 0;
}
