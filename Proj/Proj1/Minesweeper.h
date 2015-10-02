/* 
 * File:   Minesweeper.h
 * Author: Himkw_000
 *
 * Created on October 1, 2015, 10:39 PM
 */

#ifndef MINESWEEPER_H
#define	MINESWEEPER_H
#include "bits/stdc++.h"
using namespace std;
class Minesweeper {
private: 
  struct Node{
    int data;
    Node *next;
    Node *prev;
    Node *up;
    Node *down;
  };
  int size;
  int row;
  int col;
  Node *head;
  Node *last;
  Node *temp;
  Node *work;
public:
  Minesweeper(){};
  Minesweeper(int row, int col);
  int &operator[] (const int&);
  int top(int);
  int bottom(int);
  ~Minesweeper();

};
Minesweeper::Minesweeper(int row, int col){
  this->size=row*col;
  this->row=row;
  this->col=col;
  head=last=temp=work = new Node;
  head->data=0;
  for(int i=1;i<row*col;i++){
    cout<<"for loop i = "<<i<<"\n";
    last->next = new Node;
    cout<<"Create Node "<<last->data+1<<endl;
    last->next->prev=last;
    last=last->next;
    last->data=i;
    cout<<"last move to "<<last->data<<endl;
    if((i)%col==0){
//        cout<<"i+1%col==0\n";
      cout<<last->data<<" connect to "<<temp->data<<endl;
      temp->down=last;
      temp->down->up=temp;
      temp=temp->down;
    }
  }
}
int &Minesweeper::operator[](const int& index){
  work=head;
  for(int i=0;i<index;i++){
    work=work->next;
  }
  return work->data;
}
int Minesweeper::top(int index){
  work=head;
  for(int i=0;i<index;i++){
    work=work->next;
  }
  cout<<"work = "<<work->data<<endl;
  cout<<"work up = "<<work->up->data<<endl;
  return work->up->data;
}
int Minesweeper::bottom(int index){
  work=head;
  for(int i=0;i<index;i++){
    work=work->next;
  }
  return work->down->data;
}
Minesweeper::~Minesweeper(){
  work=head;
  for(int i=0;i<row*col;i++){
    head=work;
    work=head->next;
    delete head;
  }
}

#endif	/* MINESWEEPER_H */

