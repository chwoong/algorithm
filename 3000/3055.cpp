#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;

typedef pair<int,int> P;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c;
char map[51][51];
bool w_visited[51][51]={0,};
bool p_visited[51][51]={0,};

P start,finish;
queue<P> water,player;

int bfs(){
	player.push(start);
	p_visited[start.first][start.second]=true;
	int depth=0;
	while(1){
		/*물먼저 확장*/
		int len=water.size();
		while(len--){
			P here=water.front();
			water.pop();
			int hx=here.first;
			int hy=here.second;
			for(int k=0;k<4;k++){
				int nx=hx+dx[k];
				int ny=hy+dy[k];
				if(nx>=0&&nx<r&&ny>=0&&ny<c && !w_visited[nx][ny] && map[nx][ny]!='D'&& map[nx][ny]!='X'){
					map[nx][ny]='*';
					w_visited[nx][ny]=true;
					water.push(P(nx,ny));
				}
			}
		}
		/*고슴도치 확장*/
		len=player.size();
		/*이번에 추가되는 고슴도치 위치*/
		int add=0;
		while(len--){
			P here=player.front();
			player.pop();
			int hx=here.first;
			int hy=here.second;
			for(int k=0;k<4;k++){
				int nx=hx+dx[k];
				int ny=hy+dy[k];
				if(nx>=0&&nx<r&&ny>=0&&ny<c && !p_visited[nx][ny] && map[nx][ny]!='*'&& map[nx][ny]!='X'){
					if(map[nx][ny]=='D') return depth+1;
					p_visited[nx][ny]=true;
					player.push(P(nx,ny));
					add++;
				}
			}
		}
		/*고슴도치 못움직임 */
		if(add==0) return -1;
		depth++;
	}
}

int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		cin>>map[i];
		for(int j=0;j<c;j++){
			if(map[i][j]=='S') start=P(i,j);
			if(map[i][j]=='D') finish=P(i,j);
			if(map[i][j]=='*') {water.push(P(i,j)); w_visited[i][j]=true;}
		}
	}
	int ret=bfs();
	ret==-1?cout<<"KAKTUS":cout<<ret;
	return 0;
}