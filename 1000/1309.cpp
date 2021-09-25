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
using namespace std;

int n;
int dp[100001][2];

int solve(int i,int s){
	int&ret=dp[i][s];
	if(i==1){
		if(s==0) return 3;
		else return 2;
	}
	if(ret!=-1) return ret;
	if(s==0){
		ret=2*solve(i-1,1)+solve(i-1,0);
	}else{
		ret=solve(i-1,0)+solve(i-1,1);
	}
	return ret=ret%9901;
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n;
	cout<<solve(n,0);
	return 0;
}