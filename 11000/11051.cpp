#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
using namespace std;

#define MOD 10007

int dp[1001][1001];

int solve(int n,int k){
	int & ret=dp[n][k];
	if(ret!=-1) return ret;
	if(k==1) return ret=n;
	if(k==0) return ret=1;
	if(n==k) return ret=1;
	return ret=(solve(n-1,k)+solve(n-1,k-1))%MOD;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,k;
	cin>>n>>k;
	cout<<solve(n,k);
	return 0;
}