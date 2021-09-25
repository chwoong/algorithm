#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 1000000
typedef pair<int,int> P;
struct point{
	int cost;
	P p;
	point(int a,P b):cost(a),p(b){}
};
struct cmp{
	bool operator()(point a,point b){
		return a.cost>b.cost;
	}
};
int n;
int m[125][125];
int dist[125][125];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	int t=1;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				scanf("%d",&m[i][j]);
				dist[i][j]=INF;
			}
		priority_queue<point,vector<point>,cmp > pq;
		dist[0][0]=m[0][0];
		pq.push(point(m[0][0],P(0,0)));
		while(!pq.empty()){
			point curr=pq.top();
			P p=curr.p;
			int cost=curr.cost;
			pq.pop();
			if(dist[p.first][p.second]<cost) continue;
			for(int k=0;k<4;k++){
				int nx=p.first+dx[k];
				int ny=p.second+dy[k];
				if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
				int nextcost=cost+m[nx][ny];
				if(dist[nx][ny]>nextcost){
					dist[nx][ny]=nextcost;
					pq.push(point(nextcost,P(nx,ny)));
				}
			}
		}
		printf("Problem %d: %d\n",t++,dist[n-1][n-1]);
	}
	return 0;
}