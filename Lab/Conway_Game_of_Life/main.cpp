/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on November 2, 2015, 9:32 AM
 */

#include <iostream>
using namespace std;

#include "World.h"

World *next(World *);

int main(int argc, char** argv) {
  World *obj = new World(5,5);
  obj->setBoard(1,1,2);
  obj->setBoard(1,2,2);
  obj->setBoard(1,3,2);
  int num;
  obj->print();
  cin>>num;
  while(num!=0){
    World *new_world=next(obj);
    cout<<"create new world\n";
    //still point to same address
//    obj=new_world;
    obj->print();
//    delete new_world;
    cin>>num;
  }
  delete obj;
  return 0;
}
//if cell lives, around live cells = 2 or 3, then cell lives
//if cell lives, around live cells != 2 or 3, then cell died
//if cell died, around live cells ==3, then cell lives
World *next(World *obj){
  int row=obj->getRow();
  int col=obj->getCol();
  int **temp = new int*[row];
  for(int i=0;i<row;i++){
    temp[i] = new int[col];
  }
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(obj->getBoard(i,j)==1){
        if(obj->count_neighbour(i,j)==2 || obj->count_neighbour(i,j)==3)temp[i][j]=1;
        else temp[i][j]=0;
      }
      else{
        if(obj->count_neighbour(i,j)==3)temp[i][j]=1;
        else temp[i][j]=0;
      }
    }
  }
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      obj->setBoard(temp[i][j], i,j);
    }
  }
  for(int i=0;i<row;i++){
    delete []temp[i];
  }
  delete []temp;
  
  return obj;
}

