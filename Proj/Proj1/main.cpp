/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 1, 2015, 10:38 PM
 */
/* 
 * connect 4 2 players
 * board size = 6*7
 * checkWin = recursion
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
    do{
      getline(cin, temp);
//      cout<<temp;
    }while(!test.setValid(temp));
//    cout<<"setboard\n";
    test.setBoard(temp[0]-65, first);
    test.show();
  }

  return 0;
}

bool valid(string temp){
  if(temp.length()!=1){
    return false;
  }
  else if(temp[0]<'A' || temp[0]>'G'){
    return false;
  }
  return true;
}