void reverse(Node** head){
    Node* current = (*head);
    Node* prev = NULL;
    Node* nextn = NULL;
    while(current){
        nextn = current->next;
        current->next = prev;
        prev = current;
        current= nextn;
    }
    (*head) = prev;
}
long long unsigned int decimalValue(Node *head)
{
   reverse(&head);
   int mult = 1;
   Node* temp = head;
   long long unsigned int sum= 0;
   while(temp){
       sum += ((temp->data)*mult);
       sum %= 1000000007;
       mult *= 2;
       temp = temp->next;
   }
   return sum%1000000007;
}
