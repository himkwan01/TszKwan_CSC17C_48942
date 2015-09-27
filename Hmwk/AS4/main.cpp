/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on September 26, 2015, 5:18 PM
 */

#include <bits/stdc++.h>
#include "Vector_Linked_List.h"
using namespace std;

//function prototype

int main(int argc, char** argv) {
  
  cout<<"Create empty vector\n";
  Vect<int> empty;
  cout<<"empty vector size = "<<empty.getSize()<<"\n\n";
  
  cout<<"Create vector with size = 4\n";
  Vect<int> test(4);
  cout<<"vector actual size = "<<test.getMaxSize()<<endl;
  cout<<"vector current size = "<<test.getSize()<<endl;
  cout<<"fill vector\n";
  for(int i=0;i<test.getSize();i++){
    test[i]=i;
  }
  cout<<"print vector\n";
  for(int i=0;i<test.getSize();i++){
    cout<<test[i]<<endl;
  }
  cout<<endl;
  test.pop_up();
  cout<<"pop up\n";
  cout<<"current size = "<<test.getSize()<<endl;
  cout<<"size = "<<test.getMaxSize()<<endl;
  for(int i=0;i<test.getSize();i++){
    cout<<test[i]<<endl;
  }
  test.push_back(10);
  cout<<"push back 10\n";
  cout<<"current size = "<<test.getSize()<<endl;
  cout<<"size = "<<test.getMaxSize()<<endl;
  for(int i=0;i<test.getSize();i++){
    cout<<test[i]<<endl;
  }
  test.push_back(14);
  cout<<"push back 14\n";
  cout<<"current size = "<<test.getSize()<<endl;
  cout<<"size = "<<test.getMaxSize()<<endl;
  for(int i=0;i<test.getSize();i++){
    cout<<test[i]<<endl;
  }
  cout<<endl;
  
  cout<<"create vector size = 4 and initial value = 2\n";
  Vect<int> test2(4,2);
  cout<<"vector actual size = "<<test2.getMaxSize()<<endl;
  cout<<"vector current size = "<<test2.getSize()<<endl;
  cout<<"print vector\n";
  for(int i=0;i<test2.getSize();i++){
    cout<<test2[i]<<endl;
  }
  test2.pop_up();
  cout<<"pop up\n";
  cout<<"current size = "<<test2.getSize()<<endl;
  cout<<"size = "<<test2.getMaxSize()<<endl;
  for(int i=0;i<test2.getSize();i++){
    cout<<test2[i]<<endl;
  }
  test2.push_back(10);
  cout<<"push back 10\n";
  cout<<"current size = "<<test2.getSize()<<endl;
  cout<<"size = "<<test2.getMaxSize()<<endl;
  for(int i=0;i<test2.getSize();i++){
    cout<<test2[i]<<endl;
  }
  test2.push_back(14);
  cout<<"push back 14\n";
  cout<<"current size = "<<test2.getSize()<<endl;
  cout<<"size = "<<test2.getMaxSize()<<endl;
  for(int i=0;i<test2.getSize();i++){
    cout<<test2[i]<<endl;
  }
  return 0;
}

