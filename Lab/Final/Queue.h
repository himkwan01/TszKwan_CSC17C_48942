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
public:
  Queue():LnkLst<T>(){}
  Queue(int size):LnkLst<T>(size, false){}
  ~Queue(){}
  T pop();
};

template <class T>
T Queue<T>::pop(){
  T t=0;
  if(this->size>0){
    t=this->head->data;
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
  return t;
}
#endif	/* QUEUE_H */

