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
    void insert(T);
    int getSize(){return size;}
    T &operator[](const int&);
    ~LnkLst();
    void pop();
};

template <class T>
void LnkLst<T>::insert(T data){
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

