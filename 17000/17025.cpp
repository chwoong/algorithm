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
using namespace std;

struct P{
	int a,b;
	P(int x,int y):a(x),b(y){};
	bool operator<(P x){
		if(a!=x.a) return a<x.a;
		else return b>x.b;
	}
};
int n;
char m[1001][1001];
bool visited[1001][1001];
P ans(0,0);
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

P dfs(int i,int j){
	visited[i][j]=true;
	int area=1;
	int perimeter=0;
	for(int k=0;k<4;k++){
		int ni=i+dx[k];
		int nj=j+dy[k];
		if(ni>=0 && ni<n && nj>=0 && nj<n && m[ni][nj]=='#' && !visited[ni][nj]){
			P ret=dfs(ni,nj);
			area+=ret.a;
			perimeter+=ret.b;
		}
		else if(ni<0 || ni>=n || nj<0 || nj>=n || m[ni][nj]=='.') perimeter++;
	}
	return P(area,perimeter);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			m[i][j]=s[j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j] && m[i][j]=='#'){
				P ret=dfs(i,j);
				if(ans<ret) ans=ret;
			}
		}
	}
	cout<<ans.a<<' '<<ans.b;
	return 0;
}