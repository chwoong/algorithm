#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
using namespace std;

int p[1001];
int dp[1001];

/*남은 카드 개수*/
int solve(int n){
	int& ret=dp[n];
	if(ret!=-1) return ret;
	if(n==0) return ret=0;
	if(n==1) return ret=p[1];
	ret=0;
	for(int i=1;i<=n;i++)
		ret=max(ret,solve(n-i)+p[i]);
	return ret;
}

int main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		scanf("%d ",p+i);
	cout<<solve(n);
}