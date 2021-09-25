#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>

using namespace std;

int a,b;
int arr[200001],brr[200001];
set<int> s;

int main(){
	cin >> a >>b;
	int j;
	for(int i=0;i<a;i++){
		cin>>j;
		s.insert(j);
	}
	set<int>::iterator iter;
	int x=0;
	for(int i=0;i<b;i++){
		cin>>brr[i];
		iter=s.find(brr[i]);
		if(iter!=s.end()) x++;
	}
	cout<< a+b-2*x;
	
	return 0;
}