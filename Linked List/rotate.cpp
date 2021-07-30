Node* rotate(Node* head, int k)
    {
        Node* end = head;
        while(end->next){
            end = end->next;
        }
        end->next = head;
        Node* temp = NULL;
        for(int i =1; i <= k;i++){
            temp = head;
            head = head->next;
        }
        temp->next = NULL;
        return head;
    }
};
