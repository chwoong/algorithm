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

vector<int> adj[200020];
vector<int> sw[100010];
int n,m;
int dis[200020];
int cnt,scnt(1);
stack<int> st;
int sccid[200020];
int state[100010];

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
	for(int i=1;i<=n;i++)
		scanf("%d",state+i);
	//i번째 스위치
	for(int i=0;i<m;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int x;
			scanf("%d",&x);
			sw[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		int a=sw[i][0];
		int b=sw[i][1];
		//sw[i][0]과 sw[i][1]둘의 누름 여부가 같아야 함
		if(state[i]){
			adj[2*a].push_back(2*b);
			adj[2*b].push_back(2*a);
			adj[2*a+1].push_back(2*b+1);
			adj[2*b+1].push_back(2*a+1);
		}
		//sw[i][0]과 sw[i][1]의 누름 여부가 달라야 함
		else{
			adj[2*a].push_back(2*b+1);
			adj[2*b].push_back(2*a+1);
			adj[2*a+1].push_back(2*b);
			adj[2*b+1].push_back(2*a);
		}
	}
	for(int i=1;i<=2*n;i++){
		if(dis[i]==0) scc(i);
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(sccid[i*2]==sccid[i*2+1]) flag=false;
	}
	if(flag) puts("1");
	else puts("0");
	return 0;
}