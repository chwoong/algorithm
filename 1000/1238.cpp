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
vector<P> adj[1001];
priority_queue<P,vector<P>,greater<P>> pq;
vector<int> dist_xtoi(1001,INF);
/* i마을에서 x마을까지 가는 거리 계산시 이용하는 다익스트라에 필요한 vector */
vector<int> dist_itox(1001,INF);
/* i마을에서 x마을까지 가는 거리 저장 */
vector<int> dist_i(1001);

int main(){
	int n,m,x;
	cin>>n>>m>>x;
	int u,v,w;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(P(v,w));
	}
	
	// 첫번째 다익스트라 
	// X에서 각각의 마을로 가는데의 최단거리 계산
	dist_xtoi[x]=0;
	pq.push(P(0,x));
	while(!pq.empty()){
		int cost=pq.top().first;
		int here=pq.top().second;
		pq.pop();
		// 더 짧은 경로가 저장되어있으면 현재 탐색은 무시하고 다음에 다시 하자 
		if(dist_xtoi[here]<cost) continue;
		// 인접 마을 탐색
		for(int i=0;i<adj[here].size();i++){
			int there=adj[here][i].first;
			int nextdist=adj[here][i].second+cost;
			if(nextdist<dist_xtoi[there]){
				dist_xtoi[there]=nextdist;
				pq.push(P(nextdist,there));
			}
		}
	}
	
	
	// 두번째 다익스트라 
	// 각각의 마을에서 x로 가는데의 최단거리 계산 
	for(int i=1;i<=n;i++){
		priority_queue<P,vector<P>,greater<P>> pq1;
		dist_itox[i]=0;
		pq1.push(P(0,i));
		while(!pq1.empty()){
			int cost=pq1.top().first;
			int here=pq1.top().second;
			pq1.pop();
			//다익스트라 중에 x마을 방문하면 종료 
			if(here==x) {dist_i[i]=dist_itox[here]; break;}
			if(dist_itox[here]<cost) continue;
			//인접 마을 탐색
			for(int i=0;i<adj[here].size();i++){
				int there=adj[here][i].first;
				int nextdist=adj[here][i].second+cost;
				if(nextdist<dist_itox[there]){
					dist_itox[there]=nextdist;
					pq1.push(P(nextdist,there));
				}
			}
		}
		//다음 탐색때 사용할 vector 초기화
		for(int j=1;j<=n;j++){
			dist_itox[j]=INF;
		}
	}
	
	
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(i==x) continue;
		tmp=max(tmp,dist_xtoi[i]+dist_i[i]);
	}
	cout<<tmp;
	
	return 0;
}