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
		int a,b;
		scanf("%d %d",&a,&b);
		dist[a][b]=1;
		dist[b][a]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	int ans=INF;
	int a=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			sum+=dist[i][j];
		}
		if(sum<ans){
			ans=sum;
			a=i;
		}
	}
	cout<<a;
	return 0;
}