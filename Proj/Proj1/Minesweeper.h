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
    int index;
    char data;
    Node *next;
    Node *prev;
    Node *up;
    Node *down;

    Node() : index(0), data(' '),next(NULL), prev(NULL), up(NULL), down(NULL) {
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
  int getSize() {return size;}
  int getRow() {return row;}
  int getCol() {return col;}
  //overloading operator []
  char &operator[](const int&);
  char top_left(int index){return operator[](index-col-1);}
  char top(int index){return operator[](index-col);}
  char top_right(int index){return operator[](index-col+1);}
  char left(int index){return operator[](index-1);}
  char right(int index){return operator[](index+1);}
  char bottom_left(int index){return operator[](index+col-1);}
  char bottom(int index){return operator[](index+col);}
  char bottom_right(int index){return operator[](index+col+1);}
  //Destructor
  ~Minesweeper();

};
//only link first col and all row

Minesweeper::Minesweeper(int row, int col) {
  this->size = row*col;
  this->row = row;
  this->col = col;
  head = last = temp = work = new Node;
  head->index = 0;
  for (int i = 1; i < row * col; i++) {
    //    cout<<"for loop i = "<<i<<"\n";
    last->next = new Node;
    //    cout<<"Create Node "<<last->index+1<<endl;
    last->next->prev = last;
    last = last->next;
    last->index = i;
    //    cout<<"last move to "<<last->index<<endl;
    if ((i) % col == 0) {
      //        cout<<"i+1%col==0\n";
      //      cout<<last->index<<" connect to "<<temp->index<<endl;
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
  head->index = 0; //initial value
  for (int i = 1; i < size; i++) {
    //    cout<<"for loop i = "<<i<<"\n";
    last->next = new Node; //create all node
    //    cout<<"Create Node "<<last->index+1<<endl;
    last->next->prev = last; //connect left and right
    last = last->next;
    last->index = i;
    //    cout<<"last move to "<<last->index<<endl;
    if ((i) % col == 0) {
      //        cout<<"i+1%col==0\n";
      //      cout<<last->index<<" connect to "<<temp->index<<endl;
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
  head->index = 0;
//  cout << "last = " << last->index << endl;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      //j=0
      if (!(i == 0 && j == 0)) {
        last->next = new Node;
        count++;
        last->next->prev = last;
        last=last->next;
        last->index=(i * col + j);
        //        cout<<"i = "<<i<<" j = "<<j<<endl;
        //        cout<<"last = "<<last->index<<"\n";
        if (i > 0) {
          //          cout<<"temp = "<<temp->index<<"\n\n";
          //          cout<<"last = "<<last->index<<endl;
          temp->down=last;
          temp->down->up=temp;
          temp = temp->next;
        }
      }
    }
  }
//  cout<<count<<endl;
}

void Minesweeper::genMine(int num){
  srand(time(0));
  cout<<"genMine\n";
  cout<<"num = "<<num<<endl;
  int x,y;    //x and y coordinates
  int index;
  for(int i=0;i<num;i++){
    do{
      x=rand()%16;
      y=rand()%30;
      index=x*col+y;
    }while(operator[](index)!=' ');
    cout<<"index = "<<index<<endl;
    operator[](index)='*';
  }
} 

char &Minesweeper::operator[](const int& index) {
//  cout<<"call index function\n";
  work = head;
  for (int i = 0; i < index; i++) {
    work = work->next;
  }
//  cout<<"in function "<<work->index<<endl;
  return work->data;
}

Minesweeper::~Minesweeper() {
//    cout<<"here."<<endl;
    work=head;
    //delete stop before the last node
    for(int i=0;i<size-1;i++){
      head=work;
      work=head->next;
//      cout<<head->index<<endl;
      delete head;
    }
    delete work;
//
//  int count=0;
//  while (!head == 0) {
//    work = head->next;
////    cout<<head->index<<endl;
//    delete head;
//    count++;
//    head = work;
//  }
//  cout<<count<<endl;
}

#endif	/* MINESWEEPER_H */

