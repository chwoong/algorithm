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

#define MAX 52
#define INF 987654321
struct Edge{
	int to,cap,flow;
	Edge* reverse;
	Edge(int t,int c):to(t),cap(c),flow(0),reverse(nullptr){}
	int residual(){
		return cap-flow;
	}
	void push(int amt){
		flow+=amt;
		reverse->flow -= amt;
	}
};

vector<Edge*> adj[MAX];
void addEdge(int u,int v,int c){
	Edge* uv= new Edge(v,c);
	Edge* vu= new Edge(u,c);
	uv->reverse=vu;
	vu->reverse=uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}

int networkflow(int source,int sink){
	int total=0;
	while(1){
		vector<int> par(MAX,-1);
		Edge* path[MAX]={0};
		queue<int> q;
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
		//증가 경로가 없으면 종료
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

int n;

int f(char x){
	if(x>='a') return (x-'a')+26;
	else return x-'A';
}

int m[MAX][MAX];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char x[10];
		char y[10];
		int w;
		scanf("%s %s %d",x,y,&w);
		int u=f(x[0]);
		int v=f(y[0]);
		m[u][v]+=w;
		m[v][u]+=w;
	}
	for(int i=0;i<52;i++){
		for(int j=i+1;j<52;j++){
            if(m[i][j]>0) addEdge(i,j,m[i][j]);
		}
	}
	cout<<networkflow(f('A'),f('Z'));
	return 0;
}