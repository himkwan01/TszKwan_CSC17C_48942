/* 
 * File:   structure.h
 * Author: Himkw_000
 *
 * Created on October 27, 2015, 5:06 PM
 */

#ifndef STRUCTURE_H
#define	STRUCTURE_H
#include <bits/stdc++.h>
using namespace std;

struct cmp{
  bool operator()(const pair<int, int> &a, const pair<int, int> &b){
    return a.second<=b.second? true:false;
  }
};


#endif	/* STRUCTURE_H */

