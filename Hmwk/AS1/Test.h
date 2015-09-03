/* 
 * File:   Test.h
 * Author: Himkw_000
 *
 * Created on September 3, 2015, 10:31 AM
 */

#ifndef TEST_H
#define	TEST_H
#include <iostream>
#include <cstdlib>
#include <ctime>
class Test {
public:
  Test(int size){
    cout<<"Test 1 started\n";
    //set time seed
    this->size = size;
    cout<<size<<endl;
    srand(static_cast<unsigned int>(time(0)));
    //fill 1d arr (size of 2d arr)
    firstarr=filAray(size);
    secondarr=filAray(firstarr, size);
    cout<<"test 1 construct end\n";
  }
  void prnt2dAry(){
    cout<<"Print 2d arr\n";
    cout<<endl;
    //Print the allocated memory
    for(int row=0;row<size;row++){
        for(int col=0;col<firstarr[row];col++){
            cout<<secondarr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Print 2d array end\n";
  }
  void prnt1dAry(){
    cout<<"Print 1d arr\n";
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<firstarr[i]<<" ";
    }
    cout<<endl;
    cout<<"Print 1d array end\n";
  }
  ~Test(){
    cout<<"Destructor start\n";
    delete []firstarr;
    //cout<<"deleted firstarr\n";
    for(int i=0;i<size;i++){
      delete []secondarr[i];
    }
    delete []secondarr;
    cout<<"Destructor end\n";
  }
private:
  int size;
  int *firstarr;
  int **secondarr;
  int *filAray(int size){
    cout<<"Fill 1d arr\n";
    cout<<size<<endl;
    int *firstarr = new int[size];
    for(int i=0;i<size;i++){
      firstarr[i]=i+1;
    }
//    for(int i=0;i<size;i++){
//      cout<<firstarr[i]<<endl;
//    }
    cout<<"fill 1d arr\n";
    return firstarr;
  }
  int **filAray(int *firstarr,int size){
    cout<<"Fill 2d arr\n";
    //Allocates Memory
    int **secondarr=new int*[size];
    for(int i=0;i<size;i++){
        secondarr[i]=new int[firstarr[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<size;row++){
        for(int col=0;col<firstarr[row];col++){
            secondarr[row][col]=rand()%90+10;
        }
    }
    cout<<"Fill 2d arr end\n";
    return secondarr;
  }
};

#endif	/* TEST_H */

