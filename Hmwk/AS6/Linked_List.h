/* 
 * File:   Linked_List.h
 * Author: Himkw_000
 *
 * Created on September 29, 2015, 10:00 AM
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H
#include "bits/stdc++.h"
using namespace std;

template <class T>
class LnkLst{
protected:
  struct Node{
    T data;
    Node *next;
    Node *prev;
    Node():data(0), next(NULL), prev(NULL){}
  };
  int size;
  Node *head;
  Node *last;
  Node *worker;
  void subError(){
//    cout<<"ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
  }
  void empError() {
//    cout<<"ERROR: out of range\n";
    exit(EXIT_FAILURE);
  }
 public:
    LnkLst(){size=0;}
//  LnkLst(int);
    LnkLst(int, bool);
    void append(T);
    void prepend(T);
    int getSize(){return size;}
    T &operator[](const int&);
    ~LnkLst();
    T previous(int);
    T next(int);
    void pop();
};

template <class T>
LnkLst<T>::LnkLst(int size, bool doubly){
  this->size=size;
  if(size>0){
    head = new Node;
//    head->next=NULL;
    worker=head;
//    worker->prev=NULL;
    for(int i=1;i<size;i++){
      worker->next = new Node;
      //point to previous
      doubly?worker->next->prev=worker:worker->next->prev=NULL;  
      worker=worker->next;
    }
    doubly?worker->next=NULL:worker->next=head;
    last=worker;
    head->prev=last;
  }
}
template <class T>
void LnkLst<T>::append(T data){
  if(size>0){
    last->next=new Node;
    last->next->prev=last;
    last=last->next;
    last->data=data;
  }
  else{
    head=last=new Node;
    head->data=data;
  }
  size++;
}
template <class T>
void LnkLst<T>::prepend(T data){
  if(size==0){
    head=last = new Node;
    head->data=data;
  }
  else{
    worker = new Node;
    worker->data = data;
    worker->next=head;
    head=worker;
  }
  size++;
//  if(size>0){
//    size--;
//    worker=head;
//    if(size==0){
//      delete head;
//    }
//    else{
//      for(int i=0;i<size-1;i++){
//        worker=worker->next;
//      }
//      delete worker->next;
//    }
//  }
//  else empError();
}

template <class T>
LnkLst<T>::~LnkLst(){
  if(size>0){
    delete head;    //刪除指向的內存
  }
  else{
    for(int i=0;i<size;i++){
      worker=head->next;    //先暫存下一個node
      delete head;          //把第一個刪除
      head=worker;          //把下一個設為第一個
    }
  }
}
template <class T>
T &LnkLst<T>::operator [](const int& index){
  if(index<0 || index>=size){
    subError();
  }
  else{
    worker=head;
    for(int i=0;i<index;i++){
      worker=worker->next;
    }
    return worker->data;
  }
}
template <class T>
T LnkLst<T>::previous(int index){
  if(index<1 || index>=size){
    subError();
  }
  else{
    worker=head;
    for(int i=0;i<index;i++){
      worker=worker->next;
    }
    return worker->prev->data;
  }
}
template <class T>
T LnkLst<T>::next(int index){
  if(index<0 || index>=size){
    subError();
  }
  else{
    worker=head;
    for(int i=0;i<index;i++){
      worker=worker->next;
    }
    return worker->next->data;
  }
}

template <class T>
void LnkLst<T>::pop(){
  if(size>0){
    size--;
    worker=head;
    if(size==0){
      delete head;
    }
    else{
      for(int i=0;i<size-1;i++){
        worker=worker->next;
      }
      delete worker->next;
    }
  }
  else empError();  
}
#endif	/* LINKED_LIST_H */

