#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define INF 1000000
//���� ��α��� Ǯ�̸� ���� Ǯ����
int n,m;
//dist[i][j]=k �̸� i->j���� �̵��ϴµ� ��������� �ٲ���ϴ� ���� ������ k
int dist[251][251];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=(i==j?0:INF);
		}
	}
	for(int i=0;i<m;i++){
		int u,v,b;
		scanf("%d %d %d",&u,&v,&b);
		if(b==0) {
			dist[u][v]=0;
			dist[v][u]=1;
		}else{
			dist[u][v]=0;
			dist[v][u]=0;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	int k;
	cin>>k;
	while(k--){
		int s,e;
		scanf("%d%d",&s,&e);
		printf("%d\n",dist[s][e]);
	}
	return 0;
}