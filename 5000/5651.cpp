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

#define INF 987654321
struct Edge{
	int to,cap,flow;
	Edge* reverse;
	Edge(int t,int c):to(t),cap(c),flow(0),reverse(nullptr){}
	int residual(){
		return cap-flow;
	}
	void push(int amt){
		flow += amt;
		reverse->flow -= amt;
	}
};

vector<Edge*> adj[1000];
//´Ü¹æÇâ
void addEdge(int u,int v,int c){
	Edge* uv = new Edge(v,c);
	Edge* vu = new Edge(u,0);
	uv -> reverse = vu;
	vu -> reverse = uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}


int networkflow(int source,int sink){
	int total=0;
	while(1){
		vector<int>par(1000,-1);
		Edge* path[1000]={0};
		queue<int> q;;
		//par[source]=source;
		q.push(source);
		while(!q.empty() && par[sink]==-1){
			int here=q.front(); q.pop();
			for(Edge* e:adj[here]){
				int next=e->to;
				if(e->residual()>0 && par[next]==-1){
					q.push(next);
					par[next]=here;
					path[next]=e;
				}
			}
		}
		if(par[sink]==-1) break;
		int amount=INF;
		for(int i=sink;i!=source;i=par[i]){
			amount=min(amount,path[i]->residual());
		}
		for(int i=sink;i!=source;i=par[i]){
			path[i]->push(amount);
		}
		total+=amount;
	}
	return total;
}

int main(){
	int k;
	cin>>k;
	while(k--){
		int n,m;
		cin>>n>>m;
		int val[310][310];
		memset(val,0,sizeof(val));
		for(int i=0;i<m;i++){
			int f,t,b;
			scanf("%d %d %d",&f,&t,&b);
			addEdge(f,t,b);
		}
		int maxflow=networkflow(1,n);
		int ans=0;
		
		bool connected[500][500]={0,};
		for(int i=1;i<=n;i++){
			for(Edge* e:adj[i]){
				if(e->residual()>0){
					connected[i][e->to]=true;
				}
			}
		}
		for(int x=1;x<=n;x++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(connected[i][x] && connected[x][j]) connected[i][j]=true;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(Edge* e:adj[i]){
				if(e->cap!=0 && !connected[i][e->to]) ans++;
			}
		}
		
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			adj[i].clear();
		}
	}
	
	return 0;
}