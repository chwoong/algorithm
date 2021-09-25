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

int n,m;
vector<int> adj[50001];
int depth[50001];
int par[50001][20];

void dfs(int i){
	for(int next:adj[i]){
		if(depth[next]==-1){
			depth[next]=depth[i]+1;
			par[next][0]=i;
			dfs(next);
		}
	}
}

int lca(int u,int v){
	//depth[u]>=depth[v]
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if(depth[u]-depth[v]>=(1<<i)){
			u=par[u][i];
		}
	}
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}
	return par[u][0];
}

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(par,-1,sizeof(par));
	memset(depth,-1,sizeof(depth));
	depth[1]=0;
	dfs(1);
	for(int j=0;j<19;j++){
		for(int i=1;i<=n;i++){
			if(par[i][j]!=-1)
				par[i][j+1]=par[par[i][j]][j];
		}
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
	
}