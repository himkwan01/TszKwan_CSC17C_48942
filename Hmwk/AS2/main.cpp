/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on September 16, 2015, 4:36 PM
 */

#include <cstdlib>
#include <iostream>
//#include <vector>
#include "SimpleVector.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  cout<<"Vector size 10 created\n";
  
  SimpleVector<int> test(10);
  
  cout<<"Vector size = "<<test.size()<<endl;
  for(int i=0;i<test.size();i++){
    test[i]=i;
  }
  cout<<"push back value 4\n";
  test.push_back(4);
  
  cout<<"Vector size = "<<test.size()<<endl;
  for(int i=0;i<test.size();i++){
    test[i]=i;
  }
  cout<<"pop back the last element\n";
  test.pop_back();
  cout<<"Vector size = "<<test.size()<<endl;
  for(int i=0;i<test.size();i++){
    test[i]=i;
  }
  return 0;
}

