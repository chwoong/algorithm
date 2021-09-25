#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
int k;
int judge=0;
bool visited[501];

class Graph{
	public:
	int num;
	vector<vector<int>> adj;
	vector<int> parent;
	Graph(int i){
		num=i;
		adj.resize(num+1);
	}
	void setEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int curr,int before){
		visited[curr]=true;
		for(int next:adj[curr]){
			if(visited[next]&&next!=before) {k=0; break;}
		}
		for(int next:adj[curr]){
			if(!visited[next]){
				dfs(next,curr);
			}
		}
		
	}
};

int main(){
	int t=1;
	while(1){
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==0) break;
		Graph g(n);
		memset(visited,false,sizeof(visited));
		int x,y;
		for(int i=0;i<m;i++){
			scanf("%d %d",&x,&y);
			g.setEdge(x,y);
		}
		judge=0;
		k=1;
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				g.dfs(i,0);
				if(k==1) {judge++;}
				k=1;
			}
		}
		cout<<"Case "<<t<<": ";
		if(judge>1) cout<<"A forest of "<<judge<<" trees."<<endl;
		else if(judge==1) cout<<"There is one tree."<<endl;
		else cout<<"No trees."<<endl;
		t++;
	}
	return 0;
}