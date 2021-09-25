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

typedef pair<int,int> P;
int n,m;
vector<P>adj[40001];
int par[40001][20];
int dist[40001][20];
int depth[40001];

void dfs(int i){
	for(auto& next:adj[i]){
		if(depth[next.first]==-1){
			depth[next.first]=depth[i]+1;
			par[next.first][0]=i;
			dist[next.first][0]=next.second;
			dfs(next.first);
		}
	}
}

int query(int u,int v){
	//depth[u]>=depth[v]
	int ret=0;
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if(depth[u]-depth[v]>=(1<<i)){
			ret+=dist[u][i];
			u=par[u][i];
		}
	}
	if(u==v) return ret;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			ret+=dist[u][i];
			ret+=dist[v][i];
			u=par[u][i];
			v=par[v][i];
		}
	}
	return ret+dist[u][0]+dist[v][0];
}

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(P(b,c));
		adj[b].push_back(P(a,c));
	}
	memset(par,-1,sizeof(par));
	memset(depth,-1,sizeof(depth));
	memset(dist,-1,sizeof(dist));
	depth[1]=0;
	dfs(1);
	
	for(int j=0;j<19;j++){
		for(int i=1;i<=n;i++){
			if(par[i][j]!=-1){
				par[i][j+1]=par[par[i][j]][j];
				dist[i][j+1]=dist[i][j]+dist[par[i][j]][j];
			}
		}
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",query(u,v));
	}
	return 0;
}