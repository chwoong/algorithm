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

#define INF 1000000000000
struct Point{
	int x,y;
	long long d;
	Point(int a,int b,long long c):x(a),y(b),d(c){};
};
bool operator<(Point a,Point b) {return a.d>b.d;}

int n,t;
long long m[110][110];
int dx[16]={1,0,-1,0,0,1,2,3,2,1,0,-1,-2,-3,-2,-1};
int dy[16]={0,-1,0,1,3,2,1,0,-1,-2,-3,-2,-1,0,1,2};
vector<Point> adj[110][110];
long long dist[110][110];

int main(){
	cin>>n>>t;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lld",&m[i][j]);
			dist[i][j]=INF;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<16;k++){
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx>=0&&nx<n&&ny>=0&&ny<n) adj[i][j].push_back(Point(nx,ny,m[nx][ny]+(long long)3*t));
			}
		}
	}
	dist[0][0]=0;
	priority_queue<Point> pq;
	pq.push(Point(0,0,0));
	while(!pq.empty()){
		Point h=pq.top();
		long long cost=h.d;
		int x=h.x;
		int y=h.y;
		pq.pop();
		if(dist[x][y]<cost) continue;
		for(Point p:adj[x][y]){
			int nx=p.x;
			int ny=p.y;
			long long nextcost=p.d;
			if(dist[nx][ny]>cost+nextcost){
				dist[nx][ny]=cost+nextcost;
				pq.push(Point(nx,ny,dist[nx][ny]));
			}
		}
	}
	long long ans=INF;
	ans=min(ans,dist[n-1][n-1]);
	ans=min(ans,dist[n-2][n-1]+t);
	ans=min(ans,dist[n-3][n-1]+2*t);
	ans=min(ans,dist[n-2][n-2]+2*t);
	ans=min(ans,dist[n-1][n-2]+t);
	ans=min(ans,dist[n-1][n-3]+2*t);
	cout<<ans;
	return 0;
}