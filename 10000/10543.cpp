#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
using namespace std;

#define MAX 600000000000
int N,M,K;
int b[101];

//dp[m][k]: 1~m까지의 빌딩을 k번 나눴을 때 얻을 수 있는 최소 노이즈
long long dp[101][501];

long long solve(int m,int k){
	long long&ret=dp[m][k];
	if(ret!=-1) return ret;
	if(m==0) return 0;
	ret=MAX;
	//m번째 빌딩을 i번 나누면서 노이즈를 반환하자.
	for(int i=0;i<=k;i++){
		long long x=b[m]/(i+1);
		long long y=b[m]%(i+1);
		long long z=(1+x)*(b[m]+y)/2;
		ret=min(ret,solve(m-1,k-i)+z);
	}
	return ret;
}

int main(){
	cin>>N>>M>>K;
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		b[x]++;
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(M,K);
	return 0;
}