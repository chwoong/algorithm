#include <iostream>
#include <vector>

using namespace std;

class Graph{
	public:
	int num;
	vector<vector<int>> adj;
	vector<bool> visited;
	Graph(int n){
		num=n;
		adj.resize(n);
		visited.resize(n,false);
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int here){
		visited[here]=true;
		for(int i:adj[here]){
			if(!visited[i]) dfs(i);
		}
	}
	int dfsAll(){
		int components=0;
		for(int i=0;i<num;i++){
			if(!visited[i]){
				dfs(i);
				components++;
			}
		}
		return components;
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	Graph g(n);
	
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g.addEdge(u-1,v-1);
	}
	cout << g.dfsAll();
	
	return 0;
}


