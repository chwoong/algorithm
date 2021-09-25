#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;
int N;
vector<vector<pair<int,int>>> adj;
bool visited[10001];
int tmp=1;
int dist[10001];
int m=0;

void dfs(int curr){
	visited[curr]=true;
	if(adj[curr].size()==0) return;
	for(pair<int,int> next:adj[curr]){
		int n=next.first;
		if(visited[n]==true) continue;
		dist[n]=dist[curr]+next.second;
		if(dist[n]>m) {m=dist[n];tmp=n;}
		dfs(n);
	}
}

int main(){
	cin >>N;
	adj.reserve(N+1);
	int parent, child, w;
	for(int i=0;i<N-1;i++){
		cin >> parent >> child >> w;
		adj[parent].push_back(make_pair(child,w));
		adj[child].push_back(make_pair(parent,w));
	}
	memset(&visited[0],false,sizeof(visited));
	dist[1]=0;
	dfs(1);
	memset(&visited[0],false,sizeof(visited));
	m=0;
	dist[tmp]=0;
	dfs(tmp);
	cout<<m;
	
	return 0;
}