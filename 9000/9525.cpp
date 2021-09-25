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

vector<int> adj[10200];
int a[20200];
int b[20200];
bool visited[20200];
int m[100][100];

int red[100][100];
int blue[100][100];

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


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			m[i][j]=s[j];
		}
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	memset(red,-1,sizeof(red));
	memset(blue,-1,sizeof(blue));
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(m[i][j]=='X') cnt++;
			else red[i][j]=cnt;
		}
		cnt++;
	}
	//red에 적힌 번호는 0~bound -1 이다.
	int bound=cnt;
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(m[i][j]=='X') cnt++;
			else blue[i][j]=cnt;
		}
		cnt++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(m[i][j]!='X'){
				adj[red[i][j]].push_back(blue[i][j]);
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