/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on September 27, 2015, 12:13 AM
 */

#include <bits/stdc++.h>
#include "Vector_Linked_List.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  Vect<int> test(10, 1);
  cout<<"append\n";
  test.append(2);
  cout<<"prepend\n";
  test.prepend();
  cout<<"insert after";
  test.insert_after(9,4);
  cout<<"insert before\n";
  test.insert_before(0,3);
  return 0;
}

