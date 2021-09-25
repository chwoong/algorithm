#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define INF 1000000000
typedef pair<int,int> P;
int N,E;
//꼭 지나야하는 두 점
int x,y;
vector<P> adj[1000];
int dist[3][1000];
int main(){
	cin>>N>>E;
	for(int i=0;i<E;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(P(b,c));
		adj[b].push_back(P(a,c));
	}
	cin>>x>>y;
	for(int i=1;i<=N;i++){
		dist[0][i]=dist[1][i]=dist[2][i]=INF;
	}
	dist[0][1]=0;
	dist[1][x]=0;
	dist[2][y]=0;
	for(int i=0;i<3;i++){
		priority_queue<P,vector<P>,greater<P> > pq;
		if(i==0) pq.push(P(0,1));
		else if(i==1) pq.push(P(0,x));
		else pq.push(P(0,y));
		while(!pq.empty()){
			P curr=pq.top();
			pq.pop();
			int here=curr.second;
			int cost=curr.first;
			//이미 다익스트라로 해결된 점이다.
			if(dist[i][here]<cost) continue;
			for(P ele:adj[here]){
				int there=ele.first;
				int nextdist=cost+ele.second;
				if(nextdist<dist[i][there]){
					dist[i][there]=nextdist;
					pq.push(P(nextdist,there));
				}
			}
		}
	}
	int ans1=-1,ans2=-1;
	if(dist[0][x]!=INF && dist[1][y]!=INF && dist[2][N]!=INF) ans1=dist[0][x]+dist[1][y]+dist[2][N];
	if(dist[0][y]!=INF && dist[2][x]!=INF && dist[1][N]!=INF) ans2=dist[0][y]+dist[1][N]+dist[2][x];
	if(ans1!=-1 && ans2!=-1) cout<<min(ans1,ans2);
	else if(ans1==-1 && ans2==-1) cout<<-1;
	else cout<<max(ans1,ans2);
	return 0;
}