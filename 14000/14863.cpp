#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,k;
/*[0]: 도보 [1]: 자전거*/
int cost[2][100];
int tim[2][100];

int dp[101][100001];

/*도시 i까지 이동했을 때 t시간 이상이 남았을 때 앞으로의 최대 모금액*/
int solve(int i,int t){
	if(i==n){
		if(t>=0) return 0;
		else return -1000000000;
	}
	if(t<0) return -1000000000;
	int& ret=dp[i][t];
	if(ret!=-1) return ret;
	ret=-1000000000;
	ret=max(ret,cost[0][i]+solve(i+1,t-tim[0][i]));
	ret=max(ret,cost[1][i]+solve(i+1,t-tim[1][i]));
	return ret;
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<2;j++)
			scanf("%d %d",&tim[j][i],&cost[j][i]);
	
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,k);
	return 0;
}