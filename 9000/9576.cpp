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

#define MAX 1001
int n,m;
int a[MAX],b[MAX];
vector<int> adj[MAX];
bool visited[MAX];

//a의 정점 i에서 b의 매칭되지 않은 정점으로 가는 경로 찾기
bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		//아직 매칭이 안되어있거나 매칭이 되어 있어도 b[j]에서 시작하는 증가 경로가 있으면
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}
int match;

int main(){
	int n,m;
	int t;
	cin>>t;
	while(t--){
	cin>>n>>m;
		match=0;
	for(int i=0;i<m;i++){
		int a0,b0;
		scanf("%d %d",&a0,&b0);
		for(int j=a0;j<=b0;j++){
			adj[i].push_back(j);
		}
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(int i=0;i<m;i++){
		//if(a[i]==-1){
			memset(visited,0,sizeof(visited));
			if(dfs(i)) match++;
		//}
	}
	cout<<match<<endl;
		for(int i=0;i<m;i++){
			adj[i].clear();
		}
	}
	return 0;
}