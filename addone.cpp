#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void push(Node ** head, int new_data){
  Node* new_node = new Node();
  Node* temp = (*head);
  while(temp->next){
    temp = temp->next;
  }
  new_node -> data = new_data;
  temp -> next = new_node;
  new_node -> next = NULL;
}

void printList(Node* head){
  while(head!=NULL){
    cout << head->data << "   ";
    head = head->next;
  }
  cout << endl;
}

void reverse(Node ** head){
  Node* prev = NULL;
  Node* nextn = NULL;
  if(!(*head)) return;
  while((*head)){
    nextn = (*head)->next;
    (*head)->next = prev;
    prev = (*head);
    (*head) = nextn;
  }
  *head = prev;//As head is null at this point
}
Node* addoneUtil(Node* head){
  Node* res = head;
  Node* head_ref = head;
  Node* temp; //Stays one node behind head just in case the last element also gives carry
  int carry = 1, sum;
  while(head){
    sum = carry + head->data;
    carry = (sum >= 10)? 1 : 0;
    sum = sum%10;
    head->data = sum;

    temp = head;
    head = head->next;
  }
  if(carry>0){
    push(&res,carry);
  }
  return res;
}
void addone(Node* head){
  reverse(&head);
  head = addoneUtil(head);
  printList(head);
  return reverse(&head);
}
int main(){
  Node* head = new Node();
  head->data = 9;
  head->next = NULL;
  push(&head,9);
  push(&head,9);
  //push(&head,9);
  printList(head);
  addone(head);
  printList(head);
  return 0;
}
