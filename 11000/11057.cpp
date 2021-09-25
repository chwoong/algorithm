#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
using namespace std;

#define MOD 10007

int dp[10][1001];

/*바로 전 숫자,앞으로 남은 숫자 개수*/
int solve(int prev,int n){
	int& ret=dp[prev][n];
	if(ret!=-1) return ret;
	if(n==0) return ret=1;
	ret=0;
	for(int i=prev;i<=9;i++){
		ret=(ret+solve(i,n-1))%MOD;
	}
	return ret;
}

int main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int i=0;i<=9;i++)
		ans=(ans+solve(i,n-1))%MOD;
	cout<<ans;
	return 0;
}