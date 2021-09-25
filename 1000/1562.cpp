#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MOD 1000000000

/* 남은길이, 바로 전에 쓴 숫자, 지금까지 쓴 숫자 목록 */
long long dp[101][10][2000];

long long solve(int n,int c,int l){
	long long &ret=dp[n][c][l];
	if(ret!=-1) return ret;
	if(n==0 && l==1023) return ret=1;
	else if(n==0) return ret=0;
	if(c==0) ret=solve(n-1,1,l|2);
	else if(c==9) ret=solve(n-1,8,l|(1<<8));
	else ret=solve(n-1,c-1,l|(1<<(c-1)))+solve(n-1,c+1,l|(1<<(c+1)));
	ret=ret%MOD;
	return ret;
}

int main(){
	int N;
	cin>>N;
	memset(dp,-1,sizeof(dp));
	long long num=0;
	for(int i=1;i<=9;i++){
		num=(num+solve(N-1,i,1<<i))%MOD;
	}
	cout<<num;
	return 0;
}