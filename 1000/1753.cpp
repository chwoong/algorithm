#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

#define INF 100000000
typedef pair<int,int> P;
vector<P> adj[20001];
priority_queue<P,vector<P>,greater<P>> pq;
vector<int> dist(20001,INF);

int main(){
	int V,E,K;
	cin>> V>> E>>K;
	for(int i=0;i<E;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(P(v,w));
	}
	dist[K]=0;
	pq.push(P(0,K));
	while(!pq.empty()){
		int cost=pq.top().first;
		int here=pq.top().second;
		pq.pop();
		/* 지금 방문한 here에 더 짧은 경로가 저장되어 있으면 무시, 나중에 다시 방문할 거임 */
		if(dist[here]<cost) continue;
		for(P next: adj[here]){
			int there=next.first;
			int nextdist=cost+next.second;
			if(nextdist<dist[there]){
				dist[there]= nextdist;
				pq.push(P(nextdist,there));
			}
		}
	}
	for(int i=1;i<=V;i++){
		if(dist[i]==INF) printf("INF\n");
		else printf("%d\n",dist[i]);
	}
	
	return 0;
}