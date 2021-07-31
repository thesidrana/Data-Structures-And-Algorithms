struct Node* partition(struct Node* head, int x) {
    struct Node* smallerHead = NULL, *smallerLast = NULL;
    struct Node* equalHead = NULL, *equalLast = NULL;
    struct Node* largerHead = NULL, *largerLast = NULL;
    //Iterate for every node in the list
    while(head){
        if(head->data == x){
            if(equalHead==NULL){
                equalHead = equalLast = head;
            }
            else{
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }
        else if(head->data < x){
            if(smallerHead==NULL){
                smallerHead = smallerLast = head;
            }
            else{
                smallerLast->next = head;
                smallerLast = smallerLast->next;
            }
        }
        else{
            if(largerHead==NULL){
                largerHead = largerLast = head;
            }
            else{
                largerLast->next = head;
                largerLast = largerLast->next;
            }
        }
        head = head->next;
    }
    if(largerHead){
        largerLast->next = NULL;
    }
    //Connecting
    if(smallerHead==NULL){
        if(equalHead==NULL){
            return largerHead;
        }
        else{
            equalLast->next = largerHead;
            return equalHead;
        }
    }
    if(equalHead==NULL){
        smallerLast->next = largerHead;
        return smallerHead;
    }
    smallerLast->next = equalHead;
    equalLast->next = largerHead;
    return smallerHead;
}
