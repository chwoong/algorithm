#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int a,b,c,n;
int dp[301];
int solve(int i){
	if(i<0) return 0;
	int&ret=dp[i];
	if(ret!=-1) return ret;
	return ret=(solve(i-a)||solve(i-b)||solve(i-c));
}
int main(){
	cin>>a>>b>>c>>n;
	memset(dp,-1,sizeof(dp));
	dp[0]=1;
	dp[a]=1;
	dp[b]=1;
	dp[c]=1;
	cout<<solve(n);
	return 0;
}