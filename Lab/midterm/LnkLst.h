/* 
 * File:   LnkLst.h
 * Author: Himkw_000
 *
 * Created on October 27, 2015, 4:36 PM
 */

#ifndef LNKLST_H
#define	LNKLST_H
#include <bits/stdc++.h>
using namespace std;
template <class T>
class LnkLst{
protected:
  struct Node{
    T data;
    Node* next;
//    Node *prev;
  };
  int asize;
  Node *head;
  Node *last;
  Node *work;
  Node *temp;
public:
  LnkLst(){asize=0;head=last=0;}
  LnkLst(int);
  ~LnkLst();
  T &operator[](const int&);
  void append(int);
  int size(){return asize;}
};

//create and fill
template <class T>
LnkLst<T>::LnkLst(int asize){
  srand(time(0));
  this->asize=asize;
  if(asize>0){
    head = last = new Node;
    head->data = rand()%6;
//    head->prev = NULL;
    for(int i=1;i<asize;i++){
      last->next = new Node;
//      last->next->prev = last;
      last=last->next;
      last->data = rand()%6;
    }
    last->next=NULL;
  }
}

template <class T>
T &LnkLst<T>::operator [](const int& index){
    work=head;
    for(int i=0;i<index;i++){
      work=work->next;
    }
    return work->data;
}
template <class T>
void LnkLst<T>::append(int data){
  if(asize>0){
    last->next=new Node;
//    last->next->prev = last;
    last=last->next;
    last->data=data;
    last->next = NULL;
  }
  else{
    head=last=new Node;
    head->data=data;
//    last->prev = NULL;
    head->next = NULL;
  }
  asize++;
}
template <class T>
LnkLst<T>::~LnkLst(){
  if(asize>0){
    delete head;    //刪除指向的內存
  }
  else{
    for(int i=0;i<asize;i++){
      work=head->next;    //先暫存下一個node
      delete head;          //把第一個刪除
      head=work;          //把下一個設為第一個
    }
  }
}
#endif	/* LNKLST_H */

