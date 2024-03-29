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
int n,m;
int dist[101][101];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=(i==j?0:INF);
		}
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dist[a][b]=min(dist[a][b],c);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",dist[i][j]==INF?0:dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}