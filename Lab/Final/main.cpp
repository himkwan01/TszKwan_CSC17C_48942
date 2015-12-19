/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on December 14, 2015, 4:07 PM
 */
#include <fstream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

//User Libraries
#include "Stack.h"
#include "Queue.h"
#include "Linked_List.h"
#include "AVL.h"
#include "Sort.h"
#include "Graph.h"

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
string p1Hash(char *);
float h(float, Stack<char> *);
float g(float, Stack<char> *); //cosh
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
    default:;
    };
  }while(inN<7);
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
  cout<<"Type 7 to exit \n"<<endl;
}

//Choose problem number function
int getN(){
  int inN;
  cin>>inN;
  cin.ignore();
  return inN;
}
//hash
void problem1(){
  typedef map<string,int>::iterator miter;
  vector<string> vect;
  set<string> s;
  map<string,int> m;
  bool col=false;
  int collision;
  fstream io;
  int max=0;
  int ttl=0;
  string temp;
  io.open("P1_out.txt", ios::out);
  char *cstr = new char[3];
  for(int i=0;i<1000;i++){
    for(int j=0;j<3;j++){
      cstr[j] = rand()%26+65;
      io<<cstr[j];
    }
    io<<" ";
    temp = p1Hash(cstr);
//    cout<<temp<<endl;
    vect.push_back(temp);
    io<<temp<<endl;
    if(s.insert(temp).second){
      m[temp]=0;
    }
    else if(!col){
      col=true;
      collision=i+1;
    }
  }
  for(int i=0;i<vect.size();i++){
    m[vect[i]]++;
  }
  cout<<"First collision occured at "<<collision<<endl;
  for(miter iter=m.begin();iter!=m.end();iter++){
    if(max<iter->second)max=iter->second;
    ttl+=iter->second;
    ttl--;
  }
  cout<<"Max collision = "<<max<<endl;
  cout<<"Total collision = "<<ttl<<endl;
  cout<<"Average search = "<<static_cast<float>(1000)/ttl<<endl;
  io.close();
  delete []cstr;
}
//stack
void problem2(){
  Stack<char> *obj = new Stack<char>;
  float angDeg=45;
  float angRad=angDeg*atan(1)/45;
  cout<<"Problem 2 stack\n";
  cout<<"It take a while to get numbers of total call\n";
  cout<<"Angle = "<<angDeg<<" sinh = "<<sinh(angRad)<<
        " our h = "<<h(angRad, obj)<<endl;
  cout<<"Angle = "<<angDeg<<" cosh = "<<cosh(angRad)<<
        " our g = "<<g(angRad, obj)<<endl;
  int size = obj->getSize();
  int sh=0, ch=0;
  for(int i=0;i<size;i++){
    if(obj->operator [](i)=='c')ch++;
    else sh++;
  }
  cout<<"Total calls of sinh = "<<sh<<endl;
  cout<<"Total calls of cosh = "<<ch<<endl;
  
  delete obj;
}
//queue
void problem3(){
  cout<<"Problem 3 queue\n";
  int working=0;
  cout<<showpoint<<fixed<<setprecision(2);
  Queue<int> q;
  //free = false;
  vector<pair<bool, int> >clerk;
  float ttl=0;
  //initialize
  for(int i=0;i<3;i++){
    clerk.push_back(make_pair(true, 0));
  }
  
  //up to 30 min;
  //1=1s
  cout<<"output states (at the end of that second)\n";
  cout<<"Time  Line working  clerk size\n";
  int t = 60*60;
  for(int i=0;i<t;i++){
    for(int j=0;j<q.getSize();j++)q[j]+=1;    //increase 1 second
    if(i%20==0){ //20s add one more
      q.insert(0);
      
//      cout<<"Time = "<<i<<endl;
//      cout<<"Customer is inserted at "<<i<<endl;
//      cout<<"line = "<<q.getSize()<<endl;
//      cout<<"time = "<<i<<" insert\n";
    }
    //place customers
    if(q.getSize()!=0){
      int k=0;
      //find the avaliable clerk
      while(!clerk[k].first && k<=clerk.size())k++;
      //have avaliable
      if(k<clerk.size()){
//        cout<<"c"<<k+1<<" take the customers at "<<i<<endl;
//        cout<<"waiting time = "<<q[0]<<endl;
        clerk[k].first=false;
        clerk[k].second=i;
        working++;
//        cout<<"line = "<<q.getSize()<<endl;
        ttl+=q[0];
        if(k==0)ttl+=60;
        else if(k==1)ttl+=120;
        else if(k==2)ttl+=90;
        else ttl+=60;
        q.pop();
      }
      //no avaliable
      else{
        //create one more clerk if line>=5
        if(q.getSize()>=5){
//          cout<<"more than 5 waiting, create one more c\n";
//          cout<<"extra clerk take the customer at "<<i<<endl;
//          cout<<"waiting time = "<<q[0]<<endl;
          working++;
          clerk.push_back(make_pair(false, i));
          ttl+=q[0]+60;
          q.pop();
        }
        //if less than 5, just wait
      }
    }//have customers
    else{
      //no customers waiting
      sort(clerk.begin()+3,clerk.end());    //all free clerk will be at the end
      while(clerk[clerk.size()-1].first && clerk.size()>3){
        clerk.pop_back(); //pop all free
//        cout<<"pop back\n";
      }
    }//else
    //output states
    if(i%10==0)cout<<setw(4)<<i<<setw(4)<<q.getSize()<<setw(7)<<working<<setw(8)<<clerk.size()<<endl;
    //reset
    if(!clerk[0].first && (i-clerk[0].second)==60){
      clerk[0].first=true;
      working--;
//      cout<<"c1 is free at "<<i<<endl;
    }
    if(!clerk[1].first && (i-clerk[1].second)==120){
      clerk[1].first=true;
      working--;
//      cout<<"c2 is free at "<<i<<endl;
    }
    if(!clerk[2].first && (i-clerk[2].second)==80){
      clerk[2].first=true;
      working--;
//      cout<<"c3 is free at "<<i<<endl;
    }
    //additional clerk
    for(int j=3;j<clerk.size();j++){
      if(!clerk[j].first && (i-clerk[j].second)%60==0){
        clerk[j].first=true;
        working--;
      }
    }
  }//60 min
  cout<<"Up to 60 minutes\n";
  cout<<"All customers waiting time/number of customers\n";
  cout<<"waiting time = Leave time - come in time\n";
  cout<<"Average waiting time = "<<ttl/(60*180)<<" minute(s)"<<endl;
  
}
//sorting
void problem4(){
  cout<<"Problem 4 sorting\n";
  cout<<"It takes a while to finish selection and bubble sort\n";
  vector<short> v;
  long count=0;
  cout<<"rand 100000 short and output to p4.txt\n";
  fstream io;
  io.open("p4.txt", ios::out);
  //get 100000 rand num
  for(int i=0;i<100000;i++){
    short temp = rand()%32767;
    v.push_back(abs(temp));
    io<<v[i]<<endl;
  }
  io.close();
  count=0;
  cout<<"Heap operation:";
  assistHeap(v, v.size(), count); //heap
  cout<<count<<endl;
  count=0;
  cout<<"Merge operation: ";
  assisMerge(v, v.size(), count); //merge
  cout<<count<<endl;
  count=0;
  cout<<"Quick operation: ";
  assistQuick(v, 0, v.size()-1, count); //quickSort
  cout<<count<<endl;
  count=0;
  cout<<"Selection operation: ";
  selection(v, count);
  cout<<count<<endl;
  count=0;
  cout<<"Bubble operation: ";
  bubble(v, v.size(), count);
  cout<<count<<endl;
  cout<<"if you only want to get top 10 sorted element,\n";
  cout<<"selection sort will be the fastest routine\n";
  cout<<"because it only need to loop the list 10 times,\n";
  cout<<"which is 100000!/99990!\n";
  count=0;
  selection10(v, v.size(), count);
  cout<<"get top 10 elements selection sort operation = "<<count<<endl;
}

//binary tree
void problem5(){
  cout<<"Problem 5 Tree\n";
  AVLTree tree;
  stringstream ss;
  string temp;
  for(int j=0;j<1000;j++){
    ss.clear();
    for(int i=0;i<3;i++){
      ss<<rand()%26+65;
    }
    ss>>temp;
    tree.insert(temp);
  }//loop 1000
  cout<<"n = number of nodes\n";
  int n = tree.getSize();
  float t = log2(n)*1000/n;
  cout<<"searching per person = lg(n)*1000/n = "<<t<<endl;
}

//weighted graph
void problem6(){
  cout<<"Problem 6 weighted graph\n";
    Graph g(7);
    vector<string> names;
    names.push_back("SFO");
    names.push_back("ORD");
    names.push_back("JFK");
    names.push_back("DFW");
    names.push_back("MIA");
    names.push_back("LAX");
    names.push_back("BOS");
    g.addNames(names);
    g.addEdge("SFO","BOS",2704);
    g.addEdge("SFO","ORD",1846);
    g.addEdge("ORD","BOS",867);
    g.addEdge("ORD","JFK",740);
    g.addEdge("JFK","BOS",187);
    g.addEdge("SFO","DFW",1464);
    g.addEdge("DFW","ORD",802);
    g.addEdge("DFW","MIA",1121);
    g.addEdge("MIA","JFK",1090);
    g.addEdge("MIA","BOS",1258);
    g.addEdge("SFO","LAX",337);
    g.addEdge("LAX","DFW",1235);
    g.addEdge("LAX","MIA",2342);
    g.krusMST();
    g.shortestPath("BOS","LAX");
}

string p1Hash(char *str){
//  cout<<"Hash function\n";
//  for(int i=0;i<3;i++){
//    cout<<str[i];
//  }
  stringstream ss;
  string temp;
  for(int i=0;i<3;i++){
    if(str[i]>='A' && str[i]<='C')ss<<2;
    else if(str[i]>='D' && str[i]<='F')ss<<3;
    else if(str[i]>='G' && str[i]<='I')ss<<4;
    else if(str[i]>='J' && str[i]<='L')ss<<5;
    else if(str[i]>='M' && str[i]<='O')ss<<6;
    else if(str[i]>='P' && str[i]<='S')ss<<7;
    else if(str[i]>='T' && str[i]<='V')ss<<8;
    else ss<<9;
  }
  ss>>temp;
//  cout<<temp<<endl;
  return temp;
}

float h(float angR, Stack<char> *obj){
  obj->insert('s');
  float tol=1e-6;
  if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
  return 2*h(angR/2, obj)*g(angR/2, obj);
}
float g(float angR, Stack<char> *obj){
  obj->insert('c');
  float tol=1e-6;
  if(angR>-tol&&angR<tol)return 1+angR*angR/2;
  float b=h(angR/2, obj);
  return 1+2*b*b;
}
