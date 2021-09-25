#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

#define INF 1000000000000
typedef pair<long long,int> C;
typedef pair<long long,C > P;
int N,M,K;
vector<C> adj[10001];
//정점 (i,j)까지 거리: 정점 1부터의 i까지의 거리, 단 포장도로 j개 사용
long long dist[10001][21];
priority_queue<P,vector<P>,greater<P> > pq;
int main(){
	cin>>N>>M>>K;
	for(int i=0;i<M;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(C(c,b));
		adj[b].push_back(C(c,a));
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<=K;j++){
			if(i==1) dist[i][j]=0;
			else dist[i][j]=INF;
		}
	}
	pq.push(P(0,C(1,0)));
	while(!pq.empty()){
		P top=pq.top();
		pq.pop();
		long long cost=top.first;
		C x=top.second;
		//현재 조사하는 정점까지 사용된 포장 도로 개수
		int here=x.first;
		int num=x.second;
		if(cost>dist[here][num]) continue;
		for(C next:adj[here]){
			int there=next.second;
			long long nextcost=cost+next.first;
			//도로 포장 안하는 경우
			if(nextcost<dist[there][num]){
				dist[there][num]=nextcost;
				pq.push(P(nextcost,C(there,num)));
			}
			//도로 포장 하는 경우
			if(num<K && cost<dist[there][num+1]){
				dist[there][num+1]=cost;
				pq.push(P(cost,C(there,num+1)));
			}
		}
	}
	long long ans=dist[N][0];
	for(int i=1;i<=K;i++){
		ans=min(ans,dist[N][i]);
	}
	cout<<ans;
	return 0;
}