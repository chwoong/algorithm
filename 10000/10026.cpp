#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char map[100][100];
bool visited[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/* 정상 */
void dfs1(int i,int j){
	visited[i][j]=true;
	for(int t=0;t<4;t++){
		int nx=i+dx[t];
		int ny=j+dy[t];
		if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && map[i][j]==map[nx][ny])
			dfs1(nx,ny);
	}
}

/* 적룍색약 */
void dfs2(int i,int j){
	visited[i][j]=true;
	for(int t=0;t<4;t++){
		int nx=i+dx[t];
		int ny=j+dy[t];
		if(nx>=0 && nx<N && ny>=0 && ny<N && !visited[nx][ny] && map[i][j]==map[nx][ny])
			dfs2(nx,ny);
	}
}


int main(){
	cin >> N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> map[i][j];
	

	int m1(0),m2(0);
	
	fill(&visited[0][0],&visited[0][0]+sizeof(visited)/sizeof(bool),false);
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j]) {dfs1(i,j); m1++;}
				
	
	fill(&visited[0][0],&visited[0][0]+sizeof(visited)/sizeof(bool),false);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(map[i][j] == 'R') map[i][j]= 'G';
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(!visited[i][j]) {dfs2(i,j); m2++;}
	
	
	cout << m1 <<" "<<m2;
	
	return 0;
}
