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
    Node():data(0), next(NULL),prev(NULL),up(NULL),down(NULL){}
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
  Minesweeper(int, int);
  Minesweeper(int, int, bool);
  const int getSize(){return size;}
  const int getRow(){return row;}
  const int getCol(){return col;}
  int &operator[] (const int&);
  int top(int);
  int bottom(int);
  ~Minesweeper();

};
//only link first col and all row
Minesweeper::Minesweeper(int row, int col){
  this->size=row*col;
  this->row=row;
  this->col=col;
  head=last=temp=work = new Node;
  head->data=0;
  for(int i=1;i<row*col;i++){
//    cout<<"for loop i = "<<i<<"\n";
    last->next = new Node;
//    cout<<"Create Node "<<last->data+1<<endl;
    last->next->prev=last;
    last=last->next;
    last->data=i;
//    cout<<"last move to "<<last->data<<endl;
    if((i)%col==0){
//        cout<<"i+1%col==0\n";
//      cout<<last->data<<" connect to "<<temp->data<<endl;
      temp->down=last;
      temp->down->up=temp;
      temp=temp->down;
    }
  }
}
//all links
Minesweeper::Minesweeper(int row, int col, bool dum){
  this->size=row*col;
  this->row=row;
  this->col=col;
  head=last=temp=work = new Node;
  head->data=0;
  for(int i=1;i<row*col;i++){
//    cout<<"for loop i = "<<i<<"\n";
    last->next = new Node;
//    cout<<"Create Node "<<last->data+1<<endl;
    last->next->prev=last;
    last=last->next;
    last->data=i;
//    cout<<"last move to "<<last->data<<endl;
    if((i)%col==0){
//        cout<<"i+1%col==0\n";
//      cout<<last->data<<" connect to "<<temp->data<<endl;
      temp->down=last;
      temp->down->up=temp;
      temp=temp->down;
    }
  }
  //build all the link
  work=head;      //[i][j]
  temp=head->down;//[i+1][j]
  for(int i=0;i<row-1;i++){
    for(int j=0;j<col-1;j++){
      work=work->next;
      temp=temp->next;
      work->down=temp;
      work->down->up=work;
    }
    work=work->next;//change j to index 0
    temp=work->down;
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
//  cout<<"work = "<<work->data<<endl;
//  cout<<"work up = "<<work->up->data<<endl;
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

