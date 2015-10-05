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

/**
 * Minesweeper version 1
 * single player
 * normal game mode 
 * only expert level 
 * size = 16x30
 * mine = 99
 */

class Minesweeper {
private:
  struct Node {
    int data;
    char cdata;
    Node *next;
    Node *prev;
    Node *up;
    Node *down;

    Node() : data(0), cdata('0'),next(NULL), prev(NULL), up(NULL), down(NULL) {
    }
  };
  int size;
  int row;
  int col;
  Node *head;
  Node *last;
  Node *temp;
  Node *work;
public:
  //default constructor
  Minesweeper() {};
  /**
   * Constructor version 1
   * doubly linked list
   * only first col has vertical pointers connected
   * @param row
   * @param col
   */
  Minesweeper(int row, int col);
  /**
   * Constructor version 2
   * doubly linked list
   * all node has vertical pointers connected
   * expand version 1, add one more for loop to link vertically
   * @param row
   * @param col
   * @param dum
   */
  Minesweeper(int row, int col, bool dum);
  /**
   * Constructor version 3
   * doubly linked list
   * do the same thing as version 2
   * combine for loops together
   * create and link horizontally and vertically at the same time
   * @param row
   * @param col
   * @param dum1
   * @param dum2
   */
  Minesweeper(int, int, int dum1, int dum2);
  /**
   * generate mines on board
   * @param number of mines
   */
  void genMine(int num);
  const int getSize() {return size;}
  const int getRow() {return row; }
  const int getCol() {return col;}
  //overloading operator []
  int &operator[](const int&);
  //a function to get the value above current index
  int top(int);
  //a function to get the value under current index
  int bottom(int);
  //Destructor
  ~Minesweeper();

};
//only link first col and all row

Minesweeper::Minesweeper(int row, int col) {
  this->size = row*col;
  this->row = row;
  this->col = col;
  head = last = temp = work = new Node;
  head->data = 0;
  for (int i = 1; i < row * col; i++) {
    //    cout<<"for loop i = "<<i<<"\n";
    last->next = new Node;
    //    cout<<"Create Node "<<last->data+1<<endl;
    last->next->prev = last;
    last = last->next;
    last->data = i;
    //    cout<<"last move to "<<last->data<<endl;
    if ((i) % col == 0) {
      //        cout<<"i+1%col==0\n";
      //      cout<<last->data<<" connect to "<<temp->data<<endl;
      temp->down = last;
      temp->down->up = temp;
      temp = temp->down;
    }
  }
}
//all links

Minesweeper::Minesweeper(int row, int col, bool dum) {
  this->size = row*col;
  this->row = row;
  this->col = col;
  head = last = temp = work = new Node; //create first node
  head->data = 0; //initial value
  for (int i = 1; i < size; i++) {
    //    cout<<"for loop i = "<<i<<"\n";
    last->next = new Node; //create all node
    //    cout<<"Create Node "<<last->data+1<<endl;
    last->next->prev = last; //connect left and right
    last = last->next;
    last->data = i;
    //    cout<<"last move to "<<last->data<<endl;
    if ((i) % col == 0) {
      //        cout<<"i+1%col==0\n";
      //      cout<<last->data<<" connect to "<<temp->data<<endl;
      temp->down = last;
      temp->down->up = temp;
      temp = temp->down;
    }
  }
  //build all the link
  work = head; //[i][j]
  temp = head->down; //[i+1][j]
  for (int i = 0; i < row - 1; i++) {
    for (int j = 0; j < col - 1; j++) {
      work = work->next; //move to j+1
      temp = temp->next; //move to j+1
      work->down = temp; //upper one point to bottom
      work->down->up = work; //bottom one point to top
    }
    work = work->next; //move work to next line first addr
    temp = work->down; //move temp to the one under work
  }
}

Minesweeper::Minesweeper(int row, int col, int dum1, int dum2) {
  int count=1;
  this->size = row*col;
  this->row = row;
  this->col = col;
  head = last = temp = work = new Node;
  head->data = 0;
//  cout << "last = " << last->data << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      //j=0
      if (!(i == 0 && j == 0)) {
        last->next = new Node;
        count++;
        last->next->prev = last;
        last = last->next;
        last->data = (i * col + j);
        //        cout<<"i = "<<i<<" j = "<<j<<endl;
        //        cout<<"last = "<<last->data<<"\n";
        if (i > 0) {
          //          cout<<"temp = "<<temp->data<<"\n\n";
          //          cout<<"last = "<<last->data<<endl;
          temp->down = last;
          temp->down->up = temp;
          temp = temp->next;
        }
      }
    }
  }
//  cout<<count<<endl;
}

void Minesweeper::genMine(int num){
  int x,y;    //x and y coordinates
  for(int i=0;i<num;i++){
    x=rand()%16;
    y=rand()%30;
    //how to call itself (this?) obj[x*30+y]
    //if()
    [x*col+y]=-1;
  }
} 

int &Minesweeper::operator[](const int& index) {
//  cout<<"call index function\n";
  work = head;
  for (int i = 0; i < index; i++) {
    work = work->next;
  }
//  cout<<"in function "<<work->data<<endl;
  return work->data;
}

int Minesweeper::top(int index) {
  work = head;
  for (int i = 0; i < index; i++) {
    work = work->next;
  }
  //  cout<<"work = "<<work->data<<endl;
  //  cout<<"work up = "<<work->up->data<<endl;
  return work->up->data;
}

int Minesweeper::bottom(int index) {
  work = head;
  for (int i = 0; i < index; i++) {
    work = work->next;
  }
  return work->down->data;
}

Minesweeper::~Minesweeper() {
//    cout<<"here."<<endl;
    work=head;
    //delete stop before the last node
    for(int i=0;i<size-1;i++){
      head=work;
      work=head->next;
//      cout<<head->data<<endl;
      delete head;
    }
    delete work;
//
//  int count=0;
//  while (!head == 0) {
//    work = head->next;
////    cout<<head->data<<endl;
//    delete head;
//    count++;
//    head = work;
//  }
//  cout<<count<<endl;
}

#endif	/* MINESWEEPER_H */

