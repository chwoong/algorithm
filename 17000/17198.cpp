#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int m[10][10];
int sx,sy;
int ex,ey;
bool visited[10][10];

int bfs(){
	visited[sx][sy]=true;
	queue<P> q;
	q.push(P(sx,sy));
	int cnt=-1;
	while(!q.empty()){
		cnt++;
		int len=q.size();
		while(len--){
			P here=q.front();
			q.pop();
			for(int k=0;k<4;k++){
				int a=here.first+dx[k];
				int b=here.second+dy[k];
				if(a>=0&&a<10&&b>=0&&b<10&&m[a][b]!='R'&&!visited[a][b]){
					visited[a][b]=true;
					q.push(P(a,b));
					if(a==ex && b==ey) return cnt;
				}
			}
		}
	}
}

int main(){
	for(int i=0;i<10;i++){
		string s;
		cin>>s;
		for(int j=0;j<10;j++){
			m[i][j]=s[j];
			if(m[i][j]=='B') {sx=i;sy=j;}
			else if(m[i][j]=='L') {ex=i;ey=j;}
		}
	}
	cout<<bfs();	
	return 0;
}