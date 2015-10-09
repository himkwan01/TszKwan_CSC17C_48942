/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 1, 2015, 10:38 PM
 */
/* 
 * single player normal game size 16*30( mine = 99)
 * 
 */
#include <bits/stdc++.h>
#include "Minesweeper.h"
using namespace std;

//function prototype
void show(Minesweeper &, int index, int position);

int main(int argc, char** argv) {
  int row=16;
  int col=30;
  char fake[row][col];
  Minesweeper test(row,col,1,1);
  
  row=test.getRow();
  col=test.getCol();
  test.genMine(99);
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cout<<test[i*col+j]<<" ";
    }
    cout<<endl;
  }
  
  
  
  return 0;
}

void show(Minesweeper &obj, int index, int position){
  cout<<"test["<<index<<"] ";
  switch(position){
  case 1:
    cout<<"top = "<<obj.top(index);break;
  case 2:
    cout<<"bottom = "<<obj.bottom(index);break;
  default:
    cout<<"Error\n";break;
  }
  cout<<endl;
}