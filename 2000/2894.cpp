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

int d,m,n;
vector<int> adj[1001];
vector<int> rev[1001];
int indegree[1001];
vector<int> c;
vector<int> pos;
vector<int> res;
bool visited[1001];
int v[1001];

void revdfs(int i){
	if(indegree[i]==0) pos.push_back(i);
	visited[i]=true;
	for(int next:rev[i]){
		if(!visited[next]) revdfs(next);
	}
}

void dfs(int i,int k){
	if(!visited[i] && k) printf("%d ",i);
	visited[i]=true;
	for(int next:adj[i]){
		if(!visited[next]) dfs(next,k);
	}
}

int main(){
	cin>>d>>m>>n;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		rev[b].push_back(a);
		indegree[b]++;
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		c.push_back(x);	
	}
	for(int ele:c){
		memset(visited,false,sizeof(visited));
		pos.clear();
		revdfs(ele);
		//pos들에서 공통으로 접근 되는 부분은 답에 포함되어야 한다.
		int len=pos.size();
		memset(v,0,sizeof(v));
		for(int i=0;i<len;i++){
			memset(visited,false,sizeof(visited));
			dfs(pos[i],0);
			for(int j=1;j<=d;j++){
				if(visited[j]) v[j]++;
			}
		}
		for(int i=0;i<=d;i++){
			if(v[i]==len) res.push_back(i);
		}
	}
	memset(visited,false,sizeof(visited));
	for(int ele:c) res.push_back(ele);
	for(int ele:res) dfs(ele,1);
	return 0;
}