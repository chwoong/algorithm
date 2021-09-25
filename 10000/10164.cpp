#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int comb[50][50];

int solve(int i,int j){
	int &ret=comb[i][j];
	if(ret!=-1) return ret;
	if(j==0) return ret=1;
	if(j==1) return ret=i;
	if(i==1) return ret=1;
	if(i==j) return ret=1;
	ret=solve(i-1,j-1)+solve(i-1,j);
	return ret;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int x=k/m;
	int y=k-m*(k/m)-1;
	if(k==0) y=0;
	memset(comb,-1,sizeof(comb));
	//(x+y)Cx 와 m-1-y+n-1-xCn-1-x 를 구하자
	printf("%d",solve(x+y,x)*solve(n+m-2-x-y,n-1-x));
	
	return 0;
}