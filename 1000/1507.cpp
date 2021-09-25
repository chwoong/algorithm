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

int dist[20][20];
bool notcon[20][20];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&dist[i][j]);
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(dist[i][k]+dist[k][j]<dist[i][j]) {cout<<-1; return 0;}
			}
		}
	}
	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==k || k==j || i==j) continue;
				if(dist[i][k]+dist[k][j]==dist[i][j]) {notcon[i][j]=true;}
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!notcon[i][j]) ans+=dist[i][j];
		}
	}
	cout<<ans/2;
}