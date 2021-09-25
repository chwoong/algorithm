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


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		maxflow mf;
		int i,g,s;
		scanf("%d %d %d",&i,&g,&s);
		//처음 일행으로 가는 유량
		mf.addEdge(0,(s+1)*i,g);
		int m;
		scanf("%d",&m);
		//병원에서 sink로의 연결
		for(int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			for(int k=0;k<=s;k++){
				mf.addEdge((s+1)*x+k,(s+1)*(n+1),INF);
			}
		}
		/*길의 연결*/
		int r;
		scanf("%d",&r);
		for(int j=0;j<r;j++){
			int a,b,p,ti;
			scanf("%d %d %d %d",&a,&b,&p,&ti);
			for(int k=0;k<=s-ti;k++){
				mf.addEdge((s+1)*a+k,(s+1)*b+k+ti,p);
			}
		}
		/*가만히 있는 경우*/
		for(int j=1;j<=n;j++){
			for(int k=0;k<s;k++){
				mf.addEdge((s+1)*j+k,(s+1)*j+k+1,INF);
			}
		}
		/*flow*/
		printf("%d\n",mf.match(0,(s+1)*(n+1)));
		mf.clear();
	}
	return 0;
}