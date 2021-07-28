#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

void printList(Node* head)
{
  while(head!=NULL){
    cout << head->data << "   ";
    head = head->next;
  }
}
int main(){
  Node* head = NULL;
  Node* sec = NULL;
  Node* third = NULL;

  head = new Node();
  sec = new Node();
  third = new Node();

  head -> data = 1;
  head -> next = sec;

  sec -> data = 2;
  sec -> next = third;

  third -> data = 3;
  third -> next = NULL;


  printList(head);
  return 0;

}
