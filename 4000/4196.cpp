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

int t;
int cnt,scc_cnt;
int discovered[100001];
vector<int> adj[100001];
int sccid[100001];
int indegree[100001];
stack<int> st;
int scc(int here){
	int ret=discovered[here]=cnt++;
	st.push(here);
	for(int there:adj[here]){
		if(discovered[there]==-1) ret=min(ret,scc(there));
		else if(sccid[there]==-1) ret=min(ret,discovered[there]);
	}
	if(ret==discovered[here]){
		while(1){
			int p=st.top();
			st.pop();
			sccid[p]=scc_cnt;
			if(p==here) break;
		}
		scc_cnt++;
	}
	
	return ret;
}

int main(){
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		memset(discovered,-1,sizeof(discovered));
		memset(sccid,-1,sizeof(sccid));
		memset(indegree,0,sizeof(indegree));
		for(int i=1;i<=n;i++)
			adj[i].clear();
		cnt=0;
		scc_cnt=0;
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
		}
		for(int i=1;i<=n;i++){
			if(discovered[i]==-1) scc(i);
		}
		for(int i=1;i<=n;i++){
			//i->j간선에 대해 i와 j가 다른 scc에 있다면 j의 indegree추가
			for(int j:adj[i]){
				if(sccid[i]!=sccid[j]) indegree[sccid[j]]++;
			}
		}
		int ans=0;
		for(int i=0;i<scc_cnt;i++){
			if(indegree[i]==0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}