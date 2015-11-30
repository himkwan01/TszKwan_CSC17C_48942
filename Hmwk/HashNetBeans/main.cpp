#include <bits/stdc++.h>
#include "GeneralHashFunctions.h"
using namespace std;

int main(int argc, char** argv){
	srand(time(0));
	unsigned int size=300;
	unsigned int ran=1;
	bool coll[11];
	int colNum[11];
	string msg;
//	cout<<"Enter the number of elements :";
//	cin>>size;
  for(int a=1;a<=5;a++){
    ran=1;
    for(int b=0;b<11;b++)coll[b]=false;
    size*=10;
    cout<<"size = "<<size<<endl;
    vector<unsigned int> vect[11];
    set<unsigned int> s[11];
    map<unsigned int, unsigned int> m[11];
    map<unsigned int, unsigned int>::iterator iter;
    for(unsigned long i=0;i<size;i++){
      stringstream ss;
  		ss<<ran;
  		ran++;
      ss>>msg;
      for(int b=0;b<11;b++){
        switch(b){
          case 0: vect[b].push_back(RSHash(msg)%size);break;
          case 1: vect[b].push_back(JSHash(msg)%size);break;
          case 2: vect[b].push_back(PJWHash(msg)%size);break;
          case 3: vect[b].push_back(ELFHash(msg)%size);break;
          case 4: vect[b].push_back(BKDRHash(msg)%size);break;
          case 5: vect[b].push_back(SDBMHash(msg)%size);break;
          case 6: vect[b].push_back(DJBHash(msg)%size);break;
          case 7: vect[b].push_back(DEKHash(msg)%size);break;
          case 8: vect[b].push_back(BPHash(msg)%size);break;
          case 9: vect[b].push_back(FNVHash(msg)%size);break;
          case 10: vect[b].push_back(APHash(msg)%size);break;
        }
        if(s[b].insert(vect[b][i]).second){
          m[b].insert(make_pair(vect[b][i], 0));
        }
        else if(!coll[b]){
          colNum[b]=i+1;
          coll[b]=true;
        }
        
      }
    }
    for(int b=0;b<11;b++){
      for(int i=0;i<vect[b].size();i++){
        m[b][vect[b][i]]++;
      }
    }
    for(int b=0;b<11;b++){
      unsigned int max =0;
      switch(b){
        case 0: cout<<"RSHash\n";break;
        case 1: cout<<"JSHash\n";break;
        case 2: cout<<"PJWHash\n";break;
        case 3: cout<<"ELFHash\n";break;
        case 4: cout<<"BKDRHash\n";break;
        case 5: cout<<"SDBMHash\n";break;
        case 6: cout<<"DJBHash\n";break;
        case 7: cout<<"DEKHash\n";break;
        case 8: cout<<"BPHash\n";break;
        case 9: cout<<"FNVHash\n";break;
        case 10: cout<<"APHash\n";break;
      }
      for(iter=m[b].begin();iter!=m[b].end();iter++)
        if(iter->second>max)max=iter->second;
      cout<<"first collision appears at "<<colNum[b]<<endl;	
      cout<<"maximum collision = "<<max<<endl;
      coll[b]=false;
    }
    cout<<"\n\n";
	}
	return 0;
}