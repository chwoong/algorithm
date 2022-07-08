#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int ab(int i){
	return i<0?-i:i;
}

class Graph{
	private:
	/* ���� ���� */
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
	void dfs(int i){
		visited[i]=true;
		for(int next:adj[i]){
			if(!visited[next]) dfs(next);
		}
	}
	
	int dfsAll(){
		int components=0;
		for(int i=0;i<num;i++){
			if(!visited[i]) {
				dfs(i);
				components++;
			}
		}
		return components;
	}
	
};

int main(){
	int T,row,col,k;
	cin >> T;
	/* �� �׽�Ʈ ���̽� ���� */
	for(int t=0;t<T;t++){
		cin >> row >> col >> k;
		/* k���� ������ ���� graph */
		Graph g(k);
		/* ���� �Է� */
		vector<pair<int,int>> cabs;
		/* ���߰� ���� ���� */
		for(int i=0;i<k;i++){
			int x,y;
			cin >> x >> y;
			cabs.push_back(make_pair(x,y));
			for(int j=0;j<cabs.size()-1;j++){
				if((ab(cabs[j].first-x)+ab(cabs[j].second-y))==1){
					g.addEdge(cabs.size()-1,j);
				}
			}
		}
		cout << g.dfsAll() <<endl;
	}
	
	return 0;
}

