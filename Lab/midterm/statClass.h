/* 
 * File:   P3.h
 * Author: Himkw_000
 *
 * Created on October 27, 2015, 5:17 PM
 */

#ifndef P3_H
#define	P3_H
#include <bits/stdc++.h>
#include "structure.h"
using namespace std;

class statClass {
private:
  int min;
  int max;
  float avg;
  map<int, int> mode;
  vector<int> vmode;
  void setMap(vector<int>);
  template <class T>
  void setMap(T, int);
public:
  statClass(vector<int> v){setMap(v);}
  template <class T>
  statClass(T v, int dum){setMap(v, dum);}
  ~statClass();
  int getMin(){return min;}
  int getMax(){return max;}
  float getAvg(){return avg;}
};

void statClass::setMap(vector<int> v){
  sort(v.begin(), v.end());
  avg=0;
  min=v[0];
  max=v[v.size()-1];
  for(int i=0;i<v.size();i++){
    avg+=v[i];
  }
  avg/=v.size();
  set<int> num;
  num.insert(v.begin(), v.end());
  for(set<int>::iterator siter=num.begin();siter!=num.end();siter++){
    mode[*siter] = 0;
  }
}
template <class T>
void statClass::setMap(T a, int dum){
  vector<int> v;
  for(int i=0;i<a.size();i++){
    v.push_back(a[i]);
  }
  sort(v.begin(), v.end());
  avg=0;
  min=v[0];
  max=v[v.size()-1];
  for(int i=0;i<v.size();i++){
    avg+=v[i];
  }
  avg/=v.size();
  set<int> num;
  num.insert(v.begin(), v.end());
  for(set<int>::iterator siter=num.begin();siter!=num.end();siter++){
    mode[*siter] = 0;
  }
  for(int i=0;i<v.size();i++){
    mode[v[i]]++;
  }
  cout<<"min = "<<min<<endl;
  cout<<"max = "<<max<<endl;
  cout<<"avg = "<<avg<<endl;
  cout<<"print data and frequencies\n\n";
  for(map<int,int>::iterator miter=mode.begin();miter!=mode.end();miter++){
    cout<<miter->first<<" => "<<miter->second<<endl;
  }
  int largest = max_element(mode.begin(), mode.end(), cmp())->second;
  for(map<int,int>::iterator miter=mode.begin();miter!=mode.end();miter++){
    if(miter->second==largest)vmode.push_back(miter->first);
  }
  cout<<"print mode\n";
  for(int i=0;i<vmode.size();i++){
    cout<<vmode[i]<<" ";
  }
  cout<<"\n\n";
}


#endif	/* P3_H */

