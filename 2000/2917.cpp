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
using namespace std;
 
int n,m;
char d[500][500];
int s,e;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[2500000];
queue<int> q;
void dfs(int i){
	visited[i]=true;
	int x=i/500;
	int y=i%500;
	if(d[x][y]=='+') return;
	for(int k=0;k<4;k++){
		int nx=x+dx[k];
		int ny=y+dy[k];
		if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx*500+ny] && d[nx][ny]!='+'){
			dfs(nx*500+ny);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string sx;
		cin>>sx;
		for(int j=0;j<m;j++){
			d[i][j]=sx[j];
			if(d[i][j]=='V') s=i*500+j;
			else if(d[i][j]=='J') e=i*500+j;
			else if(d[i][j]=='+') {q.push(i*500+j);}
		}
	}
	for(int i=0;i<=1000;i++){
		//�� �����κ��� iĭ �� ������ ������ �� �׿����� ���� �ʰ� ���θ����� �� �� �ִ��� Ȯ��
		//���� iĭ ������ �����µ� ������ �� ������ ��� �ȴٸ� i�� ���̴�. break
		memset(visited,false,sizeof(visited));
		if(i==0){
			dfs(s);
			if(visited[e]) continue;
			else {puts("0"); break;}
		}else{
			//���� ������
			int len=q.size();
			for(int j=0;j<len;j++){
				int here=q.front();
				q.pop();
				int x=here/500;
				int y=here%500;
				for(int k=0;k<4;k++){
					int nx=x+dx[k];
					int ny=y+dy[k];
					if(nx>=0 && nx<n && ny>=0 && ny<m && d[nx][ny]!='+'){
						d[nx][ny]='+';
						q.push(nx*500+ny);
					}
					
				}
			}
			//Ž��
			dfs(s);
			if(visited[e]) continue;
			else {printf("%d",i); break;}
		}
	}
	
	return 0;
}