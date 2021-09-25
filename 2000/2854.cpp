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

#define MOD 1000000007
//dp[i][0]: i번째 문제까지 정하는데, 난이도 i~(i+1)의 문제를 사용 안한 경우
//dp[i][1]: i번째 문제까지 정하는데, 난이도 i~(i+1)의 문제를 사용 한 경우
long long dp[100001][2];
int n;
long long arr[100001];
long long brr[100001];

long long solve(int i,int j){
	long long& ret=dp[i][j];
	if(ret!=-1ll) return ret;
	if(j==0){
		ret=(solve(i-1,0)*(arr[i]+brr[i-1]))%MOD+(solve(i-1,1)*(arr[i]+brr[i-1]-1))%MOD;
	}
	else{
		ret=((solve(i-1,0)+solve(i-1,1))%MOD)*brr[i];
	}
	ret=ret%MOD;
	return ret;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",arr+i);
	}
	for(int i=1;i<n;i++){
		scanf("%lld",brr+i);
	}
	memset(dp,-1ll,sizeof(dp));
	dp[1][0]=arr[1];
	dp[1][1]=brr[1];
	cout<<(solve(n,0)+solve(n,1))%MOD;
	return 0;
}