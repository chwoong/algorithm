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

#define INF 1000000
typedef pair<int,int> P;
vector<P> car;
vector<P> place;
vector<int> adj[100];
int a[250];
int b[250];
bool visited[250];
int m[50][150];

bool v[50][50];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int r,c;
int d[100][100];
//i번째 차와 연결되어있는 (주차장 번호,거리)
vector<P> con[150];

void bfs(int i,int j){
	memset(v,0,sizeof(v));
	int dist=0;
	v[i][j]=true;
	queue<P> q;
	q.push(P(i,j));
	while(!q.empty()){
		int x=q.size();
		for(int y=0;y<x;y++){
			P here=q.front();
			q.pop();
			int si=here.first;
			int sj=here.second;
			for(int k=0;k<4;k++){
				int ni=si+dx[k];
				int nj=sj+dy[k];
				if(ni>=0 && ni<r & nj>=0 && nj<c && !v[ni][nj] && m[ni][nj]!='X'){
					d[ni][nj]=dist+1;
					q.push(P(ni,nj));
					v[ni][nj]=true;
				}
			}
		}
		dist++;
	}
}

bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}


int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		string s;
		cin>>s;
		for(int j=0;j<c;j++){
			m[i][j]=s[j];
			if(s[j]=='C') car.push_back(P(i,j));
			else if(s[j]=='P') place.push_back(P(i,j));
		}
	}
	//car 각각과 place사이의 거리를 구하자.
	int len=car.size();
	for(int i=0;i<len;i++){
		memset(d,0,sizeof(d));
		bfs(car[i].first,car[i].second);
		int l=place.size();
		for(int j=0;j<l;j++){
			int val=d[place[j].first][place[j].second];
			if(val==0){
				con[i].push_back(P(100+j,INF));
			}else{
				con[i].push_back(P(100+j,val));
			}
		}
	}
	if(len==0){
		puts("0");
		return 0;
	}
	int l=0;
	int h=INF;
	while(l+1<h){
		int mid=(l+h)/2;
		int num=0;
		for(int i=0;i<len;i++){
			for(P ele:con[i]){
				if(ele.second<=mid){
					adj[i].push_back(ele.first);
				}
			}
		}
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		for(int i=0;i<len;i++){
			memset(visited,0,sizeof(visited));
			if(dfs(i)) num++;
		}
		//mid이하의 간선으로 구성해서 가능하면 
		if(num>=len) h=mid;
		else l=mid;
		for(int i=0;i<100;i++){
			adj[i].clear();
		}
	}
	if(h==INF) puts("-1");
	else printf("%d",h);
	return 0;
}