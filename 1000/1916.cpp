#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

#define INF 1000000000
typedef pair<int,int> P;
int N,M;
//출발점, 도착점
int s,e;
vector<P> adj[1001];
int dist[1001];
priority_queue<P,vector<P>,greater<P> > pq;
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(P(b,c));
	}
	cin>>s>>e;
	for(int i=1;i<=N;i++)
		dist[i]=INF;
	dist[s]=0;
	pq.push(P(0,s));
	while(!pq.empty()){
		P curr=pq.top();
		pq.pop();
		int here=curr.second;
		int cost=curr.first;
		//이미 다익스트라로 해결된 점이다.
		if(dist[here]<cost) continue;
		for(P ele:adj[here]){
			int there=ele.first;
			int nextdist=cost+ele.second;
			if(nextdist<dist[there]){
				dist[there]=nextdist;
				pq.push(P(nextdist,there));
			}
		}
	}
	cout<<dist[e];
	return 0;
}