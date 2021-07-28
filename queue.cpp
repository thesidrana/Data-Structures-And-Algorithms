#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node* next;
};

void enqueue(Node** head, int new_data){
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = (*head);
  (*head) = new_node;

}
int dequeue(Node* head){
  while(head->next->next != NULL){
    head = head->next;
  }
  head->next = NULL;
  return head->data;
}
void printQueue(Node* head){
  while(head!=NULL){
    cout << head->data << "   ";
    head = head->next;
  }
  cout << endl;
}
int main(){
  Node* head = new Node();
  head->data = 7;
  head->next = NULL;
  enqueue(&head,6);
  enqueue(&head,5);
  enqueue(&head,4);
  enqueue(&head,3);
  enqueue(&head,2);
  enqueue(&head,1);

  printQueue(head);
  cout << "Dequeue #1" <<endl;
  dequeue(head);
  printQueue(head);
  cout << "Dequeue #2" <<endl;
  dequeue(head);
  printQueue(head);
  cout << "Dequeue #3" <<endl;
  dequeue(head);
  printQueue(head);
  delete head;
  return 0;
}
