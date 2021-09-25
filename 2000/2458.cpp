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

int n;
int m;
int dist[501][501];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		dist[a][b]=1;
		dist[b][a]=-1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dist[i][k]==1 && dist[k][j]==1) dist[i][j]=1;
				if(dist[i][k]==-1 && dist[k][j]==-1) dist[i][j]=-1;
			}
		}
	}
	int num=0;
	for(int i=1;i<=n;i++){
		bool tmp=true;
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(dist[i][j]==0) {tmp=false; break;}
			}
		}
		if(tmp) num++;
	}
	cout<<num;
	return 0;
}