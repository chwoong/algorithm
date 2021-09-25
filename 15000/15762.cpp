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

int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool visited[250][250];
int m[250][250];
set<int> s[250][250]; //(i,j)에 쌍으로 묶여 있는 넓이를 계산한 적이 있는 숫자를 set에 저장

int dfs(int i,int j){
	visited[i][j]=true;
	int ret=1;
	for(int k=0;k<4;k++){
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n&&m[nx][ny]==m[i][j]&&!visited[nx][ny])
			ret+=dfs(nx,ny);
	}
	return ret;
}
//(i,j)에서 시작하는 색깔 c1,c2로 이루어진 면적
int dfs2(int i,int j,int c1,int c2){
	if(m[i][j]==c1) s[i][j].insert(c2);
	else s[i][j].insert(c1);
	int ret=1;
	for(int k=0;k<4;k++){
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<n){
			if(m[nx][ny]==c1 || m[nx][ny]==c2)
				if(s[nx][ny].count(c1)==0 && s[nx][ny].count(c2)==0) ret+=dfs2(nx,ny,c1,c2);
		}
	}
	return ret;
}

int ans1,ans2;

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&m[i][j]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				ans1=max(ans1,dfs(i,j));
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<4;k++){
				int ni=i+dx[k];
				int nj=j+dy[k];
				if(ni>=0 && ni<n && nj>=0 && nj<n){
					if(m[i][j]!=m[ni][nj] && s[i][j].count(m[ni][nj])==0){
						ans2=max(ans2,dfs2(i,j,m[i][j],m[ni][nj]) );
					}
				}
			}
		}
	}
	
	cout<<ans1<<endl;
	cout<<ans2;
	return 0;
}