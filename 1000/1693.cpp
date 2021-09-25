/*
 *  author: chw0501
 *  reference: https://www.acmicpc.net/board/view/13972
 *  created: 19.04.2020 02:22:00(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define INF 10000000
int n;
vector<int> adj[100001];

//dp[i]: i번 정점을 col로 칠할 때 i번부터 시작한 최소 비용
int dp[19][100001];

int solve(int col,int curr,int prev){
	int & ret=dp[col][curr];
	if(ret!=-1) return ret;
	ret=col;
	for(int next:adj[curr]){
		if(next!=prev){
			int val=INF;
			for(int j=1;j<=18;j++){
				if(col!=j) val=min(val,solve(j,next,curr));
			}
			ret+=val;
		}
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++) {
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(dp,-1,sizeof(dp));
	//색깔을 1~18까지 이용
	int ans=INF;
	for(int i=1;i<=18;i++){
		ans=min(ans,solve(i,1,0));
	}
	cout<<ans;
	return 0;
}