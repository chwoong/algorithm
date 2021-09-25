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
using namespace std;

typedef pair<int,int> P;
int n,ques;
vector<P> adj[5010];
bool visited[5010];
int k;

int dfs(int i){
	int ret=1;
	visited[i]=true;
	for(P next:adj[i]){
		int there=next.first;
		int dist=next.second;
		if(visited[there]==false && dist>=k) ret+=dfs(there);
	}
	return ret;
}

int main(){
	cin>>n>>ques;
	for(int i=0;i<n-1;i++){
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		adj[p].push_back(P(q,r));
		adj[q].push_back(P(p,r));
	}
	for(int i=0;i<ques;i++){
		int v;
		memset(visited,false,sizeof(visited));
		scanf("%d %d",&k,&v);
		printf("%d\n",dfs(v)-1);
	}
	return 0;
}