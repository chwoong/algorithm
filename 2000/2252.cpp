#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n,m;
vector<int> adj[32001];
int indeg[32001];
int t[501];
int ans[501];
queue<int> q;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		indeg[b]++;
		adj[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(indeg[i]==0) q.push(i);
	}
	for(int i=0;i<n;i++){
		int x=q.front();
		q.pop();
		printf("%d ",x);
		for(int next:adj[x]){
			if(--indeg[next]==0) q.push(next);
		}
	}
	return 0;
}