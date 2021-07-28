include<bits/stdc++.h>
using namespace std;

Node *copyList(Node *head) {
    Node* current = head, *temp;
    while(current){
        temp = current->next;
        current->next = new Node(current->data);
        current->next->next = temp;
        current = temp;
    }
    current = head;
    while(current){
        if(current->next){
            current->next->arb = current->arb? current->arb->next: current->arb;
        }
        current = current->next?current->next->next:current->next;
    }
    Node* original = head, *copy = head->next;
    temp = copy;
    while(original && copy){
        original->next = original->next?original->next->next:original->next;
        copy->next = copy->next? copy->next->next: copy->next;
        original = original->next;
        copy = copy->next;
    }
    return temp;
}
