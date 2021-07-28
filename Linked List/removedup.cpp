#include<iostream>
using namespace std;

Node *removeDuplicates(Node *head)
{
 while(head!=NULL && head->next!=NULL){
     Node* start = head;
     if(start==NULL || start->next==NULL){
         return start;
     }
     else if(head->data==head->next->data){
         head->next = head->next->next;
     }
     else{
         head=head->next;
     }
     return start;
 }
}
