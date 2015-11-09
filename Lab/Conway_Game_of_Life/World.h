/* 
 * File:   world.h
 * Author: Himkw_000
 *
 * Created on November 2, 2015, 9:33 AM
 */

#ifndef WORLD_H
#define	WORLD_H

#include <iostream>
using namespace std;

class World{
public:
  World(){}
  World(int, int);
  int count_neighbour(int,int);
  int getRow(){return row;}
  int getCol(){return col;}
  int getBoard(int i,int j){return board[i][j];}
  void setBoard(int value, int i, int j){board[i][j]=value;}
  void print();
  void free();
  ~World();
private:
  int row;
  int col;
  int **board;
};
World::World(int row, int col){
  this->row=row;
  this->col=col;
  if(row!=0 && col!=0){
    board = new int*[row];
    for(int i=0;i<row;i++){
      board[i] = new int[col];
    }
    //initialize
    for(int i=0;i<row;i++){
      for(int j=0;j<col;j++){
        board[i][j]=0;
      }
    }
  }
}

int World::count_neighbour(int x, int y){
  int lx, ly, bx, by;
  lx=(x-1>-1?x-1:row-1);
  ly=(y-1>-1?y-1:col-1);
  bx=(x+1<row?x+1:0);
  by=(y+1<col?y+1:0);
  int count=0;
  count=board[lx][ly]+board[x][ly]+board[bx][ly]+
        board[lx][y]+              board[bx][y]+
        board[lx][by]+board[x][by]+board[bx][by];
  return count;
}

void World::print(){
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}

void World::free(){
  for(int i=0;i<row;i++){
    delete []board[i];
  }
  delete []board;
}

World::~World(){
  if(row*col!=0){
    for(int i=0;i<row;i++){
      delete []board[i];
    }
    delete []board;
  }
}

#endif	/* WORLD_H */

