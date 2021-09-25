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

int n,m;
vector<int> adj[5001];
int cnt,scc_cnt;
int sccid[5001];
int discovered[5001];
int outdegree[5001];
vector<int> ans;
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
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(int i=1;i<=n;i++)
			adj[i].clear();
		memset(sccid,-1,sizeof(sccid));
		memset(discovered,-1,sizeof(discovered));
		memset(outdegree,0,sizeof(outdegree));
		ans.clear();
		cnt=0;
		scc_cnt=0;
		stack<int> s;
		swap(s,st);
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
		}
		for(int i=1;i<=n;i++){
			if(discovered[i]==-1) scc(i);
		}
		for(int i=1;i<=n;i++){
			for(int j:adj[i]){
				if(sccid[i]!=sccid[j]){
					outdegree[sccid[i]]++;
				}
			}
		}
		set<int> k;
		for(int i=0;i<scc_cnt;i++){
			if(outdegree[i]==0){
				k.insert(i);
			}
		}
		for(int i=1;i<=n;i++){
			if(k.count(sccid[i])) ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		for(int ele:ans)
			printf("%d ",ele);
		printf("\n");
	}
	return 0;
}