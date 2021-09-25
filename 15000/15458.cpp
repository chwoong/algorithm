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
#include<cmath>
#include<time.h>
using namespace std;

#define MOD 1000000007
int n,k;
int color[100001];
vector<int> adj[100001];
long long dp[100001][4];

//부모가 p인 정점 x를 색깔 i로 칠할 때 x를 root로 하는 트리의 색칠 가짓수
long long solve(int x,int i,int p){
	long long&ret=dp[x][i];
	if(ret!=-1ll) return ret;
	ret=1;
	for(int next:adj[x]){
		if(next==p) continue;
		if(color[next]==i) {ret=0; break;}
		else if(color[next]!=0){
			ret=(ret*solve(next,color[next],x))%MOD;
		}else{
			long long val=0;
			for(int j=1;j<=3;j++){
				if(j!=i) val+=solve(next,j,x);
			}
			ret=(ret*val)%MOD;
		}
	}
	return ret;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(dp,-1ll,sizeof(dp));
	for(int i=0;i<k;i++){
		int b,c;
		scanf("%d %d",&b,&c);
		color[b]=c;
	}
	long long ans=0;
	if(color[1]==0){
		ans=solve(1,1,0);
		ans=(ans+solve(1,2,0))%MOD;
		ans=(ans+solve(1,3,0))%MOD;
	}
	else ans=solve(1,color[1],0);
	cout<<ans;
	return 0;
}