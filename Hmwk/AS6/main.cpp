/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on September 29, 2015, 9:58 AM
 */

#include <bits/stdc++.h>
using namespace std;

#include "Queue.h"
#include "Stack.h"
#include "Linked_List.h"
#include "Priority.h"
#include "PriorityQueue.h"
#include "SortedLnkLst.h"

int main(int argc, char** argv) {  
  Queue<int> qtest(10);
  Stack<int> stest(10);
  
//  cout<<"size = 10\n";
  cout<<"create and fill stack and queue objects\n";
//  cout<<qtest.getSize()<<endl;
  for(int i=0;i<qtest.getSize();i++){
    qtest[i]=i;
    stest[i]=i;
  }
  cout<<"print queue\n";
  for(int i=0;i<qtest.getSize();i++){
    cout<<qtest[i]<<" ";
  }
  cout<<"\n\nqueue append (10)\n";
  qtest.append(10);
//  cout<<"print queue\n";
  for(int i=0;i<qtest.getSize();i++){
    cout<<qtest[i]<<" ";
  }
  cout<<"\n\nqueue prepend\n";
  qtest.prepend();
  cout<<"print queue\n";
  for(int i=0;i<qtest.getSize();i++){
    cout<<qtest[i]<<" ";
  }
  
  cout<<"\n\nprint stack\n";
  for(int i=0;i<stest.getSize();i++){
    cout<<stest[i]<<" ";
  }
  cout<<"\nstack append (10)\n";
  stest.append(10);
  cout<<"print stack\n";
  for(int i=0;i<stest.getSize();i++){
    cout<<stest[i]<<" ";
  }
  cout<<"\n\nstack prepend\n";
  stest.prepend();
  cout<<"print stack\n";
  for(int i=0;i<stest.getSize();i++){
    cout<<stest[i]<<" ";
  }
  
  cout<<"\n\ncreate doubly linked list\n";
  LnkLst<int> doubly(10,true);
  for(int i=0;i<doubly.getSize();i++){
    doubly[i]=2*i;
  }
  cout<<"print doubly array\n";
  for(int i=0;i<doubly.getSize();i++){
    cout<<doubly[i]<<" ";
  }
  cout<<"\n\n";
  cout<<"call previous function\n";
  cout<<"previous data of "<<doubly[5]<<" = "<<doubly.previous(5)<<endl;
  
  cout<<"\ncreate circular linked list\n";
  LnkLst<int> circular(10,false);
  for(int i=0;i<circular.getSize();i++){
    circular[i]=i;
  }
  cout<<"print circular array\n";
  for(int i=0;i<circular.getSize();i++){
    cout<<circular[i]<<" ";
  }
  cout<<"\nlast->next = "<<circular.next(circular.getSize()-1)<<"\n\n";
  
  cout<<"Create empty priority linked list\n";
  PriorityLnkLst<int> pList;
  cout<<"append data=10\n";
  
  pList.append(10);
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
  pList.prepend();
  cout<<"append data=21\n";
  pList.append(21);
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
//  pList.prepend();
  
  cout<<"append data= 4\n";
  pList.append(4);
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"append data= 100\n";
  pList.append(100);
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"append data= -10\n";
  pList.append(-10);
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"get value 4\n";
  pList.find(4);
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"get value -10\n";
  pList.find(-10);
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"prepend\n";
  pList.prepend();
  for(int i=0;i<pList.getSize();i++){
    cout<<pList[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"Create empty priority queue\n";
  PriorityQueue<int> pQueue;
  cout<<"append data=10\n";
  
  pQueue.append(10);
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
  pQueue.prepend();
  cout<<"append data=21\n";
  pQueue.append(21);
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
//  pList.prepend();
  
  cout<<"append data= 4\n";
  pQueue.append(4);
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"append data= 100\n";
  pQueue.append(100);
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"append data= -10\n";
  pQueue.append(-10);
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"get value 4\n";
  pQueue.find(4);
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"get value -10\n";
  pQueue.find(-10);
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"prepend\n";
  pQueue.prepend();
  for(int i=0;i<pQueue.getSize();i++){
    cout<<pQueue[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"Create sort linked list\n";
  SortLnkLst<int> sLnkLst(10);
  for(int i=0;i<sLnkLst.getSize();i++){
    sLnkLst[i]=i;
  }
  for(int i=0;i<sLnkLst.getSize();i++){
    cout<<sLnkLst[i]<<" ";
  }
  cout<<"\n\n";
  
  cout<<"append 4\n";
  cout<<"automatically call sort function inside append\n";
  sLnkLst.append(4);
  for(int i=0;i<sLnkLst.getSize();i++){
    cout<<sLnkLst[i]<<" ";
  }
  cout<<"\n\n";
  
  return 0;
}
