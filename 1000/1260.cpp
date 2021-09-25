#include<iostream>
#include<queue>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> ord;

class Graph{
	private:
	int num;
	vector<vector<int>> adj;
	vector<bool> visited;
	
	public:
	Graph(int n){
		num=n;
		adj.resize(n+1);
		visited.resize(n+1,false);
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void sorting(){
		for(int i=1;i<=num;i++){
			sort(adj[i].begin(),adj[i].end());
		}
	}
	void dfs(int here){
		ord.push_back(here);
		visited[here]=true;
		for(int next:adj[here]){
			if(!visited[next]) dfs(next);
		}
	}
	vector<int> bfs(int i){
		queue<int>q;
		vector<int> order_bfs;
		fill(visited.begin(),visited.end(),false);
		visited[i]=true;
		q.push(i);
		while(!q.empty()){
			int here=q.front();
			q.pop();
			order_bfs.push_back(here);
			for(int next:adj[here]){
				if(!visited[next]){
					q.push(next);
					visited[next]=1;
				}
			}
		}
		return order_bfs;
	}
	
};

int main(){
	int N,M,V;
	cin >> N >> M >> V;
	
	Graph g(N);
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u>>v;
		g.addEdge(u,v);
	}
	g.sorting();
	
	g.dfs(V);
	for(int i:ord)
		cout<< i <<" ";
	cout<< endl;
	
	vector<int> order(g.bfs(V));
	for(int i:order)
		cout<< i <<" ";
	
}