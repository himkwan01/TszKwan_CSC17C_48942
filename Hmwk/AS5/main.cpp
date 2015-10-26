/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on September 27, 2015, 12:13 AM
 */

#include <bits/stdc++.h>
#include "Vector_Linked_List.h"
using namespace std;
template <class T>
void show(Vect<T> &obj){
  for(int i=0;i<obj.getSize();i++){
    cout<<obj[i]<<endl;
  }
}
int main(int argc, char** argv) {
  
  cout<<"create test size= 4, initial value =1\n";
  cout<<"create obj copy and copy test\n";
  Vect<int> test(4, 1);
  Vect<int> copy(test);
  Vect<int> copy1 = copy;
  
  cout<<"output test\n";
  show(test);
  cout<<"output copy\n";
  show(copy);
  cout<<"change copy value\n";
  for(int i=0;i<copy.getSize();i++){
    copy[i]=i;
    cout<<copy[i]<<endl;
  }
  cout<<"first value in copy = "<<copy.first()<<endl;
  cout<<"last value in copy = "<<copy.rear()<<endl;
  
  cout<<"copy prepend 123 and show\n";
  copy.prepend(123);
  show(copy);
  
  cout<<"copy append 3 and show\n";
  copy.append(3);
  show(copy);
  
  cout<<"copy extract 1 and show\n";
  copy.extract(1);
  show(copy);
  
  cout<<"test extract 1 and show\n";
  test.extract(1);
  show(test);
  
  cout<<"insert 2 after last value in obj copy\n";
  copy.insert_after(copy.getSize()-1,2);
  show(copy);
  
  cout<<"insert 100 after second value in obj copy\n";
  copy.insert_after(1,100);
  show(copy);
  
  cout<<"insert -1 before first value in obj copy\n";
  copy.insert_before(0,-1);
  show(copy);
  
  cout<<"insert 1000 before the second value in obj copy\n";
  copy.insert_before(1,1000);
  show(copy);
  
  return 0;
}

