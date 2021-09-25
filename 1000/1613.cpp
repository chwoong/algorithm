#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

#define INF 1000000000
int n,K;
int dist[401][401];

int main(){
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=(i==j?0:INF);
		}
	}
	for(int i=0;i<K;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		dist[a][b]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	int s;
	cin>>s;
	while(s--){
		int a,b;
		scanf("%d %d",&a,&b);
		int x=dist[a][b];
		int y=dist[b][a];
		if(x!=INF && x>0) puts("-1");
		else if(y!=INF && y>0) puts("1");
		else if(x==INF || y==INF) puts("0");
	}
	return 0;
}