#include <iostream>
#include <algorithm>

using namespace std;

int N;
int height[100][100];
bool visited[100][100];

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int safe=1;
int rain=1;

void dfs(int i,int j){
	visited[i][j]=true;
	for(int k=0;k<4;k++){
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && height[nx][ny]>rain)
			dfs(nx,ny);
	}
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> height[i][j];	
		}
	}
	for(;rain<101;rain++){
		int components=0;
		fill(&visited[0][0],&visited[0][0]+sizeof(visited)/sizeof(bool),false);
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(!visited[i][j] && height[i][j] > rain) {dfs(i,j);components++;}
			}
		}
		safe = max(components,safe);
	}
	
	cout << safe;
	
	return 0;
}