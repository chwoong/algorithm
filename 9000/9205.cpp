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
#define INF 1000000000
int t;

int main(){
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int dist[105][105];
		int xcor[105];
		int ycor[105];
		for(int i=0;i<n+2;i++){
			int x,y;
			scanf("%d %d",xcor+i,ycor+i);
		}
		for(int i=0;i<n+2;i++){
			for(int j=0;j<n+2;j++){
				if(i==j) dist[i][j]=0;
				else{
					int d=abs(xcor[i]-xcor[j])+abs(ycor[i]-ycor[j]);
					if(d>1000) dist[i][j]=INF;
					else dist[i][j]=0;
				}
			}
		}
		for(int k=0;k<n+2;k++){
			for(int i=0;i<n+2;i++){
				for(int j=0;j<n+2;j++){
					if(dist[i][k]==0 && dist[k][j]==0) dist[i][j]=0;
				}
			}
		}
		if(dist[0][n+1]==0) puts("happy");
		else puts("sad");
	}
	return 0;
}