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

int v,e;
vector<int> adj[10001];
int discovered[10001];
int low[10001];
int cnt=0;
bool visited[10001];
int col=0;
vector<int> bcc[10001];

void dfs(int i,int prev){
	discovered[i]=low[i]=++cnt;
	for(int next:adj[i]){
		if(next==prev) continue;
		if(discovered[next]==0){
			dfs(next,i);
			low[i]=min(low[i],low[next]);
		}else low[i]=min(low[i],discovered[next]);
	}
}
void color(int i,int c){
	if(c>0) bcc[i].push_back(c);
	visited[i]=true;
	for(int next:adj[i]){
		if(visited[next]) continue;
		//i는 단절점
		if(discovered[i]<=low[next]){
			bcc[i].push_back(++col);
			color(next,col);
		}else color(next,c);
	}
}

int main(){
	cin>>v>>e;
	for(int i=0;i<e;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=v;i++){
		cnt=0;
		if(discovered[i]==0) dfs(i,0);
	}
	for(int i=1;i<=v;i++){
		col=0;
		if(!visited[i]) color(i,0);
	}
	vector<int> ans;
	for(int i=1;i<=v;i++){
		if(bcc[i].size()>=2){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(int ele:ans)
		printf("%d ",ele);
	return 0;
}