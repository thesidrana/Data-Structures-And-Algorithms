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

void detectLoop(Node* head, Node** slow, Node** fast, Node** prev){
        while((*slow) && (*fast) &&(*fast)->next){
            (*slow) = (*slow)->next;
            (*prev) = (*fast)->next;
            (*fast) = (*fast)->next->next;
            if((*slow)==(*fast)){
                break;
            }
        }
    }
    void removeLoop(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        detectLoop(head,&slow,&fast,&prev);
        prev->next = NULL;
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
  cout << removeLoop(head) <<endl;
  return 0;
}
