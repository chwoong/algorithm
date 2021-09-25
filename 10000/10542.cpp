#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
using namespace std;

bool visited[500001];
int point[500001];
int indegree[500001];
int ans;
void dfs(int i,int ismaf){
	if(indegree[i]==0 && !visited[i] && ismaf){
		ans++;
		visited[i]=true;
		indegree[point[i]]--;
		dfs(point[i],0);
	}
	if(!visited[i]&&!ismaf){
		visited[i]=true;
		indegree[point[i]]--;
		dfs(point[i],1);
	}
}

int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		int x;
		scanf("%d",&x);
		indegree[x]++;
		point[i]=x;
	}
	for(int i=1;i<=N;i++){
		if(indegree[i]==0 && !visited[i]){
			dfs(i,1);
		}
	}
	for(int i=1;i<=N;i++){
		if(!visited[i]){
			dfs(i,0);
		}
	}
	cout<<ans;
	return 0;
}