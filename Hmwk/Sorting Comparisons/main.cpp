/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 26, 2015, 11:19 AM
 */


#include <cstdlib>
#include<iostream>
#include<vector>


using namespace std;
void print(vector<int>);
void bubble(vector<int>, int&);
void selection(vector<int>, int&);
void quickSort(vector<int>&, int, int, int&);
void assistQuick(vector<int>, int, int, int&);
void assistHeap(vector<int>, int, int&);
void heapSort(vector<int>&, int, int&);
void heapRebuild(vector<int>&, int, int, int&);
void assisMerge(vector<int>, int, int&);
void mrgSort(vector<int>&, int, int, int&);
void merge(vector<int>&, int, int, int, int&);
int main(int argc, char** argv) {
    srand(time(0));
    int size=100;
    int count=0;
    vector<int> v;
    for (int i=0; i<size;i++) {
        v.push_back(rand()%10000);
    }
//    print(v);
    cout<<"100 random number sort";
    bubble(v, count);
    cout<<"bubble operation: "<<count<<endl;
    count=0;
    selection(v, count);
    cout<<"selection operation: "<<count<<endl;
    count=0;
    assistQuick(v, 0, size-1, count); //quickSort
    cout<<"quick operation: "<<count<<endl;
    count=0;
    assistHeap(v, size, count); //heap
    cout<<"heap operation: "<<count<<endl;
    count=0;
    assisMerge(v, size, count); //merge
    cout<<"merge operation: "<<count<<endl;
    
    
    cout<<endl<<"200 random number sort";
    for(int i=0;i<200-v.size();i++){
      v.push_back(rand()%10000);
    }
    
    bubble(v, count);
    cout<<"bubble operation: "<<count<<endl;
    count=0;
    selection(v, count);
    cout<<"selection operation: "<<count<<endl;
    count=0;
    assistQuick(v, 0, v.size()-1, count); //quickSort
    cout<<"quick operation: "<<count<<endl;
    count=0;
    assistHeap(v, v.size(), count); //heap
    cout<<"heap operation: "<<count<<endl;
    count=0;
    assisMerge(v, v.size(), count); //merge
    cout<<"merge operation: "<<count<<endl;
    return 0;
}

void assistQuick(vector<int> v, int l, int r, int &count){
    quickSort(v, l, r, count);
//    print(v);
}

void assistHeap(vector<int> p, int l, int &countHep){
    heapSort(p, l, countHep);
//    print(p);
}

void assisMerge(vector<int> p, int l, int&count) {
  mrgSort(p, 0, l, count);
//  print(p);
}

void print(vector<int> v) {
  cout<<endl;
  for (int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
  cout<<endl;
}

void mrgSort(vector<int> &a, int beg, int end, int&count) {
  count+=3; // assign
  int center=(beg+end)/2;
  count+=2; //if
  if((center-beg)>1)mrgSort(a, beg, center, count);
  count+=2; //if
  if((end-center)>1)mrgSort(a, center, end, count);
  merge(a, beg, center, end, count);
}

void merge(vector<int> &hilow, int beg, int nlow, int nhigh, int&count) {
  //Create a merged array
  count+=4;  //assign
  int span=nhigh-beg; //Span the range to merge
  int cntl=beg;
  int cnth=nlow; //Independent counters to merge
  vector<int> c(span); //Allocate Memory

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

void bubble(vector<int> v, int&count) {
  bool swap=false;
  count++;
  do{
    swap=false;
    count+=2;
    for(int i=0;i<v.size()-1;i++){
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

void selection(vector<int> v, int&count){
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
    }
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

void quickSort(vector<int> &v, int start, int end, int &count){
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

//void quickSort(vector<int>&s, int start, int end, int&countQik) {
//    if (start < end){
//        int left = start+1, right = end;
//        int pivot = s[start]; //参照数是s[l];
//        while (left < right){
//            countQik += 4;
//            從右至左找小於pivot
//            while (left < right && s[right] >= pivot){
//                right--;
//            }
//            这里判断left<right,上面while循环有可能条件同时打破
//            if (left < right){ 
//                s[left++] = s[right];
//            }
//            从左向右找第一个大于等于x的数
//            while(left < right && s[left] < pivot){
//                left++;
//            }
//            if (left < right){
//                s[right--] = s[left];
//            }
//        }
//        s[left] = pivot;
//        quickSort(s, start, left - 1, countQik);
//        quickSort(s, left + 1, end, countQik);
//    }
//}

void heapSort(vector<int> &p, int size, int&count) {
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

void heapRebuild(vector<int> &p, int root, int size, int& count) {
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