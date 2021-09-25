#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;

class Graph{
	public:
	int num;
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<int> parent;
	Graph(int i){
		num=i;
		adj.resize(num+1);
		visited.resize(num+1,false);
		parent.resize(num+1,-1);
	}
	void setEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void bfs(){
		queue<int> q;
		visited[1]=true;
		q.push(1);
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			for(int next:adj[curr]){
				if(!visited[next]){
					visited[next]=true;
					q.push(next);
					parent[next]=curr;	
				}
			}
		}
	}
	void printparent(){
		for(int i=2;i<=N;i++){
			printf("%d\n",parent[i]);
		}
	}
};

int main(){
	cin >>N;
	Graph g(N);
	int x,y;

	for(int i=1;i<N;i++){
		scanf("%d %d",&x,&y);
		g.setEdge(x,y);
	}
	
	g.bfs();
	g.printparent();
	
	return 0;
}