/*
Given a singly linked list, your task is to remove every kth node from the linked list.
*/
Node* deleteK(Node *head,int k)
{
    if (head == NULL)
        return NULL;
 
    if (k == 1)
    {
       return NULL;
    }
    struct Node *ptr = head, *prev = NULL;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        if (k == count)
        {
            delete(prev->next);
            prev->next = ptr->next;
            count = 0;
        }
        if (count != 0)
            prev = ptr;
        ptr = prev->next;
    }
    return head;
}
