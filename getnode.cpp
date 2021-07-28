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
int getNode(Node * head, int index){
  if(head==NULL){return -1;}
  else{
    int count = 0;
    while(head!=NULL){
      if(count==index){
        break;
      }
      else{
        count++;
        head=head->next;
      }
    }
  }
  return head->data;
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
  cout << getNode(head,3) << endl;
  return 0;
}
