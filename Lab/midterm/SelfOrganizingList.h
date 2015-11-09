/* 
 * File:   SelfOrganizingList.h
 * Author: Himkw_000
 *
 * Created on October 29, 2015, 11:00 AM
 */

#ifndef SELFORGANIZINGLIST_H
#define	SELFORGANIZINGLIST_H
#include <bits/stdc++.h>
using namespace std;
#include "LnkLst.h"

template <class T>
class SelfOrganizingList:public LnkLst<T>{
public:
  SelfOrganizingList():LnkLst<T>(){}
  SelfOrganizingList(int size):LnkLst<T>(size){}
  bool find(T);
};

template <class T>
bool SelfOrganizingList<T>::find(T data){
  bool chk=false;
  this->work = this->head;
  while(this->work->next!=NULL){
    if(this->work->next->data==data){
      chk=true;
      //move to front;
      this->temp = this->work->next;
      this->work->next = this->temp->next;
      this->temp->next = this->head;
      this->head = this->temp;
    }
    else{
      this->work = this->work->next;
    }
  }
  return chk;
}

#endif	/* SELFORGANIZINGLIST_H */

