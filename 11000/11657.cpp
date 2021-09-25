/*
 *  author: chw0501
 *  reference:https://m.blog.naver.com/kks227/220796963742
 *  created: 26.04.2020 06:23:59(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define MOD 1000000007
#define INF 1000000000000

int n,m;
vector<P> adj[501];
vector<ll> dist;

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);
		adj[a].push_back(P(c,b));
	}
	dist.assign(n+1,INF);
	dist[1]=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			for(P p:adj[j]){
				int next=p.second;
				ll d=p.first;
				if(dist[j]!=INF && dist[next]>dist[j]+d){
					dist[next]=dist[j]+d;
					if(i==n-1){
						puts("-1");
						return 0;
					}
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		printf("%lld\n",dist[i]!=INF?dist[i]:-1ll);
	}
	return 0;
}