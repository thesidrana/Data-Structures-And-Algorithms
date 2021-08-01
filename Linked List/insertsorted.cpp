Node *sortedInsert(struct Node* head, int data) {
        Node* current;
        Node* new_node = new Node(data);
    if (head == NULL || head->data >= new_node->data) {
        new_node->next = head;
        head= new_node;
    }
    else {
        current = head;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        }
    return head;    
    }
