/*
Given a linked list and positions m and n.
Reverse the linked list from position m to n.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* next;
}

Node* reverse(Node* head){
  Node* current = head, *prev = NULL, *nextn = NULL;
  while(current){
    nextn = current->next;
    current->next = prev;
    prev = current;
    current = nextn;
  }
  return prev;
}

Node* convert(Node* head, int m, int n){
  if(m==n) return head;
  Node* revs = NULL, *revspre = NULL;
  Node* revend = NULL, *revendnext = NULL;
  int i = 1;
  Node* current = head;
  while(i <= n && current){
    if(i<m){
      revspre = current;
    }
    if(i==m){
      revs = current;
    }
    if(i==n){
      revend = current;
      revendnext = current->next;
    }
    current = current->next;
    i++;
  }
  revend->next = NULL;
  revend = reverse(revs);
  if(revspre){
    revspre->next = revend;
  }
  else{
    head = revend;
  }
  revs->next = revendnext;
  return head;
}
