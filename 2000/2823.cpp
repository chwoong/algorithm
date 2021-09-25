#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int,int> P;
vector <P> adj[10][10];
int R,C;
char map[10][10];
int sx,sy,ans;
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
bool visited[10][10];

void dfs(P here,int dir){
	int hx=here.first;
	int hy=here.second;
	visited[hx][hy]=true;
	int tmp=0;
	for(int k=0;k<4;k++){
		if(k!=3-dir){
			int nx=hx+dx[k];
			int ny=hy+dy[k];
			if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
			if(map[nx][ny]=='.'){
				tmp++;
				if(visited[nx][ny]==false) dfs(P(nx,ny),k);
			}
		}
	}
	//막다른 길이 있으면
	if(tmp==0) ans=1;
}

int main(){
	cin>>R>>C;
	int cnt=0;
	for(int i=0;i<R;i++){
		char s[20];
		scanf("%s",s);
		for(int j=0;j<C;j++){
			map[i][j]=s[j];
			if(map[i][j]=='.'){cnt++;sx=i;sy=j;}
		}
	}
	if(cnt==1) {cout<<1; return 0;}
	for(int k=0;k<4;k++){
		int nx=sx+dx[k];
		int ny=sy+dy[k];
		if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
		if(map[nx][ny]=='X'||visited[nx][ny]) continue;
		dfs(P(nx,ny),k);
	}
	cout<<ans;
	return 0;
}