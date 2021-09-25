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
#include<time.h>
using namespace std;

int p,e;
vector<int> adj[10000];
int discovered[10000];
int low[10000];
bool visited[10000];
vector<int> bcc[10000];
int cnt,col;
int component;

void dfs(int i,int p){
	discovered[i]=low[i]=++cnt;
	for(int next:adj[i]){
		if(next==p) continue;
		if(discovered[next]==0){
			dfs(next,i);
			low[i]=min(low[i],low[next]);
		}else{
			low[i]=min(low[i],discovered[next]);
		}
	}
}
void color(int i,int c){
	if(c>0) bcc[i].push_back(c);
	visited[i]=true;
	for(int next:adj[i]){
		if(visited[next]) continue;
		if(discovered[i]<=low[next]){\
			bcc[i].push_back(++col);
			color(next,col);
		}else color(next,c);
	}
}

int main(){
	while(1){
		cin>>p>>e;
		if(p==0 && e==0) break;
		for(int i=0;i<e;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=0;i<p;i++){
			cnt=0;
			if(discovered[i]==0) {component++;dfs(i,-1);}
		}
		for(int i=0;i<p;i++){
			col=0;
			if(!visited[i]) color(i,0);
		}
		int ans=0;
		for(int i=0;i<p;i++){
			if(bcc[i].size()==0) ans=max(ans,component-1);
			else ans=max(ans,component+(int)(bcc[i].size()-1));
		}
		printf("%d\n",ans);
		/*ÃÊ±âÈ­*/
		for(int i=0;i<p;i++){
			discovered[i]=low[i]=0;
			visited[i]=false;
			col=cnt=component=0;
			bcc[i].clear();
			adj[i].clear();
		}
	}
	
	return 0;
}