/* 
 * File:   Sort.h
 * Author: Himkw_000
 *
 * Created on December 18, 2015, 2:29 PM
 */

#ifndef SORT_H
#define	SORT_H
#include <bits/stdc++.h>
using namespace std;
void selection10(vector<short> &v, int size, long &count){
  vector<short> temp;
  int min;
  count++;
  for(int i=0;i<10;i++){
    count++;
    min=i;
    count+=3;
    for(int j=i+1;j<size;j++){
      count+=4;
      if(v[min]>v[j]){
        count++;
        min=j;
      }
    }//j loop
    count++;
    if(min!=i){
      //swap
      count+=7;
      short temp=v[min];
      v[min]=v[i];
      v[i]=temp;
    }
  }
  for(int i=0;i<10;i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
}
void merge(vector<short> &hilow, int beg, int nlow, int nhigh, long &count) {
  //Create a merged array
  count+=4;  //assign
  int span=nhigh-beg; //Span the range to merge
  int cntl=beg;
  int cnth=nlow; //Independent counters to merge
  vector<short> c(span); //Allocate Memory

  //Fill the array
  count++; //i=0
  for(int i=0;i<span;i++) {
    count+=2; //i< and i++
    count++; //if
    if(cntl==nlow){
      count+=4; //assign
      c[i]=hilow[cnth++];
    }
    else if(cnth==nhigh){
      count+=5; //if 
      c[i]=hilow[cntl++];
    }
    else if(hilow[cntl]<hilow[cnth]){
      count+=8;
      c[i]=hilow[cntl++];
    }
    else{
      count+=8;
      c[i]=hilow[cnth++];
    }
  }
  //Copy back and deallocate memory
  count++; //i=0
  for(int i=0;i<span;i++) {
    count+=6; //for loop
    hilow[beg+i]=c[i];
  }
}
void mrgSort(vector<short> &a, int beg, int end, long &count) {
  count+=3; // assign
  int center=(beg+end)/2;
  count+=2; //if
  if((center-beg)>1)mrgSort(a, beg, center, count);
  count+=2; //if
  if((end-center)>1)mrgSort(a, center, end, count);
  merge(a, beg, center, end, count);
}

void bubble(vector<short> v, int size, long &count) {
  cout<<"bubble sort\n";
  bool swap=false;
  count++;
  do{
    swap=false;
    count+=2;
    for(int i=0;i<size-1;i++){
      count+=8;
      if(v[i]>v[i+1]){
        count+=10;
        swap=true;
        int temp=v[i];
        v[i]=v[i+1];
        v[i+1]=temp;
      }
    }
  }while(swap);
//  print(v);
}

void selection(vector<short> v, long &count){
  int min;
  count++;  //i=0
  for(int i=0;i<v.size()-1;i++){
    count+=4;
    min=i;
    count++;
    count+=2;
    for(int j=i+1;j<v.size();j++){
      count+=6;
      if(v[min]>v[j]){
        count++;
        min=j;
      }
    }//j loop
    count++;
    if(min!=i){
      //swap
      count+=7;
      int temp=v[min];
      v[min]=v[i];
      v[i]=temp;
    }
  }
//  print(v);
}

void quickSort(vector<short> &v, int start, int end, long &count){
  count+=2;
  if(start>=end)return; //only 1 element, assume be sorted
  count+=5;
  int mid=v[end];
  int left=start, right=end-1;
  count++;
  while(left<right){
    count+=3;
    while(v[left]<mid && left<right){ //value < last value
      left++;
      count+=4;
    }
    count+=4;
    while(v[right]>=mid && left<right){
      right--;
      count+=6;    
    }
    //swap;
    int temp=v[left];
    v[left]=v[right];
    v[right]=temp;
    count+=7;
  } //while loop ends
  count+=4;
  if(v[left]>=v[end]){
    //swap
    count+=7;
    int temp=v[left];
    v[left]=v[end];
    v[end]=temp;
  }
  else{
    left++;
    count++;
  }
  quickSort(v, start, left-1, count);
  quickSort(v, left+1, end, count);
}

void heapRebuild(vector<short> &p, int root, int size, long &count) {
  count+=3;
  int child=root*2+1; //永远是左孩子的下标，而且保障从上到下比较到底
  count+=3; //
  if(child<=size-1) {//下标不越界
    count+=2; //
    int rightChild=child+1;
    count+=3;
    if (rightChild<=size-1) {//右孩子存在
      count+=3;
      if (p[child]<p[rightChild]){ //当右孩子>左孩，用右孩子做准备
        child = rightChild;
        count++; //
      }
      count+=3;
      if (p[root]<p[child]) {//把比较大的孩子与父做比较
        count+=7;
        int temp=p[child];
        p[child]=p[root];
        p[root]=temp;
        heapRebuild(p, child, size, count);
      }
    }
  }
}
void heapSort(vector<short> &p, int size, long &count) {
    count+=2; //
    for (int i=size-1;i>=0;i--) {
      count+= 3; //
      heapRebuild(p,i,size,count);
    }
    count+=2; //
    int last=size-1;
    count++; //
    for (int i=1;i<=size;i++,last--) {
      count+=13;
      int temp=p[0];
      p[0]=p[last];
      p[last]=temp;
      heapRebuild(p, 0, last, count);
    }
}
void assistQuick(vector<short> v, int l, int r, long &count){
    quickSort(v, l, r, count);
//    print(v);
}

void assistHeap(vector<short> p, int l, long &countHep){
    heapSort(p, l, countHep);
//    print(p);
}

void assisMerge(vector<short> p, int l, long &count) {
  mrgSort(p, 0, l, count);
//  print(p);
}

void print(vector<short> v) {
  cout<<endl;
  for (int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;
}


#endif	/* SORT_H */

