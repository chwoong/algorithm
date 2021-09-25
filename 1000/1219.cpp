#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

#define INF 1000000000000
typedef pair<int,long long> P;

int N,s,e,M;
//(도시,교통수단 가격)
vector<P> adj[101];
vector<int> inv[101];
bool ispos[101];
int sal[101];
long long dist[101];
int main(){
	cin>>N>>s>>e>>M;
	while(M--){
		int a,b;
		long long c;
		scanf("%d %d %lld",&a,&b,&c);
		adj[a].push_back(P(b,c));
		inv[b].push_back(a);
	}
	for(int i=0;i<N;i++){
		scanf("%d",sal+i);
	}
	for(int i=0;i<N;i++){
		dist[i]=-(long long)INF;
	}
	dist[s]=sal[s];
	//각 점에서 e로 갈 수 있는 지를 확인하자.
	queue<int> q;
	q.push(e);
	while(!q.empty()){
		int here=q.front();
		q.pop();
		ispos[here]=true;
		for(int there:inv[here]){
			if(!ispos[there]) q.push(there);
		}
	}
	if(ispos[s]==false){
		puts("gg");
		return 0;
	}
	//완화 N번 시행
	for(int i=0;i<N;i++){
		for(int here=0;here<N;here++){
			for(P next:adj[here]){
				int there=next.first;
				long long cost=next.second;
				if(dist[here]!=-INF && dist[there]<dist[here]-cost+sal[there]){
					dist[there]=dist[here]-cost+sal[there];
					if(i==N-1){
						if(ispos[here]){
							puts("Gee");
							return 0;
						}
					}
				}
			}
		}
	}
	cout<<dist[e];
	return 0;
}