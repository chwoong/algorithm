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

#define INF 1000000
int n,m;
int dist[101][101];
bool visited[101];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=(i==j?0:INF);
		}
	}
	while(m--){
		int a,b;
		scanf("%d %d",&a,&b);
		dist[a][b]=min(dist[a][b],1);
		dist[b][a]=min(dist[b][a],1);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	vector<int> rep;
	for(int i=1;i<=n;i++){
		vector<int> v;
		if(visited[i]) continue;
		if(!visited[i]){
			for(int j=1;j<=n;j++){
				if(dist[i][j]!=INF){
					visited[j]=true;
					v.push_back(j);
				}
			}
		}
		cout<<endl;
		int x=100;
		int a;
		for(int p:v){
			int m=0;
			for(int q:v){
				if(p!=q){
					if(m<dist[p][q]){
						m=dist[p][q];
					}
				}
			}
			if(m<x){
				x=m;
				a=p;
			}
		}
		rep.push_back(a);
	}
	sort(rep.begin(),rep.end());
	cout<<rep.size()<<endl;
	for(int ele:rep){
		cout<<ele<<endl;
	}
	return 0;
}