/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
*/
// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

Node* merge(Node *a, Node*b){
    if(!a) return b;
    if(!b) return a;
    Node* res;
    if(a->data < b->data){
        res = a;
        res->bottom = merge(a->bottom,b);
    }
    else{
        res = b;
        res->bottom = merge(a,b->bottom);
    }
    res->next = NULL;
    return res;
}    
Node *flatten(Node *root)
{
   if(!root || !(root->next)) return root;
   return merge(root,flatten(root->next));
}

