#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>

using namespace std;

/* m[i]=Ai */
map<long long,long long>m;

long long n;
long long p,q;

long long f(long long i){
	if(i==0) return 1;
	map<long long,long long>::iterator iter;
	long long x=0;
	iter=m.find(i/p);
	if(iter!=m.end()) x+=(*iter).second;
	else x+=f(i/p);
	
	iter=m.find(i/q);
	if(iter!=m.end()) x+=(*iter).second;
	else x+=f(i/q);
	m[i]=x;
	return x;
}

int main(){
	cin >> n >> p >> q;
	m[0]=1;
	cout<< f(n);
	
	return 0;
}