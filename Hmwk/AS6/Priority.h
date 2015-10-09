/* 
 * File:   Priority.h
 * Author: Himkw_000
 *
 * Created on October 7, 2015, 3:16 PM
 */

#ifndef PRIORITY_H
#define	PRIORITY_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
class PriorityLnkLst{
protected:
  struct Node{
    T data;
    Node *next;
    Node():data(0), next(NULL){}
  };
  int size;
  Node *head;
  Node *worker;
  Node *last;
  void subError(){
    cout<<"ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
  }
  void empError() {
    cout<<"ERROR: out of range\n";
    exit(EXIT_FAILURE);
  }
public:
  PriorityLnkLst(){size=0;head=worker=last=NULL;}
  void append(T);
  void prepend();
  int getSize(){return size;}
  ~PriorityLnkLst();
  T &operator[](const int &);
  void find(T);
};

template <class T>
void PriorityLnkLst<T>::append(T data){
  if(size!=0){
    worker=new Node;
    worker->data=data;
    worker->next=head;
    head=worker;
  }
  else{
    head=last=new Node;
    head->data=data;
  }
  size++;
}

template <class T>
void PriorityLnkLst<T>::prepend(){
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

template <class T>
PriorityLnkLst<T>::~PriorityLnkLst(){
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
T &PriorityLnkLst<T>::operator[](const int& index){
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
void PriorityLnkLst<T>::find(T data){
  worker=head;
  for(int i=0;i<size-1;i++){
    if(worker->next->data==data){
      Node *temp=worker->next;
      worker->next=temp->next;
      temp->next=head;
      head=temp;
    }
    else{
      worker=worker->next;
    }
  }
}
#endif	/* PRIORITY_H */

