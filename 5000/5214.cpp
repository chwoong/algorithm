#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

int n,m,k;
//1~n까지는 역 정점
//(n+1)~(n+m)까지는 하이퍼튜브 정점
vector<int> adj[101001];
bool visited[101001];

int bfs(){
	queue<int> q;
	int cnt=1;
	q.push(1);
	visited[1]=true;
	while(!q.empty()){
		cnt++;
		int len=q.size();
		while(len--){
			int here=q.front();
			q.pop();
			for(int next:adj[here]){
				if(!visited[next]){
					q.push(next);
					visited[next]=true;
					if(next==n) return (cnt+1)/2;
				}
			}
		}
	}
	return -1;
}

int main(){
	cin>>n>>k>>m;
	for(int i=n+1;i<=n+m;i++){
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			adj[i].push_back(x);
			adj[x].push_back(i);
		}
	}
	if(n==1) cout<<1;
	else cout<<bfs();
	
	return 0;
}