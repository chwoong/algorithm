#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

#define INF 1000000000000
typedef pair<long long,long long> P;
long long N,M,D,E;
vector<P> adj[100001];
priority_queue<P,vector<P>,greater<P> >pq1,pqn;
long long h[100001];
long long dist1[100001];
long long distn[100001];
int main(){
	cin>>N>>M>>D>>E;
	if(N==2) {cout<<"Impossible";return 0;}
	for(int i=1;i<=N;i++)
		scanf("%lld",h+i);
	for(int i=0;i<M;i++){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(h[a]<h[b]) adj[a].push_back(P(c,b));
		if(h[b]<h[a]) adj[b].push_back(P(c,a));
	}
	for(int i=1;i<=N;i++){
		dist1[i]=INF;
		distn[i]=INF;
	}
	dist1[1]=0;
	distn[N]=0;
	pq1.push(P(0,1));
	pqn.push(P(0,N));
	while(!pq1.empty()){
		P top=pq1.top();
		pq1.pop();
		int here=top.second;
		long long cost=top.first;
		if(cost>dist1[here]) continue;
		for(P next:adj[here]){
			int there=next.second;
			long long nextcost=next.first+cost;
			if(nextcost>=dist1[there]) continue;
			dist1[there]=nextcost;
			pq1.push(P(nextcost,there));
		}
	}
	while(!pqn.empty()){
		P top=pqn.top();
		pqn.pop();
		int here=top.second;
		long long cost=top.first;
		if(cost>distn[here]) continue;
		for(P next:adj[here]){
			int there=next.second;
			long long nextcost=next.first+cost;
			if(nextcost>=distn[there]) continue;
			distn[there]=nextcost;
			pqn.push(P(nextcost,there));
		}
	}
	int tmp=0;
	long long ans=-INF;
	for(int i=2;i<=N-1;i++){
		if(dist1[i]!=INF &&distn[i]!=INF && h[i]>1){
			tmp=1;
			ans=max(ans,-D*(dist1[i]+distn[i])+E*h[i]);
		}
	}
	if(tmp) cout<<ans;
	else cout<<"Impossible";
	return 0;
}