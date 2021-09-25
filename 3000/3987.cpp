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
using namespace std;

#define U 0
#define R 1
#define D 2
#define L 3
#define INF 1000000

int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
char na[4]={'U','R','D','L'};
int n,m,x,y;
char map[500][500];
bool visited[500][500][4];

int solve(int i,int j,int d){
	//cout<<i<<' '<<j<<' '<<d<<endl;
	if(i<0 || i>=n || j<0 || j>=m || map[i][j]=='C') return 0;
	if(visited[i][j][d]) return INF;
	visited[i][j][d]=true;
	if(d==U && map[i][j]=='\\') return 1+solve(i,j-1,L);
	else if(d==U && map[i][j]=='/') return 1+solve(i,j+1,R);
	
	else if(d==R && map[i][j]=='\\') return 1+solve(i+1,j,D);
	else if(d==R && map[i][j]=='/') return 1+solve(i-1,j,U);
	
	else if(d==D && map[i][j]=='\\') return 1+solve(i,j+1,R);
	else if(d==D && map[i][j]=='/') return 1+solve(i,j-1,L);
	
	else if(d==L && map[i][j]=='\\') return 1+solve(i-1,j,U);
	else if(d==L && map[i][j]=='/') return 1+solve(i+1,j,D);
	
	else return 1+solve(i+dy[d],j+dx[d],d);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			map[i][j]=s[j];
		}
	}
	cin>>x>>y;
	int m(0),c;
	for(int i=0;i<4;i++){
		memset(visited,false,sizeof(visited));
		int val=solve(x-1,y-1,i);
		//cout<<i<<' '<<val<<endl;
		if(m<val) {m=val; c=i;}
		if(m>=INF) break; 
		//cout<<endl;
	}
	cout<<na[c]<<endl;
	if(m>=INF) cout<<"Voyager";
	else cout<<m;
	return 0;
}