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
using namespace std;

#define MAX 100000000
int n,m;
int x[100001];
int y[100001];
vector<int> adj[100001];
bool visited[100001];
int min_x,min_y,max_x,max_y;
int ans=4*MAX;
void dfs(int here){
	visited[here]=true;
	min_x=min(min_x,x[here]);
	min_y=min(min_y,y[here]);
	max_x=max(max_x,x[here]);
	max_y=max(max_y,y[here]);
	for(int next:adj[here]){
		if(!visited[next]) dfs(next);
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d %d",x+i,y+i);
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			min_y=min_x=MAX;
			max_x=max_y=0;
			dfs(i);
			ans=min(ans,2*(max_x-min_x)+2*(max_y-min_y));
		}
	}
	cout<<ans;
	return 0;
}