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
#include<cmath>
using namespace std;

int N,r,c;

int recall(int i,int j,int n){
	if(n==0) return 0;
	int ret;
	bool a=i<(1<<(n-1));
	bool b=j<(1<<(n-1));
	if(a && b) ret=recall(i,j,n-1);
	else if(a && !b) ret=(1<<(2*n-2))+recall(i,j-(1<<(n-1)),n-1);
	else if(!a && b) ret=(1<<(2*n-2))*2+recall(i-(1<<(n-1)),j,n-1);
	else ret=(1<<(2*n-2))*3+recall(i-(1<<(n-1)),j-(1<<(n-1)),n-1);
	return ret;
}

int main(){
	cin>>N>>r>>c;
	cout<<recall(r,c,N);
	return 0;
}