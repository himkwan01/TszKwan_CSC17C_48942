/* 
 * File:   TemplateT.h
 * Author: Himkw_000
 *
 * Created on September 3, 2015, 10:31 AM
 */

// firstarr must be int coz its the size of secondarr

#ifndef TEMPLATE_H
#define	TEMPLATE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
template <class T>
class TemplateT {
public:
  TemplateT(int size){
    //cout<<"TemplateT 1 started\n";
    //set time seed
    this->size = size;
    cout<<size<<endl;
    
    //fill 1d arr (size of 2d arr)
    firstarr=filAray(size);
    secondarr=filAray(firstarr, size);
    //cout<<"test 1 construct end\n";
  }
  void prnt2dAry(){
    cout<<"Print 2d array\n";
    cout<<endl;
    //Print the allocated memory
    for(int row=0;row<size;row++){
        for(int col=0;col<firstarr[row];col++){
            cout<<secondarr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //cout<<"Print 2d array end\n";
  }
  void prnt1dAry(){
    cout<<"Print 1d array\n";
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<firstarr[i]<<" ";
    }
    cout<<endl;
    //cout<<"Print 1d array end\n";
  }
  ~TemplateT(){
    //cout<<"Destructor start\n";
    delete []firstarr;
    //cout<<"deleted firstarr\n";
    for(int i=0;i<size;i++){
      delete []secondarr[i];
    }
    delete []secondarr;
    //cout<<"Destructor end\n";
  }
private:
  int size;
  int *firstarr;
  T **secondarr;
  int *filAray(int size){
    //cout<<"Fill 1d arr\n";
    cout<<"size = "<<size<<endl;
    int *firstarr = new int[size];
    for(int i=0;i<size;i++){
      firstarr[i]=i+1;
    }
//    for(int i=0;i<size;i++){
//      cout<<firstarr[i]<<endl;
//    }
    //cout<<"fill 1d arr\n";
    return firstarr;
  }
  T **filAray(int *firstarr,int size){
    //cout<<"Fill 2d arr\n";
    //Allocates Memory
    T **secondarr=new T*[size];
    for(int i=0;i<size;i++){
        secondarr[i]=new T[firstarr[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<size;row++){
        for(int col=0;col<firstarr[row];col++){
            secondarr[row][col]=static_cast<T>(rand()%9000+1000)/100;
        }
    }
    //cout<<"Fill 2d arr end\n";
    return secondarr;
  }
};

#endif	/* TEMPLATE_H */

