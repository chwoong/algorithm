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

typedef pair<int,int> P;
int n,m;
vector<int> adj[100001];
int discovered[100001];
int low[100001];
int cnt;
stack<P> s;
vector<vector<P> > bcc;
void dfs(int i,int p){
	discovered[i]=low[i]=++cnt;
	for(int next:adj[i]){
		if(next==p) continue;
		if(discovered[next]<discovered[i]) s.push(P(i,next));
		if(discovered[next]==0){
			dfs(next,i);
			low[i]=min(low[i],low[next]);
			if(low[next]>=discovered[i]){
				vector<P> thisbcc;
				while(!s.empty()){
					P here=s.top();
					s.pop();
					thisbcc.push_back(here);
					if(here==P(i,next)) break;
				}
				bcc.push_back(thisbcc);
			}
		}else{
			low[i]=min(low[i],discovered[next]);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	bool flag=true;
	bool vis[100001]={0,};
	for(auto& v: bcc){
		if(v.size()==1) continue;
		set<int> p;
		for(P ele:v){
			p.insert(ele.first);
			p.insert(ele.second);
		}
		//bcc에 속한 정점 수와 간선 수가 다르면 not cactus
		if(p.size()!=v.size()) flag=false;
		for(int ele:p){
			if(vis[ele]) flag=false;
			vis[ele]=true;
		}
	}
	if(flag) cout<<"Cactus";
	else cout<<"Not cactus";
	return 0;
}