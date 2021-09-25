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
int n,p;

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

vector<Edge*> adj[2000];
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
		vector<int>par(2000,-1);
		Edge* path[2000]={0};
		queue<int> q;;
		par[source]=source;
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
	cin>>n>>p;
	for(int i=0;i<p;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		addEdge(u,v,1);
	}
	cout<<networkflow(1,2);
	return 0;
}