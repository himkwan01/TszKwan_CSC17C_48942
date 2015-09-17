/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on September 3, 2015, 10:27 AM
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

//User Libraries
//#include "Test.h"
#include "TemplateT.h"
//Global Constants

//Function Prototypes
int *filAray(int);
int **filAray(int*,int);
void prntAry(int *,int);
void prntAry(int **,int *,int);
void destroy(int **,int *,int);


//Execution Begins Here
int main(){
  int num=10;
//    //Initialize the random number generator
//    srand(static_cast<unsigned int>(time(0)));
//    int col=10;
//    //Fill the arrays
//    int *d1ary=filAray(col);
//    int **d2ary=filAray(d1ary,col);
//    //Print the arrays
//    prntAry(d1ary,col);
//    prntAry(d2ary,d1ary,col);
//    //Delete the dynamic arrays
//    destroy(d2ary,d1ary,col);

    TemplateT<int> test(num);
    cout<<"Template <int> created\n";
    test.prnt1dAry();
    test.prnt2dAry();
    TemplateT<float> tempT(num);
    cout<<"Template <float> created\n";
    cout<<showpoint<<fixed<<setprecision(2);
    tempT.prnt1dAry();
    tempT.prnt2dAry();
    //test.~Test();
    return 0;
}

void destroy(int **a,int *b,int c){
    delete []b;
    for(int i=0;i<c;i++){
        delete []a[i];
    }
    delete []a;
}

void prntAry(int **array,int *cols,int nCols){
    cout<<endl;
    //Print the allocated memory
    for(int row=0;row<nCols;row++){
        for(int col=0;col<cols[row];col++){
            cout<<array[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *array,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

//Fills a 1-Dim array with the number of
//Columns per row
int **filAray(int *cols,int nCols){
    //Allocates Memory
    int **array=new int*[nCols];
    for(int i=0;i<nCols;i++){
        array[i]=new int[cols[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<nCols;row++){
        for(int col=0;col<cols[row];col++){
            array[row][col]=rand()%90+10;
        }
    }
    return array;
}

//Fills a 1-Dim array with the number of
//Columns per row
int *filAray(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        //array[i]=rand()%10+1;
        array[i]=i+1;
    }
    return array;
}
