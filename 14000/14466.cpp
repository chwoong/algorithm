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
using namespace std;

bool adj[101][101][4];
int n,k,r;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
bool iscow[101][101];
bool visited[101][101];
vector<int> num;

int dfs(int i,int j){
	visited[i][j]=true;
	int ret=0;
	if(iscow[i][j]) ret++;
	for(int k=0;k<4;k++){
		//그쪽 방향으로 갈수 있다.
		if(adj[i][j][k]){
			int nx=i+dx[k];
			int ny=j+dy[k];
			if(nx>=1 && nx<=n && ny>=1 && ny<=n && !visited[nx][ny]){
				ret+=dfs(nx,ny);
			}
		}
	}
	return ret;
}

int main(){
	cin>>n>>k>>r;
	memset(adj,true,sizeof(adj));
	for(int i=0;i<r;i++){
		int r,c,r1,c1;
		scanf("%d %d %d %d",&r,&c,&r1,&c1);
		int x=r1-r;
		int y=c1-c;
		if(x==0 && y==1){
			adj[r][c][3]=0;
			adj[r1][c1][1]=0;
		}else if(x==1 && y==0){
			adj[r][c][0]=0;
			adj[r1][c1][2]=0;
		}else if(x==0 && y==-1){
			adj[r][c][1]=0;
			adj[r1][c1][3]=0;
		}else{
			adj[r][c][2]=0;
			adj[r1][c1][0]=0;
		}
	}
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		iscow[a][b]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!visited[i][j]) num.push_back(dfs(i,j));
		}
	}
	long long ans=0;
	for(int ele:num){
		ans+=(long long)(k-ele)*(long long)ele;
	}
	cout<<ans/2;
	return 0;
}