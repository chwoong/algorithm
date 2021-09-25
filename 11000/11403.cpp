#include <iostream>
#include <algorithm>
using namespace std;

int N;
int adj[100][100];
bool visited[100];


void dfs(int i){
	for(int j=0;j<N;j++){
		if(adj[i][j]==1 && !visited[j]) {visited[j]=true;dfs(j);}
	}
}


int main(){
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> adj[i][j];
	
	for(int i=0;i<N;i++){
		fill(&visited[0],&visited[0]+100,false);
		dfs(i);
		for(int j=0;j<N;j++)
			cout << visited[j]<< " ";
		cout << endl;
	}
	
	return 0;
}
