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

#define INF 2000000000
typedef pair<int,int> P;

int n,m,k;
vector<int> adj[50010];
//나중에 road값을 편하게 수정하기 위해 간선 정보를 map으로 저장
map<P,int> road;
int dist[50010];
int basic[50010];
int p[50010];
int y[50010];
priority_queue<P,vector<P>,greater<P> > pq;
void dijk(int s){
	pq.push(P(0,s));
	dist[s]=0;
	while(!pq.empty()){
		P t=pq.top();
		pq.pop();
		int here=t.second;
		int cost=t.first;
		if(dist[here]<cost) continue;
		for(int next:adj[here]){
			if(road[P(here,next)]+cost<dist[next]){
				dist[next]=road[P(here,next)]+cost;
				pq.push(P(dist[next],next));
			}
		}
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,t;
		scanf("%d %d %d",&a,&b,&t);
		adj[a].push_back(b);
		adj[b].push_back(a);
		road[P(a,b)]=t;
		road[P(b,a)]=t;
	}
	for(int i=0;i<k;i++){
		scanf("%d %d",p+i,y+i);
	}
	for(int i=1;i<=n;i++){
		dist[i]=INF;
	}
	dijk(n);
	//새로운 간선 추가(n+1노드에서나가는)
	//n+1에서 yummy가 있는 pasture(i)로 가는 간선 값=(n에서 i로 가는 최단거리)-(yumminess)
	//그러면 yummy를 최대 한번만 이용한다.
	for(int i=0;i<k;i++){
		adj[n+1].push_back(p[i]);
		road[P(n+1,p[i])]=dist[p[i]]-y[i];
	}
	for(int i=1;i<=n+1;i++){
		basic[i]=dist[i];
		dist[i]=INF;
	}
	dijk(n+1);
	for(int i=1;i<n;i++){
		if(dist[i]<=basic[i]) puts("1");
		else puts("0");
	}
	return 0;
}