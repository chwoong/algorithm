#include<iostream>
#include<queue>
#include <vector>
#include<utility>
#include<algorithm>

using namespace std;

int l;
int sx,sy;
int fx,fy;
char map[300][300];
int dis[300][300];

int dx[8]={1,2, 2, 1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1, 1, 2};

bool visited[300][300]={false,};

int bfs(){
	queue<pair<int,int>> q;
	visited[sx][sy]=true;
	q.push(make_pair(sx,sy));
	dis[sx][sy]=0;
	while(!q.empty()){
		pair<int,int> here = q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int nx=here.first+dx[i];
			int ny=here.second+dy[i];
			if(nx>=0&&nx<l&&ny>=0&&ny<l&&!visited[nx][ny]){
				visited[nx][ny]=true;
				dis[nx][ny] = dis[here.first][here.second]+1;
				q.push(make_pair(nx,ny));
			}
			if(nx==fx && ny== fy) return dis[nx][ny];
		}
	}
	return 0;
}

int main(){
	int test;
	cin >> test;
	for(int i=0;i<test;i++){
		cin >>l >> sx >> sy>> fx>>fy;
		fill(&dis[0][0],&dis[0][0]+sizeof(dis)/sizeof(int),0);
		fill(&visited[0][0],&visited[0][0]+sizeof(visited)/sizeof(bool),false);
		cout << bfs()<<endl;
	}
	return 0;
}