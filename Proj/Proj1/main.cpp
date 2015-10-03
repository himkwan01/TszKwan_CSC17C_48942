/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 1, 2015, 10:38 PM
 */

#include <cstdlib>
#include <iostream>
#include "Minesweeper.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  Minesweeper test(4,4,1,1);
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
  cout<<"test[5] top =  "<<test.top(5)<<endl;
  cout<<"test[5] bottom = "<<test.bottom(5)<<endl;
  return 0;
}

