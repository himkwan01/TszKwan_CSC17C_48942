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
#include <cstdlib>
#include <iostream>
#include "Minesweeper.h"
using namespace std;

//function prototype
void show(Minesweeper &, int index, int position);

int main(int argc, char** argv) {
  Minesweeper test(16,30,1,1);
//  ChessBoard a(1000,1000);
  int row=test.getRow();
  int col=test.getCol();
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      cout<<test[i*col+j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  //show(test, 5, 1);
  show(test, 5, 2);
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