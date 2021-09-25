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
using namespace std;

int n,k;
int m[100][10];
bool visited[100][10];
bool visdfs[100][10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

//숫자를 아래로 끌어내림
void down(){
	for(int j=0;j<10;j++){
		queue<int> q;
		for(int i=n-1;i>=0;i--){
			if(m[i][j]!='0') q.push(m[i][j]);
		}
		for(int i=n-1;i>=0;i--){
			if(q.empty()){m[i][j]='0';continue;}
			m[i][j]=q.front();
			q.pop();
		}
	}
}
int dfs(int i,int j,int tmp){
	visdfs[i][j]=true;
	int a=0;
	for(int p=0;p<4;p++){
		int nx=i+dx[p];
		int ny=j+dy[p];
		if(nx>=0 && nx<n && ny>=0 && ny<10 && !visdfs[nx][ny] && m[nx][ny]==tmp){
			a+=dfs(nx,ny,tmp);
		}
	}
	return 1+a;
}
void color(int i,int j,int tmp){
	visited[i][j]=true;
	m[i][j]='0';
	for(int p=0;p<4;p++){
		int nx=i+dx[p];
		int ny=j+dy[p];
		if(nx>=0 && nx<n && ny>=0 && ny<10 && !visited[nx][ny] && m[nx][ny]==tmp){
			color(nx,ny,tmp);
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<10;j++){
			m[i][j]=(int)s[j];
		}
	}
	down();
	while(1){
		bool pos=false;
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			for(int j=0;j<10;j++){
				//만약 m[i][j]를 포함한 구간의 면적이 k이상이면...
				if(m[i][j]=='0') visited[i][j]=true;
				else if(!visited[i][j]){
					memset(visdfs,false,sizeof(visdfs));
					int size=dfs(i,j,m[i][j]);
					if(size>=k) {
						pos=true;
						color(i,j,m[i][j]);
					}
				}
			}
		}
		if(pos) down();
		if(!pos) break;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<10;j++){
			printf("%c",m[i][j]);
		}
		printf("\n");
	}
	return 0;
}