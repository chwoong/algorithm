#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
#include<stdlib.h>
using namespace std;

#define INF 2000000000
typedef pair<int,int> P;
int n,m;
vector<P> adj[101];
vector<int> rev[101];
vector<int> dist;
bool visited[101];
int cycle[101];
queue<int> q,q1;
bool dodal[101];
int p[101];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(P(w,v));
		rev[v].push_back(u);
	}
	//도달 가능한지 확인
	dodal[n]=true;
	q1.push(n);
	while(!q1.empty()){
		int here=q1.front();
		q1.pop();
		for(int next:rev[here]){
			if(!dodal[next]){
				dodal[next]=true;
				q1.push(next);
			}
		}
	}
	if(dodal[1]==false){
		puts("-1");
		return 0;
	}
	//ASPF
	dist.assign(n+1,-INF);
	dist[1]=0;
	visited[1]=true;
	cycle[1]++;
	q.push(1);
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			for(P next:adj[j]){
				int there=next.second;
				int cost=next.first;
				if(dist[j]!=-INF && dist[there]<cost+dist[j]){
					dist[there]=dist[j]+cost;
					p[there]=j;
					if(i==n-1 && dodal[there]){
						puts("-1");
						return 0;
					}
				}
			}
		}
	}
	vector<int> path;
	if(dist[n]==-INF){
		puts("-1");
		return 0;
	}
	for(int i=n;i!=1;i=p[i]){
		path.push_back(i);
	}
	path.push_back(1);
	reverse(path.begin(),path.end());
	for(int ele:path)
		cout<<ele<<" ";
	return 0;
}