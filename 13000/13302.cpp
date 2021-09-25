#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
using namespace std;

int N,M;
bool d[101];
//dp[i][j]: i일째까지 리조트 이요하고 j개의 쿠폰이 남았을 때 앞으로 필요한 최소 비용
int dp[101][40];
int solve(int i,int num){
	if(i>=N) return 0;
	int& ret=dp[i][num];
	if(ret!=-1) return ret;
	//i+1일부터 못가는 날은 skip
	int j=i+1;
	while(d[j]&&j<=N) j++;
	if(j==N+1) return ret=0;
	ret=37000+solve(j+4,num+2);
	ret=min(ret,25000+solve(j+2,num+1));
	ret=min(ret,10000+solve(j,num));
	if(num>=3) ret=min(ret,solve(j,num-3));
	return ret;
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int x;
		scanf("%d",&x);
		d[x]=true;
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0);
	return 0;
}