/* 
 * File:   Stack.h
 * Author: Himkw_000
 *
 * Created on October 7, 2015, 11:26 AM
 */

#ifndef STACK_H
#define	STACK_H
#include <bits/stdc++.h>
#include "Linked_List.h"
using namespace std;
template <class T>
class Stack:public LnkLst<T>{
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
////    cout<<"ERROR: Subscript out of range.\n";
//    exit(EXIT_FAILURE);
//  }
//  void empError() {
////    cout<<"ERROR: out of range\n";
//    exit(EXIT_FAILURE);
//  }
public:
  Stack():LnkLst<T>(){}
  Stack(int size):LnkLst<T>(size, false){}
  ~Stack(){}
//  T &operator[](const int &index);
//  void append(T);
//  void prepend();
//  int getSize(){return size;}
};

//template <class T>
//Stack<T>::Stack(int size):LnkLst<T>(size){
////  if(size>0){
//////    this->size=size;
////    head=last=new Node;
////    for(int i=1;i<size;i++){
////      last->next=new Node;
////      last=last->next;
////    }
////  }
////  else{
////    empError();
////  }
//}
//template <class T>
//Stack<T>::~Stack(){}
//template <class T>
//T &Stack<T>::operator [](const int& index){
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
//void Stack<T>::append(T data){
//  last->next=new Node;
//  last=last->next;
//  last->data=data;
//  size++;
//}
//template <class T>
//void Stack<T>::prepend(){
//  if(size>0){
//    size--;
//    work=head;
//    for(int i=0;i<size-1;i++){
//      work=work->next;
//    }
//    delete work->next;
//  }
//  else empError();
//}

#endif	/* STACK_H */

