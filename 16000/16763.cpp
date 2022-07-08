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

#define INF 2000000000
typedef pair<int,int> P;

int n,m,k;
vector<int> adj[50010];
//���߿� road���� ���ϰ� �����ϱ� ���� ���� ������ map���� ����
map<P,int> road;
int dist[50010];
int basic[50010];
int p[50010];
int y[50010];
priority_queue<P,vector<P>,greater<P> > pq;
void dijk(int s){
	pq.push(P(0,s));
	dist[s]=0;
	while(!pq.empty()){
		P t=pq.top();
		pq.pop();
		int here=t.second;
		int cost=t.first;
		if(dist[here]<cost) continue;
		for(int next:adj[here]){
			if(road[P(here,next)]+cost<dist[next]){
				dist[next]=road[P(here,next)]+cost;
				pq.push(P(dist[next],next));
			}
		}
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,t;
		scanf("%d %d %d",&a,&b,&t);
		adj[a].push_back(b);
		adj[b].push_back(a);
		road[P(a,b)]=t;
		road[P(b,a)]=t;
	}
	for(int i=0;i<k;i++){
		scanf("%d %d",p+i,y+i);
	}
	for(int i=1;i<=n;i++){
		dist[i]=INF;
	}
	dijk(n);
	//���ο� ���� �߰�(n+1��忡��������)
	//n+1���� yummy�� �ִ� pasture(i)�� ���� ���� ��=(n���� i�� ���� �ִܰŸ�)-(yumminess)
	//�׷��� yummy�� �ִ� �ѹ��� �̿��Ѵ�.
	for(int i=0;i<k;i++){
		adj[n+1].push_back(p[i]);
		road[P(n+1,p[i])]=dist[p[i]]-y[i];
	}
	for(int i=1;i<=n+1;i++){
		basic[i]=dist[i];
		dist[i]=INF;
	}
	dijk(n+1);
	for(int i=1;i<n;i++){
		if(dist[i]<=basic[i]) puts("1");
		else puts("0");
	}
	return 0;
}