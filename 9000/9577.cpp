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

int a[250];
int b[250];
vector<int> adj[110];
bool visited[250];

bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}
int t;

int main(){
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int t1,t2,x;
			scanf("%d %d",&t1,&t2);
			scanf("%d",&x);
			for(int j=0;j<x;j++){
				int p;
				scanf("%d",&p);
				for(int k=t1;k<t2;k++){
					//k시각의 정점에 p번 조각을 연결
					adj[k].push_back(100+p);
				}
			}
		}
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		int ans=0;
		bool tmp=true;
		for(int i=0;i<100;i++){
			memset(visited,0,sizeof(visited));
			if(dfs(i)) ans++;
			if(ans==n) {tmp=false;printf("%d\n",i+1);break;}
		}
		if(tmp) printf("%d\n",-1);
		for(int i=0;i<110;i++){
			adj[i].clear();
		}
	}
	return 0;
}