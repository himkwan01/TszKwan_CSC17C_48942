/* 
 * File:   SortedLnkLst.h
 * Author: Himkw_000
 *
 * Created on October 7, 2015, 7:30 PM
 */

#ifndef SORTEDLNKLST_H
#define	SORTEDLNKLST_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
class SortLnkLst{
public:
  SortLnkLst(){size=0;head=last=worker=0;}
  SortLnkLst(int size);
  ~SortLnkLst();
  T &operator[](const int &);
  void sort();
  void append(T);
  void prepend();
  int getSize(){return size;}
  private:
    struct Node{
      T data;
      Node *next;
      Node():data(0), next(NULL){}
    };
    Node *head;
    Node *last;
    Node *worker;
    int size;
    void subError(){
      cout<<"ERROR: Subscript out of range.\n";
      exit(EXIT_FAILURE);
    }
    void empError() {
      cout<<"ERROR: out of range\n";
      exit(EXIT_FAILURE);
    }
};

template <class T>
SortLnkLst<T>::SortLnkLst(int size){
  this->size=size;
  if(size>0){
    head=last=new Node;
    for(int i=1;i<size;i++){
      last->next=new Node;
      last=last->next;
    }
  }
}

template <class T>
SortLnkLst<T>::~SortLnkLst(){
  if(size>0){
    for(int i=0;i<size-1;i++){
      worker=head->next;
      delete head;
      head=worker;
    }
    delete head;
  }
}

template <class T>
T &SortLnkLst<T>::operator [](const int &index){
  if(index<0 || index>size-1){
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
void SortLnkLst<T>::sort(){
  bool swap=true;
  T temp;
  do{
    swap=false;
    for(int i=0;i<size-1;i++){
      if(operator[](i)>operator[](i+1)){
        swap=true;
        temp=operator[](i);
        operator[](i)=operator[](i+1);
        operator[](i+1)=temp;
      }
    }
  }while(swap);
}

template <class T>
void SortLnkLst<T>::append(T data){
  if(size==0){
    head=last=new Node;
    head->data=data;
  }
  else{
    last->next=new Node;
    last=last->next;
    last->data=data;
  }
  size++;
  sort();
}

template <class T>
void SortLnkLst<T>::prepend(){
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

#endif	/* SORTEDLNKLST_H */

