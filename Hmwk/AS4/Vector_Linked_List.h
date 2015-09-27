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

//第一個node必需分開建立
template <class T>
class Vect{
public:
  //default constructor
  Vect(){
    size=0;
    current_size=0;
  }
  //constructor only size
  Vect(int size);
  //constructor size and initial value
  Vect(int size, T data);
  //Destructor
  ~Vect();
  // overloading []operator
  T &operator[](const int &index);
  void push_back(T data);
  void pop_up();
  //get current size
  int getSize(){return current_size;}
  //get actual size
  int getMaxSize(){return size;}
  
private:
  struct Node{
    T data;     //store value
    Node *next;   //store next node address
  };
  Node *head;        //store the first node address
  Node *last;        //store last node address 附加時不用再loop
  Node *worker;      //current node address
  int size;          //num of nodes created
  int current_size; //
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
    current_size=size;
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
  current_size=size;
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
  if(index<0 || index>=current_size){
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
void Vect<T>::push_back(T data){
  if(current_size<size){
//    cout<<"change value only\n";
//      cout<<"current last value = "<<last->data<<endl;
    last=last->next;
    last->data=data;
  }
  //create more
  else{
    if(size==0){
      size=10;        //create 10
      current_size=0; //will add one at the end;
      Node *clink = new Node;  //create the first Node
      clink->data=data;
      head=clink;
      last=clink;
    }
    else{
//      cout<<"double size\n";
      //add the first one and input the value
      last->next = new Node;
      last=last->next;  //update last address
      last->data=data;
    }
      worker=last;      //copy last address to create more
      //add size-1 more at the end
      for(int i=1;i<size;i++){
        //last should be the vect[current_address] address
        worker->next = new Node();
        worker=worker->next;
      }
      if(current_size>1)size*=2;    //only double if not the first one
  }
  //update current_size
  current_size++;
}
template <class T>
void Vect<T>::pop_up(){
//    cout<<"pop up funtion\n";
  if(current_size>0){
    current_size--;
    //update last

    last=head;
    for(int i=0;i<current_size-1;i++){
      last=last->next;
    }
  }
}
#endif	/* VECTOR_LINKED_LIST_H */

