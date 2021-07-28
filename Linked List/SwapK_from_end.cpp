/*
Given a singly linked list of size N, and an integer K. 
You need to swap the Kth node from the beginning and Kth node from the end of the linked list. 
Swap the nodes through the links. Do not change the content of the nodes.
*/

Node *swapkthnode(Node* head, int num, int k)
{
    int n = 0;
    Node* temp = head;
    while(temp){
        n++;
        temp = temp->next;
    }
    if(k>n) return head;
    if(2*k-1 == n) return head;
    Node* start = head;
    Node* start_prev = NULL;
    for(int i = 1; i < k;i++){
        start_prev = start;
        start = start->next;
    }
    Node* end = head;
    Node* end_prev = NULL;
    for(int i = 1; i < n-k+1;i++){
        end_prev = end;
        end = end->next;
    }
    if(start_prev){
        start_prev->next = end; 
    }
    if(end_prev){
        end_prev->next = start;
    }
    temp = start->next;
    start->next = end->next;
    end->next = temp;
    if(k==1){
        return end;
    }
    if(k==n){
        return start;
    }
    return head;
}
