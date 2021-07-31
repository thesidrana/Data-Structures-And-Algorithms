/*
Given 2 polynomials in the form of linked lists, add them.
*/

Node* addPolynomial(Node *p1, Node *p2)
    {
        Node* head = new Node(0,0);
        Node* res = head;
        if(p1&&!p2) return p1;
        if(!p1&&p2) return p2;
        while(p1 && p2){
            if(p1->pow == p2->pow){
                res->next = new Node(p1->coeff + p2->coeff, p1->pow);
                res = res->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p1->pow > p2->pow){
                res->next = new Node(p1->coeff, p1->pow);
                res = res->next;
                p1 = p1->next;
            }
            else{
                res->next = new Node(p2->coeff, p2->pow);
                res = res->next;
                p2 = p2->next;
            }
        }
        while(p1){
            res->next = new Node(p1->coeff, p1->pow);
            res = res->next;
            p1 = p1->next;
        }
        while(p2){
            res->next = new Node(p2->coeff, p2->pow);
            res = res->next;
            p2 = p2->next;
        }
        res->next = NULL;
        return head->next;
    }
