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

#define INF 10000000

typedef pair<int,long long> P;
int n,m;
long long cost[2501];
vector<P> adj[2501];
long long dist[2501][2501];
long long ans[2501];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",cost+i);
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(P(b,c));
		adj[b].push_back(P(a,c));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=INF;
		}
	}
	//각 점(i)에서 다익스트라
	for(int i=1;i<=n-1;i++){
		priority_queue<P,vector<P>,greater<P> > pq;
		dist[i][i]=0;
		pq.push(P(0,i));
		while(!pq.empty()){
			P h=pq.top();
			pq.pop();
			int here=h.second;
			long long c=h.first;
			if(dist[i][here]<c) continue;
			for(P next:adj[here]){
				int there=next.first;
				long long nextcost=cost[i]*next.second;
				if(c+nextcost<dist[i][there]){
					dist[i][there]=c+nextcost;
					pq.push(P(dist[i][there],there));
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans[i]=INF;
	//이제 1번 도시에서 dist로 다익스트라
	ans[1]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,1));
	while(!q.empty()){
		P h=q.top();
		q.pop();
		int here=h.second;
		long long c=h.first;
		if(ans[here]<c) continue;
		for(int j=1;j<=n;j++){
			if(here!=j){
				if(c+dist[here][j]<ans[j]){
					ans[j]=c+dist[here][j];
					q.push(P(ans[j],j));
				}
			}
		}
	}
	cout<<ans[n];
	return 0;	
}