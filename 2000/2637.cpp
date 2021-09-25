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
vector<P> adj[101];
///ans[i][j]: i를 만드는데 필요한 기본부품 j의 개수
int ans[101][101];
int indeg[101];

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,k;
		scanf("%d %d %d",&x,&y,&k);
		adj[y].push_back(P(x,k));
		indeg[x]++;
	}
	queue<int> q;
	
	for(int i=1;i<=n;i++){
		if(indeg[i]==0) {ans[i][i]=1;q.push(i);}
	}
	for(int i=0;i<n;i++){
		int x=q.front();
		q.pop();
		for(P ele:adj[x]){
			int next=ele.first;
			int num=ele.second;
			for(int i=1;i<=n-1;i++){
				ans[next][i]+=num*ans[x][i];
			}
			if(--indeg[next]==0) q.push(next);
		}
	}
	for(int i=1;i<=n-1;i++){
		if(ans[n][i]) printf("%d %d\n",i,ans[n][i]);
	}
	return 0;
}