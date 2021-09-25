#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

#define INF 1000000
typedef pair<int,int> P;
int N,M;
vector<P> adj[1001];
priority_queue<P,vector<P>,greater<P> >pq;
int dist[1001];
int pre[1001];
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(P(c,b));
		adj[b].push_back(P(c,a));
	}
	for(int i=1;i<=N;i++)
		dist[i]=INF;
	dist[1]=0;
	pq.push(P(0,1));
	while(!pq.empty()){
		P top=pq.top();
		pq.pop();
		int here=top.second;
		int cost=top.first;
		for(P next:adj[here]){
			int there=next.second;
			int nextcost=cost+next.first;
			if(nextcost>dist[there]) continue;
			pre[there]=here;
			dist[there]=nextcost;
			pq.push(P(nextcost,there));
		}
	}
	cout<<N-1<<'\n';
	for(int i=2;i<=N;i++){
		cout<<i<<" "<<pre[i]<<'\n';
	}
	return 0;
}