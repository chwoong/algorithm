#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

#define INF 1000000000
struct info{
	int c;
	int d;
	int f;
};
struct P{
	int d;
	int i;
	int m;
};
bool operator<(P a,P b){
	return a.d>b.d;
}
int T,N,M,K;
//1번 점에서 i점 까지 갔는데 j원썼을 때 최소 시간
int dist[101][10001];
int main(){
	cin>>T;
	while(T--){
		vector<info> adj[101];
		priority_queue<P> pq;
		scanf("%d %d %d",&N,&M,&K);
		for(int i=0;i<K;i++){
			int u,v,c,d;
			scanf("%d %d %d %d",&u,&v,&c,&d);
			info x={c,d,v};
			adj[u].push_back(x);
		}
		for(int i=1;i<=N;i++)
			for(int j=0;j<=M;j++)
				dist[i][j]=INF;
		dist[1][M]=0;
		P x={0,1,0};
		pq.push(x);
		while(!pq.empty()){
			P top=pq.top();
			pq.pop();
			int cost=top.d;
			int money=top.m;
			int here=top.i;
			if(cost>dist[here][money]) continue;
			for(info x:adj[here]){
				int there=x.f;
				int nextcost=x.d+cost;
				int usemoney=money+x.c;
				if(usemoney>M) continue;
				if(nextcost<dist[there][usemoney]){
					dist[there][usemoney]=nextcost;
					P a={nextcost,there,usemoney};
					pq.push(a);
				}
			}
		}
		int ans=INF;
		for(int i=0;i<=M;i++)
			ans=min(ans,dist[N][i]);
		if(ans==INF) printf("Poor KCM\n");
		else printf("%d\n",ans);
	}
	return 0;
}