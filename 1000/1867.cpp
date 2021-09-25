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

int a[1010];
int b[1010];
vector<int> adj[500];
bool visited[1010];

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
int m[500][500];

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x--; y--;
		adj[x].push_back(500+y);
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	int ans=0;
	for(int i=0;i<n;i++){
		memset(visited,0,sizeof(visited));
		if(dfs(i)) ans++;
	}
	cout<<ans;
	return 0;
}