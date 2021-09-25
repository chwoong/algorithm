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
int v,e;
int dist[401][401];

int main(){
	cin>>v>>e;
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			dist[i][j]=INF;
		}
	}
	while(e--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dist[a][b]=min(dist[a][b],c);
	}
	for(int k=1;k<=v;k++){
		for(int i=1;i<=v;i++){
			for(int j=1;j<=v;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	int m=INF;
	for(int i=1;i<=v;i++){
		m=min(dist[i][i],m);
	}
	printf("%d",m==INF?-1:m);
	return 0;
}