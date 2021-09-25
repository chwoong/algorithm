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
#define MAX 110000
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
		while(!q.empty()){
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


int main(){
	int m,n;
	cin>>m>>n;
	maxflow mf;
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d",&x);
		mf.addEdge(0,i,x);
	}
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		vector<int> v;
		v.clear();
		for(int j=0;j<a;j++){
			int x;
			scanf("%d",&x);
			v.push_back(x);
			mf.addEdge((i-1)*m+x,n*m+i,INF);
		}
		int b;
		scanf("%d",&b);
		mf.addEdge(n*m+i,n*m+n+1,b);
		if(i!=n){
			for(int j=1;j<=m;j++){
				mf.addEdge((i-1)*m+j,i*m+j,INF);
			}
			for(int j:v){
				for(int k:v){
					mf.addEdge((i-1)*m+j,i*m+k,INF);
				}
			}
		}
	}
	cout<<mf.match(0,n*m+n+1);
	return 0;
}