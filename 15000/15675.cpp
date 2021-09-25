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

vector<int> adj[4000];

int n,m;
char c[1000][1000];
int dis[4000];
int cnt,scnt(1);
stack<int> st;
int sccid[4000];

int scc(int i){
	int ret=dis[i]=++cnt;
	st.push(i);
	for(int next:adj[i]){
		if(dis[next]==0) ret=min(ret,scc(next));
		else if(sccid[next]==0) ret=min(ret,dis[next]);
	}
	if(ret==dis[i]){
		while(!st.empty()){
			int h=st.top();
			sccid[h]=scnt;
			st.pop();
			if(h==i) break;
		}
		scnt++;
	}
	return ret;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			c[i][j]=s[j];
		}
	}
	//보석이 들어있는 칸에 대해서는 행과 열중에 하나만 선택
	//(!x v !y) ^ (x v y)
	//위치추적기가 들어있는 칸에 대해서는 행과 열 둘다 선택 or 둘다 선택x
	//(!x v y) ^ (x v !y)
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(c[i][j]=='*'){
				adj[2*i+1].push_back(2*j+2000);
				adj[2000+2*j+1].push_back(2*i);
				adj[2*i].push_back(2*j+1+2000);
				adj[2*j+2000].push_back(2*i+1);
			}else if(c[i][j]=='#'){
				adj[2*i+1].push_back(2*j+1+2000);
				adj[2000+2*j+1].push_back(2*i+1);
				adj[2*i].push_back(2*j+2000);
				adj[2*j+2000].push_back(2*i);
			}
		}
	}
	for(int i=0;i<4000;i++){
		cnt=0;
		if(dis[i]==0) scc(i);
	}
	bool flag=true;
	for(int i=0;i<2000;i++){
		if(sccid[2*i]==sccid[2*i+1]) flag=false;
	}
	if(flag) puts("1");
	else puts("0");
	return 0;
}