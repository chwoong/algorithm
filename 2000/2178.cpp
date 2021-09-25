#include<iostream>
#include<queue>
#include <vector>
#include<utility>

using namespace std;

int N,M;
char map[100][100];
int dis[100][100]={0,};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<pair<int,int>> q;
bool visited[100][100]={false,};

int bfs(){
	visited[0][0]=true;
	q.push(make_pair(0,0));
	dis[0][0]=1;
	while(!q.empty()){
		pair<int,int> here = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=here.first+dx[i];
			int ny=here.second+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&map[nx][ny]=='1'&&!visited[nx][ny]){
				visited[nx][ny]=true;
				dis[nx][ny] = dis[here.first][here.second]+1;
				q.push(make_pair(nx,ny));
			}
			if(nx==N-1 && ny== M-1) return dis[nx][ny];
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> map[i][j];
		}
	}
	cout << bfs();
	return 0;
}