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

typedef pair<int,int> P;
int v,e;
int cnt,scc_cnt;
int discovered[10001];
int sccid[10001];
vector<int> adj[10001];
vector<int> ans[10001];
stack<int> st;

int scc(int here){
	int ret=discovered[here]=cnt++;
	st.push(here);
	for(int next:adj[here]){
		if(discovered[next]==-1) ret=min(ret,scc(next));
		else if(sccid[next]==-1) ret=min(ret,discovered[next]);
	}
	if(ret==discovered[here]){
		while(1){
			int t=st.top();
			st.pop();
			sccid[t]=scc_cnt;
			ans[scc_cnt].push_back(t);
			if(t==here) break;
		}
		scc_cnt++;
	}
	return ret;
}

int main(){
	scanf("%d %d",&v,&e);
	for(int i=0;i<e;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
	}
	memset(discovered,-1,sizeof(discovered));
	memset(sccid,-1,sizeof(sccid));
	for(int i=1;i<=v;i++){
		if(discovered[i]==-1){
			scc(i);
		}
	}
	printf("%d\n",scc_cnt);
	for(int i=0;i<scc_cnt;i++){
		sort(ans[i].begin(),ans[i].end());
	}
	vector<P> res;
	for(int i=0;i<scc_cnt;i++){
		res.push_back(P(ans[i][0],i));
	}
	sort(res.begin(),res.end());
	for(int i=0;i<scc_cnt;i++){
		int x=res[i].second;
		for(int ele:ans[x])
			printf("%d ",ele);
		printf("-1\n");
	}
	return 0;
}