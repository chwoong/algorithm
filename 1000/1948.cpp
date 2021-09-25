#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef pair<int,int> P;
int n,m,s,e;
vector<P> adj[10001];
int indeg[10001];
int result[10001];
vector<int> rev[10001];
int ans=0;
bool visited[10001];

void bfs(){
	visited[e]=true;
	queue<int> q;
	q.push(e);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int ele:rev[x]){
			if(!visited[ele]) {ans++; visited[ele]=true; q.push(ele);}
			else ans++;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adj[u].push_back(P(v,w));
		indeg[v]++;
	}
	cin>>s>>e;
	queue<int> q;
	q.push(s);
	for(int i=0;i<n;i++){
		int x=q.front();
		q.pop();
		for(P ele:adj[x]){
			int next=ele.first;
			int w=ele.second;
			if(result[x]+w>result[next]){
				vector<int> v;
				swap(rev[next],v);
				result[next]=result[x]+w;
				rev[next].push_back(x);
			}else if(result[x]+w==result[next]){
				rev[next].push_back(x);
			}
			if(--indeg[next]==0) q.push(next);
		}
	}
	cout<<result[e]<<endl;
	bfs();
	cout<<ans;
	return 0;
}