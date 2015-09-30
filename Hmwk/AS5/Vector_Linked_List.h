/* 
 * File:   Vector_Linked_List.h
 * Author: Himkw_000
 *
 * Created on September 26, 2015, 5:19 PM
 */

#ifndef VECTOR_LINKED_LIST_H
#define	VECTOR_LINKED_LIST_H

#include "bits/stdc++.h"
using namespace std;
/*
 * First and Last Functions
 * Prepend
 * Append
 * Copy Constructor and Assignment Operator
 * Extract
 * InsertAfter and InsertBefore
 */
//第一個node必需分開建立
template <class T>
class Vect{
public:
  //default constructor
  Vect(){
    size=0;
  }
  //constructor only size
  Vect(int size);
  //constructor size and initial value
  Vect(int size, T data);
//  Vect(Vect<T>);
  //Destructor
  virtual~Vect();
  // overloading []operator
  T &operator[](const int &index);
  void append(T data);
  void prepend();
  //get actual size
  int getSize(){return size;}
  T first();
  T rear();
  void insert_after(int index, T data);
  void insert_before(int index, T data);
private:
  struct Node{
    T data;     //store value
    Node *next;   //store next node address
  };
  Node *head;        //store the first node address
  Node *last;        //store last node address 附加時不用再loop
  Node *worker;      //current node address
  int size;          //num of nodes created
  void subError(){
    cout<<"ERROR: Subscript out of range.\n";
    exit(EXIT_FAILURE);
  }
  void empError() {
    cout << "ERROR: out of range\n";
    exit(EXIT_FAILURE);
  }
};
template <class T>
Vect<T>::Vect(int size){
  if(size>0){
    this->size=size;
    //create first Node
    head = new Node;
    head->next=NULL; //set next address to null
    last = head;
    //create the rest
    for(int i=1;i<size;i++){
      last->next=new Node;
      last=last->next;
    }
  }
  else{
    empError();
  }
}
template <class T>
Vect<T>::Vect(int size, T data){
  this->size=size;
  //create first Node
  head = new Node;
  head->data=data;
  head->next=NULL;
  last=head;
  //create the rest
  for(int i=1;i<size;i++){
    last->next = new Node;
    last=last->next;
    last->data=data;
    last->next=NULL;
  }
}
//template <class T>
//Vect<T>::Vect(Vect<T> a){
//  this=a;
//}
template <class T>
Vect<T>::~Vect(){
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
T &Vect<T>::operator [](const int& index){
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
void Vect<T>::append(T data){
  cout<<"append function/n";
  last->next=new Node;
  last=last->next;
  last->next=NULL;
  last->data=data;
  size++;
}
template <class T>
void Vect<T>::prepend(){
  cout<<"prepend function\n";
  if(size>0){
    size--;
    worker=head;
    for(int i=0;i<size-1;i++){
      worker=worker->next;
    }
    delete worker->next;
  }
  else empError();
}
template <class T>
T Vect<T>::first(){
  return head->data;
}
template <class T>
T Vect<T>::rear(){
  return last->data;
}
template <class T>
void Vect<T>::insert_after(int index, T data){
  if(index>size-1||index<0){
    empError();
  }
  else{
    worker=head;
    for(int i=0;i<index;i++){
      worker=worker->next;
    }
    if(index==size-1){
      last=worker;
      worker->next = new Node;
      worker=worker->next;
      worker->data=data;
      last=worker;
    }
    else{
      //save current worker->next
      Node *temp=worker->next;
      worker->next = new Node;
      worker=worker->next;
      worker->data=data;
      worker->next=temp;
    }
    size++;
  }
}
template <class T>
void Vect<T>::insert_before(int index, T data){
  if(index>size-1||index<0){
    empError();
  }
  else{
    if(index==0){
      Node *temp=head;
      head = new Node;
      head->data=data;
      head->next=temp;
    }
    else{
      worker=head;
      for(int i=0;i<index-2;i++){
        worker=worker->next;
      }
      Node *temp=worker->next;
      worker->next=new Node;
      worker=worker->next;
      worker->data=data;
      worker->next=temp;
    }
    size++;
  }
}

#endif	/* VECTOR_LINKED_LIST_H */

