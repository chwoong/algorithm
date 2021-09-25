/*
 *  author: chw0501
 *  reference: 
 *  created: 13.12.2020 08:38:05(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n, m;
vector<int> adj[100001];
int depth[100001];
int par[100001][20];

void dfs(int i){
	for(int next: adj[i]){
		if(depth[next] == -1){
			par[next][0] = i;
			depth[next] = depth[i] + 1;
			dfs(next);
		}
	}
}

int lca(int u, int v){
	//depth[u] <= depth[v] ¸¦ º¸Àå
	if(depth[u] > depth[v]) swap(u, v);
	for(int i = 19; i >= 0; i--){
		if((depth[v]-depth[u]) >= (1<<i)) v = par[v][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(par, -1, sizeof(par));
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;
	dfs(1);
	for(int i = 1; i < 20; i++){
		for(int j = 1; j <= n; j++){
			if(par[j][i-1] != -1) par[j][i] = par[par[j][i-1]][i-1];
		}
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}