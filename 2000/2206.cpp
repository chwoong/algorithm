#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int> P;

int N,M;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

char map[1001][1001];
bool visited[1001][1001][2]={false,};
int bfs(){
	int depth=1;
	queue<pair<int,P> > q;
	q.push(make_pair(0,P(1,1)));
	visited[1][1][0]=true;
	if(1==N && 1==M) return 1;
	while(!q.empty()){
		int len=q.size();
		for(int j=0;j<len;j++){
		pair<int,P>x = q.front();
		q.pop();
		P here=x.second;
		int hx=here.first;
		int hy=here.second;
		/* 벽 부순 경험이 있음 */
		if(x.first==1){
			for(int i=0;i<4;i++){
				/*다음 위치*/
				int nx=hx+dx[i];
				int ny=hy+dy[i];
				if(nx>=1 && nx<=N && ny>=1 && ny<=M && !visited[nx][ny][1] && map[nx][ny]=='0'){
					q.push(make_pair(1,P(nx,ny)));
					visited[nx][ny][1]=true;
					if(nx==N && ny==M) return depth+1;
				}
			}
		}
		/* 벽 부순 경험이 없음 */
		else{
			for(int i=0;i<4;i++){
				/*다음 위치*/
				int nx=hx+dx[i];
				int ny=hy+dy[i];
				/*벽 안부숨*/
				if(nx>=1 && nx<=N && ny>=1 && ny<=M && !visited[nx][ny][0] && map[nx][ny]=='0'){
					q.push(make_pair(0,P(nx,ny)));
					visited[nx][ny][0]=true;
					if(nx==N && ny==M) return depth+1;
				}
				/*벽 부숨*/
				if(nx>=1 && nx<=N && ny>=1 && ny<=M && !visited[nx][ny][0] && map[nx][ny]=='1'){
					q.push(make_pair(1,P(nx,ny)));
					visited[nx][ny][1]=true;
				}
			}
		}
		}
		depth++;
	}
	return -1;
}

int main(){
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>&map[i][1];
	}
	cout<<bfs();
	return 0;
}