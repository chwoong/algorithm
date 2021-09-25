#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int n;
char m[20][20];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool visited[20][20][20][20][4][2][2];
int ans=0;

struct state{
	int x1,y1,x2,y2,dir,s1,s2;
};
int main(){
	cin>>n;
	for(int i=n-1;i>=0;i--){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			m[i][j]=s[j];
		}
	}
	queue<state> q;
	q.push((state){0,0,0,0,1,0,0});
	visited[0][0][0][0][1][0][0]=true;
	while(!q.empty()){
		int len=q.size();
		for(int i=0;i<len;i++){
			state h=q.front();
			q.pop();
			//확인
			int a1=(h.s1 || (h.x1==n-1 && h.y1==n-1));
			int a2=(h.s2 || (h.x2==n-1 && h.y2==n-1));
			if(a1 && a2){
				printf("%d",ans); return 0;
			}
			//옮기기
			//dir바꾸기
			if(!visited[h.x1][h.y1][h.x2][h.y2][(h.dir+1)%4][a1][a2]){
				q.push((state){h.x1,h.y1,h.x2,h.y2,(h.dir+1)%4,a1,a2});
				visited[h.x1][h.y1][h.x2][h.y2][(h.dir+1)%4][a1][a2]=true;
			}
			if(!visited[h.x1][h.y1][h.x2][h.y2][(h.dir+3)%4][a1][a2]){
				q.push((state){h.x1,h.y1,h.x2,h.y2,(h.dir+3)%4,a1,a2});
				visited[h.x1][h.y1][h.x2][h.y2][(h.dir+3)%4][a1][a2]=true;
			}
			//dir방향으로 위치 옮기기
			int nx1=h.x1+dx[h.dir];
			nx1=max(0,nx1);
			nx1=min(nx1,n-1);
			int ny1=h.y1+dy[h.dir];
			ny1=max(0,ny1);
			ny1=min(ny1,n-1);
			int nx2=h.x2+dx[(h.dir+1)%4];
			nx2=max(0,nx2);
			nx2=min(nx2,n-1);
			int ny2=h.y2+dy[(h.dir+1)%4];
			ny2=max(0,ny2);
			ny2=min(ny2,n-1);
			if(m[nx1][ny1]=='H') {nx1=h.x1; ny1=h.y1;}
			if(m[nx2][ny2]=='H') {nx2=h.x2; ny2=h.y2;}
			if(!visited[nx1][ny1][nx2][ny2][h.dir][a1][a2]){
				q.push((state){nx1,ny1,nx2,ny2,h.dir,a1,a2});
				visited[nx1][ny1][nx2][ny2][h.dir][a1][a2]=true;
			}
		}
		ans++;
	}
	return 0;
}