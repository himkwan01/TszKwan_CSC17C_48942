/* 
 * File:   Linked_List.h
 * Author: Himkw_000
 *
 * Created on September 29, 2015, 10:00 AM
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H
#include "bits/stdc++.h"
class LnkLst{
public:
  LnkLst();
  LnkLst(int);
  LnkLst(int, int);
private:
  struct Node{
    int data;
    Node *next;
    Node *prev;
  };
  int size;
  Node *head;
  Node *last;
  Node *worker;
};
LnkLst::LnkLst(int size, bool doubly){
  this->size=size;
  if(size>0){
    head = new Node;
    head->next=NULL;
    worker=head;
    worker->prev=NULL;
    for(int i=1;i<size;i++){
      worker->next = new Node;
      worker->next->prev=worker;  //point to previous
      worker=worker->next;
    }
    doubly?worker->next=NULL:worker->next=head;
    last=worker;
    head->prev=last;
  }
}
#endif	/* LINKED_LIST_H */

