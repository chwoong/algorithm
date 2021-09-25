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
int n,m;
P edge[300000];
vector<vector<int> > adj;
int col[100001];
bool pos=true;
bool visited[100001];

void dfs(int i){
	visited[i]=true;
	for(int ele:adj[i]){
		if(visited[ele]){
			if(col[ele]==col[i]) pos=false;
			else continue;
		}else{
			col[ele]=(!col[i]);
			dfs(ele);
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		edge[i]=P(a,b);
	}
	//이분 탐색
	int l(1),h(m);
	while(l+1<h){
		pos=true;
		//mid번째까지 간선을 추가했을 때 두 팀으로 나누는 것이 가능한지 확인
		int mid=(l+h)/2;
		vector<vector<int> > v(n+1);
		adj.swap(v);
		for(int i=0;i<mid;i++){
			adj[edge[i].first].push_back(edge[i].second);
			adj[edge[i].second].push_back(edge[i].first);
		}
		memset(visited,false,sizeof(visited));
		for(int i=1;i<=n;i++){
			if(!visited[i]) {col[i]=0;dfs(i);}
		}
		//mid로 했을 때 가능하면 l=mid
		if(pos) l=mid;
		else h=mid;
	}
	cout<<l+1;
	return 0;
}