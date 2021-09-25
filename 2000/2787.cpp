#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

int n,m;
bool visited[201];
bool adj[201][201];
int amatch[201];
int bmatch[201];

bool dfs(int a){
	if(visited[a]) return false;
	visited[a]=true;
	for(int b=1;b<=n;b++){
		if(adj[a][b]){
			if(bmatch[b]==-1 || dfs(bmatch[b])){
				amatch[a]=b;
				bmatch[b]=a;
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin>>n>>m;
	memset(adj,true,sizeof(adj));
	while(m--){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(b>c) swap(b,c);
		if(a==1){
			for(int i=d+1;i<=n;i++){
				for(int j=b;j<=c;j++){
					adj[i][j]=false;
				}
			}
		}else{
			for(int i=1;i<d;i++){
				for(int j=b;j<=c;j++){
					adj[i][j]=false;
				}
			}
		}
		//그 외 구간에 v값이 나오면 안됨
		for(int i=1;i<=n;i++){
			if(i<b||i>c) adj[d][i]=false;
		}
	}
	memset(amatch,-1,sizeof(amatch));
	memset(bmatch,-1,sizeof(bmatch));
	int size=0;
	for(int start=1;start<=n;start++){
		memset(visited,false,sizeof(visited));
		if(dfs(start)) size++;
	}
	if(size==n){
		for(int i=1;i<=n;i++){
			printf("%d ",bmatch[i]);
		}
	}else{
		cout<<-1;
	}
	return 0;
}