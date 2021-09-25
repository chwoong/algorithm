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

#define MAX 3050
#define INF 987654321
struct maxflow{
	struct edge{
		int to,cap,flow,rev;
		int residual(){
			return cap-flow;
		}
	};
	vector<edge> adj[MAX];
	int par[MAX], ind[MAX];
	bool visited[MAX]={0,};
	
	void clear(){
		for(int i=0;i<MAX;i++) adj[i].clear();
		memset(visited,0,sizeof(visited));
	}
	void addEdge(int u,int v,int c){
		adj[u].push_back((edge){v,c,0,(int)adj[v].size()});
		adj[v].push_back((edge){u,0,0,(int)adj[u].size()-1});
	}
	
	bool bfs(int src,int sink){
		memset(visited,0,sizeof(visited));
		queue<int> q;
		q.push(src);
		visited[src]=true;
		while(!q.empty() && !visited[sink]){
			int here=q.front(); q.pop();
			int len=adj[here].size();
			for(int i=0;i<len;i++){
				edge e=adj[here][i];
				if(e.residual()>0 && !visited[e.to]){
					visited[e.to]=true;
					par[e.to]=here;
					ind[e.to]=i;
					q.push(e.to);
				}
			}
		}
		return visited[sink];
	}
	int match(int src,int sink){
		int total=0;
		while(bfs(src,sink)){
			int amount=INF;
			for(int i=sink;i!=src;i=par[i]){
				amount=min(amount,adj[par[i]][ind[i]].residual());
			}
			for(int i=sink;i!=src;i=par[i]){
				int r=adj[par[i]][ind[i]].rev;
				adj[par[i]][ind[i]].flow+=amount;
				adj[i][r].flow-=amount;
			}
			total+=amount;
		}
		return total;
	}
};

int n,m,k;


int main(){
	cin>>n>>m>>k;
	maxflow mf;
	
	//0번 점 src
	//1번 점 capacity k의  src2
	//2번 ~ 2*n+1: 직원
	//2n+2 ~ 2*n+m+1: 일
	//2*n+m+2: sink
	mf.addEdge(0,1,k);
	for(int i=1;i<=n;i++){
		mf.addEdge(0,2*i,1);
		mf.addEdge(1,2*i+1,1);
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int v;
			scanf("%d",&v);
			mf.addEdge(2*i,2*n+1+v,1);
			mf.addEdge(2*i+1,2*n+1+v,1);
		}
	}
	for(int i=2*n+2;i<=n*2+m+1;i++){
		mf.addEdge(i,2*n+m+2,1);
	}
	cout<<mf.match(0,2*n+m+2);
	return 0;
}