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
//#include "Minesweeper.h"
#include "Connect_Four.h"

//function prototype
bool valid(string);

//Program starts
int main(int argc, char** argv) {
  //declare vars
  string temp;
  bool valid;
  bool first=false;
  bool repeat=false;
  C4<char> test(6,7);
  do{
    repeat=false;
    first=false;
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
    test.clr();
    cout<<test.getName(first)<<" wins!\n";
    do{
      valid=true;
      cout<<"Play again ? (Y/N)";
      getline(cin,temp);
      if(temp.length()!=1)valid=false;
      else if(temp[0]!='Y' && temp[0]!='N')valid=false;
      else if(temp[0]=='Y')repeat=true;
    }while(!valid);
  }while(repeat);
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