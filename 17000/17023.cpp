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

#define INF 1000000000
typedef pair<int,int> P;
int n,m,t;
int cow[10001];
long long num[10001];
//(도착점,시간)
vector<P> adj[10001];
priority_queue<P,vector<P>,greater<P> >pq;
//dist[i]: i->1까지 걸리는 최단시간
int dist[10001];
//최단 경로상의 부모 정점
int p[10001];

int indegree[10001];

int main(){
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		scanf("%d",cow+i);
		num[i]=cow[i];
	}
	for(int i=0;i<m;i++){
		int a,b,ti;
		scanf("%d %d %d",&a,&b,&ti);
		adj[a].push_back(P(b,ti));
		adj[b].push_back(P(a,ti));
	}
	//다익스트라
	pq.push(P(0,1));
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	dist[1]=0;
	while(!pq.empty()){
		P t=pq.top();
		pq.pop();
		int here=t.second;
		int cost=t.first;
		if(dist[here]<cost) continue;
		for(P next:adj[here]){
			int there=next.first;
			int nextcost=cost+next.second;
			if(dist[there]>nextcost){
				dist[there]=nextcost;
				pq.push(P(nextcost,there));
			}
		}
	}
	for(int i=1;i<=n;i++)
		p[i]=100000;
	p[1]=1;
	for(int i=n;i>=2;i--){
		for(P ele:adj[i]){
			int there=ele.first;
			int d=ele.second;
			if(dist[there]+d==dist[i]){
				p[i]=min(p[i],there);
			}
		}
	}
	long long ans=0;
	queue<int> q;
	for(int i=1;i<=n;i++){
		indegree[p[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ans=max(ans,(long long)(dist[x]-t)*num[x]);
		num[p[x]]+=num[x];
		if(--indegree[p[x]] ==0) q.push(p[x]);
	}
	cout<<ans;
	return 0;
}