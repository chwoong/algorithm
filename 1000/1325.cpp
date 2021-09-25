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

int n,m;
vector<int> adj[10001];
bool visited[10001];
bool acyclic[10001];
int num[10001];
queue<int> c; //cycle이루는 원소들

int dfs(int i){
	int ret=1;
	visited[i]=true;
	for(int next:adj[i]){
		if(!visited[next]) ret+=dfs(next);
	}
	return ret;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			visited[j]=false;
		if(!visited[i]) num[i]=dfs(i);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(res<num[i]) res=num[i];
	}
	for(int i=1;i<=n;i++){
		if(num[i]==res) printf("%d ",i);
	}
	return 0;
}