/* 
 * File:   PriorityQueue.h
 * Author: Himkw_000
 *
 * Created on October 7, 2015, 7:30 PM
 */

#ifndef PRIORITYQUEUE_H
#define	PRIORITYQUEUE_H

#include <bits/stdc++.h>
using namespace std;

#include "Priority.h"

template <class T>
class PriorityQueue:public PriorityLnkLst<T>{
public:
  PriorityQueue():PriorityLnkLst<T>(){}
//  PriorityQueue(int size):PriorityLnkLst<T>(int size){}
  void prepend(){
    if(this->size>0){
      this->size--;
      if(this->size==0){
        delete this->head;
      }
      else{
        this->worker=this->head->next;
        delete this->head;
        this->head=this->worker;
      }
    }
  }
};

#endif	/* PRIORITYQUEUE_H */

