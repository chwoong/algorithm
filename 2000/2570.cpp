#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int a[21000];
int b[21000];
vector<int> adj[21000];
bool visited[21000];

bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}
int v[100][100];
int arr[100][100];
int brr[100][100];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x--; y--;
		v[x][y]=1;
	}
	memset(arr,-1,sizeof(arr));
	memset(brr,-1,sizeof(brr));
	int cnt=0;
	for(int i=0;i<2*n;i++){
		int x=i;
		for(int y=0;y<2*n;x--,y++){
			if(x>=0 && x<n && y>=0 && y<n){
				if(v[x][y]==1){
					cnt++;
				}else{
					arr[x][y]=cnt;
				}
			}
		}
		cnt++;
	}
	int bound=cnt;
	for(int i=0;i<2*n;i++){
		int x=i;
		for(int y=n-1;y>=0;y--,x--){
			if(x>=0 && x<n && y>=0 && y<n){
				if(v[x][y]==1){
					cnt++;
				}else{
					brr[x][y]=cnt;
				}
			}
		}
		cnt++;
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]==0){
				adj[arr[i][j]].push_back(brr[i][j]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<bound;i++){
		memset(visited,0,sizeof(visited));
		if(dfs(i)) ans++;
	}
	cout<<ans;
	return 0;
}