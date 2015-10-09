/* 
 * File:   Queue.h
 * Author: Himkw_000
 *
 * Created on October 7, 2015, 11:26 AM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include <bits/stdc++.h>
#include "Linked_List.h"
using namespace std;

template <class T>
class Queue:public LnkLst<T>{
private:
//  struct Node{
//    T data;
//    Node *next;
//    Node():data(0), next(NULL){}
//  };
//  Node *head;
//  Node *last;
//  Node *work;
//  int size;
//  void subError(){
//    cout<<"ERROR: Subscript out of range.\n";
//    exit(EXIT_FAILURE);
//  }
//  void empError() {
//    cout<<"ERROR: out of range\n";
//    exit(EXIT_FAILURE);
//  }
public:
  Queue():LnkLst<T>(){}
  Queue(int size):LnkLst<T>(size, false){}
  ~Queue(){}
//  T &operator[](const int &index);
//  void append(T);
  void prepend();
//  int getSize(){return size;}
};

//template <class T>
//Queue<T>::Queue(int size){
//  cout<<"queue constructor\n";
//  if(size>0){
//    this->size=size;
//    cout<<"size = "<<this->size<<endl;
//    head=last=new Node;
//    for(int i=1;i<size;i++){
//      last->next=new Node;
//      last=last->next;
//    }
//  }
//  else{
//    empError();
//  }
//}
//template <class T>
//T &Queue<T>::operator [](const int& index){
//  if(index<0 || index>=size){
//    subError();
//  }
//  else{
//    work=head;
//    for(int i=0;i<index;i++){
//      work=work->next;
//    }
//    return work->data;
//  }
//}

//template <class T>
//void Queue<T>::append(T data){
//  last->next=new Node;
//  last=last->next;
//  last->data=data;
//  size++;
//}
template <class T>
void Queue<T>::prepend(){
  if(this->size>0){
    this->size--;
    this->worker=this->head;
    if(this->size==0){
      delete this->head;
    }
    else{
      this->worker=this->head->next;
      delete this->head;
      this->head=this->worker;
    }
  }
//  
//  this->worker=this->head->next;
//  delete this->head;
//  this->head=this->worker;
//  this->size--;
}
#endif	/* QUEUE_H */

