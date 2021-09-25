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

int a[600];
int b[600];
vector<int> adj[300];
bool visited[600];

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
int m[300][300];

int main(){
	int r,c,n;
	cin>>r>>c>>n;
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x--; y--;
		m[x][y]=1;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(!m[i][j]){
				adj[i].push_back(300+j);
			}
		}
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	int ans=0;
	for(int i=0;i<r;i++){
		memset(visited,0,sizeof(visited));
		if(dfs(i)) ans++;
	}
	cout<<ans;
	return 0;
}