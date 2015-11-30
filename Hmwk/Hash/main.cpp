#include <bits/stdc++.h>
#include "GeneralHashFunctions.h"
using namespace std;

int main(){
	srand(time(0));
	unsigned int size, mod;
	unsigned int ran=rand();
	vector<unsigned int> vect;
	set<unsigned int> s;
	map<unsigned int, unsigned int> m;
	map<unsigned int, unsigned int>::iterator iter;
	bool coll=false;
	int colNum;
	string msg = "CSC17C Hash test";
	cout<<"Enter the number of elements :";
	cin>>size;
	cout<<"Enter the number of buckets :";
	cin>>mod;
	for(unsigned int i=0;i<size;i++){
		stringstream ss;
		ss<<ran;
		string temp;
		ss>>temp;
		msg = msg + temp;
		ran++;
		vect.push_back(SDBMHash(msg)%mod);
		if(s.insert(vect[i]).second){
			m[vect[i]]=0;
		}
		else if(!coll){
			colNum=i+1;
			coll=true;
		}
	}
	for(int i=0;i<vect.size();i++){
		m[vect[i]]++;
	}
	unsigned int max =0;
	for(iter=m.begin();iter!=m.end();iter++)
		if(iter->second>max)max=iter->second;
	cout<<"first collision appears at "<<colNum<<endl;	
	cout<<"max collision = "<<max<<endl;
	
	return 0;
}