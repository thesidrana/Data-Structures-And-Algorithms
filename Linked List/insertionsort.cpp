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
void sortedInsert(Node** head_ref, Node* new_node){
    Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
      //For first element or if the element to be inserted is smaller than the head ref
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        current = *head_ref;
        while (current->next!=NULL && current->next->data < new_node->data)
        {
          //Move till the last element or where the data of new node becomes larger than pre existing data.
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}
void insertionSort(Node **head_ref)
{
    Node *sorted = NULL; //Creating new linked list to store result
    Node *current = *head_ref; //Current Pointer starts from the head
    while (current != NULL)
    {
        Node *next = current->next; //Next of current is remembered.
        sortedInsert(&sorted, current);//Current is inserted to new linked list in sorted manner
        current = next; //The next element is now current
    }
    *head_ref = sorted; //The head of the linked list is changed to the head of new linkedlist.
}
int main(){
  Node* head = new Node();
  head->data = 7;
  head->next = NULL;
  push(&head,3);
  push(&head,5);
  push(&head,1);
  push(&head,2);
  push(&head,6);
  push(&head,4);

  printList(head);
  insertionSort(&head);
  printList(head);
  return 0;
}
