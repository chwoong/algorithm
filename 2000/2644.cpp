#include<iostream>
#include<queue>
#include <vector>
#include<algorithm>

using namespace std;

class Graph{
	private:
	int num;
	vector<vector<int>> adj;
	vector<bool> visited;
	queue<int> q;
	vector<int>distance;
	public:
	Graph(int n){
		num=n;
		adj.resize(n);
		visited.resize(n,false);
		distance.resize(n);
	}
	
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int bfs(int start,int finish){
		q.push(start);
		visited[start]=true;
		distance[start]=0;
		while(!q.empty()){
			int here = q.front();
			q.pop();
			for(int next:adj[here]){
				if(!visited[next]){
					visited[next]=true;
					q.push(next);
					distance[next]=distance[here]+1;
				}
				if(next==finish) return distance[next];
			}
		}
		return -1;
		
	}
	
	
};

int main(){
	int N,p1,p2,m;
	cin >> N >> p1 >> p2 >> m;
	Graph g(N);
	for(int i=0;i<m;i++){
		int x,y;
		cin>> x>>y;
		g.addEdge(x-1,y-1);
	}
	cout<< g.bfs(p1-1,p2-1);
	
	return 0;
}