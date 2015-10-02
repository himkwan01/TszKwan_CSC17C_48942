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
  Minesweeper test(3,3);
//  for(int i=0;i<9;i++){
//    test[i]=i;
//  }
  for(int i=0;i<9;i++){
    cout<<test[i]<<" ";
  }
  cout<<endl<<test.top(3)<<endl;
  cout<<test.bottom(3)<<endl;
  return 0;
}

