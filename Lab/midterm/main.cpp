/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on October 27, 2015, 3:52 PM
 */

#include <bits/stdc++.h>
using namespace std;
//User Libraries
#include "structure.h"
#include "LnkLst.h"
#include "SimpleVector.h"
#include "statClass.h"
#include "SelfOrganizingList.h"
//Global Constants

//Function Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
//Vect* top(Vect, int);
//LnkLst *top(LnkLst, int);
template <class T>
T *top(T, int);
//Vect* mode(Vect);
//LnkLst *mode(LnkLst);
template <class T>
T *mode(T);
float rtan(float);
float g(float);
float h(float);
template <class T>
statClass *stat(T);
template <class T>
statClass * stat(T obj, int dum);
//System Begins Here
int main(int argc, char** argv) {
  srand(time(0));
  cout<<showpoint<<setprecision(7);
  int inN;
  do{
    Menu();
    inN=getN();
    switch(inN){
    case 1: problem1();break;
    case 2: problem2();break;
    case 3: problem3();break;
    case 4: problem4();break;
    case 5: problem5();break;
    case 6: problem6();break;
    case 7: problem7();break;
    case 8: problem8();break;
    case 9: problem9();break;
    default:;
    };
  }while(inN<10);
  return 0;
}

//Menu Function
void Menu(){
  cout<<"Type 1 for problem 1"<<endl;
  cout<<"Type 2 for problem 2"<<endl;
  cout<<"Type 3 for problem 3"<<endl;
  cout<<"Type 4 for problem 4"<<endl;
  cout<<"Type 5 for problem 5"<<endl;
  cout<<"Type 6 for problem 6"<<endl;
  cout<<"Type 7 for problem 7"<<endl;
  cout<<"Type 8 for problem 8"<<endl;
  cout<<"Type 9 for problem 9"<<endl;
  cout<<"Type 10 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
  int inN;
  cin>>inN;
  cin.ignore();
  return inN;
}
//return vector *top, contains top x elements in v
void problem1(){
  cout<<"Problem 1  15pts\n";
  Vect v1;
//  vector<int> v;
  cout<<"fill vector\n";
  for(int i=0;i<10;i++){
//    v.append(rand()%1000);
    v1.append(rand()%1000);
  }
  for(int i=0;i<v1.size();i++){
//    cout<<v[i]<<" ";
    cout<<v1[i]<<" ";
  }
  cout<<endl;
  cout<<"call top (vector, 4)\n";
//  vector<int> *p4 = top(v, 4);
  Vect *p4 = top(v1, 4);
  cout<<"display top(vector,4)\n";
  for(int i=0;i<p4->size();i++){
    cout<<(*p4)[i]<<" ";
  }
  cout<<"\n\n";
  delete p4;
}
//return vector *mode
void problem2(){
  cout<<"Problem 2  20pts\n";
  Vect data;
  int size=10;
  cout<<"vector size =10\n";
  cout<<"fill vector range 0-3\n";
  for(int i=0;i<size;i++){
    data.append(rand()%4);
  }
  cout<<"call mode function\n";
  Vect *v2 = mode(data);
  cout<<"output mode\n";
  for(int i=0;i<v2->size();i++){
    cout<<(*v2)[i]<<" ";
  }
  cout<<"\n\n";
  delete v2;
}

void problem3(){
  cout<<"Problem 3  25pts\n";
  cout<<"create Vect size=10, fill range 0-5\n";
  Vect v;
  for(int i=0;i<10;i++){
    v.append(rand()%6);
  }
  cout<<"print data\n";
  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
  cout<<"call stat function\n";
  statClass *result = stat(v,1);
}
//using link list to solve p1
void problem4(){
  cout<<"Problem 4  15pts\n";
  cout<<"create and fill LnkLst size=10\n";
  cout<<"range 0-5\n";
  LnkLst<int> p4(10);
  for(int i=0;i<p4.size();i++){
    cout<<p4[i]<<" ";
  }
  cout<<endl;
  cout<<"call top (LnkLst, 4)\n";
  LnkLst<int> *p42 = top(p4, 4);
  cout<<"display top(LnkLst,4)\n";
  for(int i=0;i<p42->size();i++){
    cout<<(*p42)[i]<<" ";
  }
  cout<<"\n\n";
  delete p42;
}
void problem5(){
  cout<<"Problem 5  20pts\n";
  cout<<"create and fill LnkLst size=10\n";
  cout<<"range 0-5\n";
  LnkLst<int> p4(10);
  for(int i=0;i<p4.size();i++){
    cout<<p4[i]<<" ";
  }
  cout<<endl;
  cout<<"call mode function\n";
  LnkLst<int> *temp = mode(p4);
  for(int i=0;i<temp->size();i++){
    cout<<(*temp)[i]<<" ";
  }
  cout<<"\n\n";
  delete temp;
}
void problem6(){
  cout<<"Problem 6 25 pts\n";
  cout<<"create lnklst size=10, fill range 0-5\n";
  LnkLst<int> p6(10);
  cout<<"print data\n";
  for(int i=0;i<p6.size();i++){
    cout<<p6[i]<<" ";
  }
  cout<<"call stat function\n";
  statClass *result = stat(p6, 1);
  
}
void problem7(){
  int num;
  SelfOrganizingList<int> a;
  cout<<"fill self organizing list from 0-4\n";
  for(int i=0;i<10;i++){
    a.append(i/2);
  }
  cout<<"print data\n";
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<"Input a data you want to access :";
  cin>>num;
  cout<<(a.find(num)?"found\n":"not found\n");
  cout<<"print data\n";
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
  }
  cout<<"\n\n";
}
void problem8(){
  cout<<"Problem 8  15pts\n";
  cout<<"output tan(x) from -1 to 1\n";
  cout<<setprecision(2);
  for(float i=-10;i<=10;i+=1){
    cout<<"System tan("<<i/10<<") = "<<tan(i/10)<<endl;
    cout<<"Recursive tan("<<i/10<<") = "<<rtan(i/10)<<"\n\n";
  }
}
void problem9(){
  cout<<"Problem 9  25pts\n";
  cout<<"mutual function\n";
  cout<<setprecision(6);
  for(float i=-10;i<=10;i+=1){
    cout<<"h("<<i<<") = "<<h(i/10)<<endl;
    cout<<"g("<<i<<") = "<<g(i/10)<<endl<<endl;
  }
  
}

//Vect *top(Vect v, int p){
//  vector<int> stlv;
////  cout<<"fill stlv\n";
////  cout<<"v.size = "<<v.size()<<endl;
//  for(int i=0;i<v.size();i++){
//    stlv.push_back(v[i]);
//  }
//  sort(stlv.begin(), stlv.end());
////  cout<<"finish sorting\n";
//  Vect *temp = new Vect;
//  for(int i=0;i<p;i++){
//    temp->append(stlv[stlv.size()-p+i]);
//  }
////  cout<<"finish filling top vect\n";
//  return temp;
//}

//Vect *mode(Vect v){
//  vector<int> vect;
//  for(int i=0;i<v.size();i++){
//    vect.push_back(v[i]);
//  }
//  sort(vect.begin(), vect.end());
//  cout<<"print sort vect\n";
//  for(int i=0;i<vect.size();i++){
//    cout<<vect[i]<<" ";
//  }
//  cout<<endl;
//  set<int> num;
//  map<int,int> mode;
//  map<int,int>::iterator miter;
//  for(int i=0;i<v.size();i++){
//    if(num.insert(v[i]).second){
//      mode[v[i]]=0;
//    }
//  }
//  for(int i=0;i<v.size();i++){
//    mode[v[i]]++;
//  }
//  int largest = max_element(mode.begin(), mode.end(), cmp())->second;
//  Vect *temp = new Vect;
//  for(miter=mode.begin();miter!=mode.end();miter++){
//    if(miter->second==largest){
//      //push
//      temp->append(miter->first);
//    }
//  }
//  return temp;
//}


//LnkLst *top(LnkLst a, int p){
//  LnkLst *temp = new LnkLst;
//  vector<int> stlv;
//  for(int i=0;i<a.size();i++){
//    stlv.push_back(a[i]);
//  }
//  sort(stlv.begin(), stlv.end());
//  for(int i=0;i<p;i++){
//    temp->append(stlv[stlv.size()-p+i]);
//  }
//  return temp;
//}

//LnkLst *mode(LnkLst a){
//  LnkLst *temp = new LnkLst;
//  set<int> num;
//  map<int, int>::iterator miter;
//  vector<int> vtemp;
//  map<int, int> mde;
//  for(int i=0;i<a.size();i++){
//    vtemp.push_back(a[i]);
//  }
//  sort(vtemp.begin(), vtemp.end());
//  for(int i=0;i<a.size();i++){
//    a[i]=vtemp[i];
//  }
//  cout<<"print sorted linked list\n";
//  for(int i=0;i<a.size();i++){
//    cout<<a[i]<<" ";
//  }
//  cout<<endl;
//  for(int i=0;i<a.size();i++){
//    if(num.insert(a[i]).second){
//      mde[a[i]]=0;
//    }
//  }
//  for(int i=0;i<a.size();i++){
//    mde[a[i]]++;
//  }
//  int largest = max_element(mde.begin(), mde.end(), cmp())->second;
//  for(miter=mde.begin();miter!=mde.end();miter++){
//    if(miter->second==largest)
//      temp->append(miter->first);
//  }
//  
//  return temp;
//}

float rtan(float angle){
  float tol=1e-2;
  float temp = angle+angle*angle*angle/3;
  if(temp>-tol && temp<tol){
    return temp;
  }
  float tanv= rtan(angle/2);
  return 2*tanv/(1-tanv*tanv);
}
float h(float x){
  float tol=1e-6;
  if(abs(x)<tol)return x+x*x*x/6;
  float v = h(x/2);
  return 2*v*g(x/2);
}
float g(float x){
  float tol=1e-6;
  if(abs(x)<tol)return 1+x*x/2;
  float v = h(x/2);
  return 1+v*v*2;
}

template <class T>
T*top(T v, int p){
  vector<int> stlv;
//  cout<<"fill stlv\n";
//  cout<<"v.size = "<<v.size()<<endl;
  for(int i=0;i<v.size();i++){
    stlv.push_back(v[i]);
  }
  sort(stlv.begin(), stlv.end());
//  cout<<"finish sorting\n";
  T *temp = new T;
  for(int i=0;i<p;i++){
    temp->append(stlv[stlv.size()-p+i]);
  }
//  cout<<"finish filling top vect\n";
  return temp;
}

template <class T>
T *mode(T v){
  vector<int> vect;
  for(int i=0;i<v.size();i++){
    vect.push_back(v[i]);
  }
  sort(vect.begin(), vect.end());
  cout<<"print out sort data\n";
  for(int i=0;i<vect.size();i++){
    cout<<vect[i]<<" ";
  }
  cout<<endl;
  set<int> num;
  map<int,int> mode;
  map<int,int>::iterator iter;
  for(int i=0;i<v.size();i++){
    if(num.insert(v[i]).second){
      mode[v[i]]=0;
    }
  }
  for(int i=0;i<v.size();i++){
    mode[v[i]]++;
  }
  int largest = max_element(mode.begin(),mode.end(), cmp())->second;
  T *temp = new T;
  for(iter=mode.begin();iter!=mode.end();iter++){
    if(iter->second==largest)
      temp->append(iter->first);
  }
  return temp;
}

template <class T>
statClass * stat(T obj){
  vector<int> vect;
  for(int i=0;i<obj.size();i++){
    vect.push_back(obj[i]);
  }
  statClass *a = new statClass(vect);
  return a;
}
template <class T>
statClass * stat(T obj, int dum){
  statClass *a = new statClass(obj, dum);
  return a;
}