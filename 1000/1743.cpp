#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int ab(int i){
	return i<0?-i:i;
}

int big=0;

class Graph{
	private:
	/* 정점 개수 */
	int num;
	vector<vector<int>> adj;
	vector<bool> visited;
	
	public:
	Graph(int n){
		num=n;
		adj.resize(num);
		visited.resize(num,false);
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int dfs(int i){
		visited[i]=true;
		if(adj[i].size()==0) return 1;
		int tmp=1;
		for(int next:adj[i]){
			if(!visited[next]) {
				tmp+=dfs(next);
			}
		}
		return tmp;
	}
	
	void dfsAll(){
		for(int i=0;i<num;i++){
			if(!visited[i]) {
				big=max(big,dfs(i));
			}
		}
	}
	
};

int main(){
		int n,m,k;
		cin >> n>>m>>k;
		/* 정점 n개의 그래프 생성*/
		Graph g(k);
		/* 원하는 사람의 방향 간선 추가 */
		vector<pair<int,int>>food;
		for(int i=0;i<k;i++){
			int x,y;
			cin >> x >> y;
			food.push_back(make_pair(x,y));
			for(int j=0;j<food.size()-1;j++){
				if((ab(food[j].first-x)+ab(food[j].second-y))==1){
					g.addEdge(food.size()-1,j);
				}
			}
		}
		g.dfsAll();
		cout << big;
	
	return 0;
}

