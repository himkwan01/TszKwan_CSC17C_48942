/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 27, 2015, 12:02 PM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

struct cmp{
  bool operator()(const pair<int, int> &a, const pair<int, int> &b){
    return a.second<=b.second? true:false;
  }
};
int main(int argc, char** argv) {
  srand(time(0));
  vector<int> data;
  set<int> num;
  set<int>::iterator siter;
  map<int, int>::iterator miter;
  map<int, int> mode;
  float avg=0;
  int size=10;
  //input vector
  for(int i=0;i<size;i++){
    data.push_back(rand()%5);
  }
  sort(data.begin(), data.end());
  
  for(int i=0;i<size;i++){
    cout<<data[i]<<" ";
    avg+=data[i];
  }
  cout<<endl;
  cout<<"average = "<<avg/data.size()<<endl;
  cout<<"median = ";
  if(size%2==0){
    cout<<static_cast<float>((data[size/2]+data[size/2+1]))/2;
  }
  else cout<<data[data.size()/2];
  cout<<endl;
  //input set
  num.insert(data.begin(), data.end());
  
  for(siter=num.begin();siter!=num.end();siter++){
    mode[*siter] = 0;
    cout<<*siter<<" ";
  }
  cout<<endl;
  for(int i=0;i<data.size();i++){
    mode[data[i]]++;
  }
  for(miter=mode.begin();miter!=mode.end();miter++){
    cout<<miter->first<<" => "<<miter->second<<endl;
  }
  int largest  = max_element(mode.begin(), mode.end(), cmp())->second;
  cout<<"mode = ";
  for(miter=mode.begin();miter!=mode.end();miter++){
    if(miter->second==largest)cout<<miter->first<<" ";
  }
  return 0;
}

