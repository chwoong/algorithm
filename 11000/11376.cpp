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
vector<int> adj[3000];
int a[3000];
int b[3000];
bool visited[3000];

bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=1;
	for(int next:adj[i]){
		if(b[next]==-1 || dfs(b[next])){
			a[i]=next;
			b[next]=i;
			return 1;
		}
	}
	return 0;
}


int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		for(int j=0;j<x;j++){
			int v;
			scanf("%d",&v);
			adj[2*i].push_back(v);
			adj[2*i+1].push_back(v);
		}
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	
	int cnt=0;
	for(int i=0;i<2*n;i++){
		memset(visited,0,sizeof(visited));
		if(dfs(i)) cnt++;
	}
	cout<<cnt;
	return 0;
}