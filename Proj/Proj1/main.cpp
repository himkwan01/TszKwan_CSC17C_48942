/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 1, 2015, 10:38 PM
 */
/* 
 * connect 4 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

//user libraries
#include "Minesweeper.h"
#include "Connect_Four.h"

//function prototype
bool valid(string);

//Program starts
int main(int argc, char** argv) {
  //declare vars
  string temp;
  bool first=false;
  C4<char> test(6,7);
  test.show();
  while(!test.getWin()){
    first?first=false:first=true;
    getline(cin, temp);
    
    test.setBoard(temp[0]-65, first);
    test.show();
  }
//  getline(cin, temp);
  
  
  
  
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