#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int cycle=0;
class Graph{
	private:
	/* 정점 개수 */
	int num;
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<bool> finished;
	
	public:
	Graph(int n){
		num=n;
		adj.resize(num);
		visited.resize(num,false);
		finished.resize(num,false);
	}
	void addEdge(int u,int v){
		adj[u].push_back(v);
	}
	void dfs(int i){
		visited[i]=true;
		for(int next:adj[i]){
			if(!visited[next]) dfs(next);
			else if(finished[next]==false){
				for(int tmp=next;tmp!=i;tmp=adj[tmp][0]){
					cycle++;
				}
				cycle++;
			}
		}
		finished[i]=true;
	}
	
	void dfsAll(){
		for(int i=0;i<num;i++){
			if(!visited[i]) {
				dfs(i);
			}
		}
	}
	
};

int main(){
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		int n;
		cin >> n;
		/* 정점 n개의 그래프 생성*/
		Graph g(n);
		/* 원하는 사람의 방향 간선 추가 */
		for(int j=0;j<n;j++){
			int tmp;
			cin >>tmp;
			g.addEdge(j,tmp-1);
		}
		g.dfsAll();
		cout << n-cycle << endl;
		cycle=0;
	}
	
	return 0;
}

