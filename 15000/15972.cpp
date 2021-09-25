#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int N,M,H;
//각 칸의 물 높이 저장
int map[1000][1000];
bool visited[1000][1000];
//각 방의 왼쪽 및 위쪽의 구멍 정보 저장
int lef[1001][1001];
int up[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
priority_queue<tuple<int,int,int>>pq;
void flood_fill(int under,int i,int j){
	visited[i][j]=true;
	if(map[i][j]<under) return;
	map[i][j]=under;
	int val;
	for(int k=0;k<4;k++){
		int ni=i+dx[k];
		int nj=j+dy[k];
		if(ni<0 || ni>=N || nj<0 || nj>=M) continue;
		if(visited[ni][nj]) continue;
		if(k==0 && i!=N-1 && up[ni][nj]!=-1){
			val=max(under,up[ni][nj]);
			flood_fill(val,ni,nj);
		}else if(k==2 && i!=0 && up[i][j]!=-1){
			val=max(under,up[i][j]);
			flood_fill(val,ni,nj);
		}else if(k==3 && j!=0 && lef[i][j]!=-1){
			val=max(under,lef[i][j]);
			flood_fill(val,ni,nj);
		}else if(k==1 && j!=M-1 && lef[ni][nj]!=-1){
			val=max(under,lef[ni][nj]);
			flood_fill(val,ni,nj);
		}
	}
}

int main(){
	cin>>N>>M>>H;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			map[i][j]=H;
	//구멍 정보 저장
	for(int i=0;i<=N;i++){
		for(int j=0;j<M;j++){
			int x;
			scanf("%d",&x);
			if(i==0 && x!=-1){
				map[0][j]=min(map[0][j],x);
				pq.push(make_tuple(-x,0,j));
			}
			if(i==N && x!=-1){
				map[N-1][j]=min(map[N-1][j],x);
				pq.push(make_tuple(-x,N-1,j));
			}
			else up[i][j]=x;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<=M;j++){
			int x;
			scanf("%d",&x);
			if(j==0 && x!=-1){
				map[i][j]=min(map[i][j],x);
				pq.push(make_tuple(-x,i,j));
			}
			if(j==M && x!=-1){
				map[i][M-1]=min(map[i][M-1],x);
				pq.push(make_tuple(-x,i,M-1));
			}
			else lef[i][j]=x;
		}
	}
	while(!pq.empty()){
		memset(visited,0,sizeof(visited));
		tuple<int,int,int> t=pq.top();
		pq.pop();
		flood_fill(-get<0>(t),get<1>(t),get<2>(t));
	}
	int vol=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			vol+=map[i][j];
	cout<<vol;
	return 0;
}