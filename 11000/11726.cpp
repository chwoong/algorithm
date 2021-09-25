#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

#define MOD 10007

int dp[1001];

int solve(int i){
	int&ret=dp[i];
	if(ret!=-1) return ret;
	if(i==0 || i==1) return ret=1;
	return ret=(solve(i-2)+solve(i-1))%MOD;
}
int main(){
	memset(dp,-1,sizeof(dp));
	int n;
	cin>>n;
	cout<<solve(n);
	return 0;
}