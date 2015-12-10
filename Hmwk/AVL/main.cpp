/* 
 * File:   main.cpp
 * Author: Himkw_000
 *
 * Created on December 9, 2015, 8:21 PM
 */

/*
 * Tsz Kwan
 * CSC 17C 48942 
 * AVL Tree
 */



#include <bits/stdc++.h>
#include "AVL.h"
//#include "test.cpp"
using namespace std;

int main(){

	cout<<"AVL Tree\n";
	int arr[] = {5,4,3,6,8,2,1};
	cout<<"Print elements :";
	for(int i=0;i<7;i++)
		cout<<arr[i]<<" ";
	cout<<"\n\n";
	AVLTree<int> a;
	
	for(int i=0;i<7;i++)
		a.insert(arr[i]);
	cout<<"PreOrder :";
	a.preOrder();
	cout<<"\nInOrder :";
	a.inOrder();
	cout<<"\nPostOrder :";
	a.postOrder();
  
  cout<<"Remove 6\n";
  a.remove(6);
  cout<<"PreOrder :";
	a.preOrder();
	cout<<"\nInOrder :";
	a.inOrder();
	cout<<"\nPostOrder :";
	a.postOrder();
	return 0;
}

