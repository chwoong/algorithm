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
int n,m;
vector<int> adj[100000];
int cnt,scc_cnt;
int sccid[100000];
int discovered[100000];
int indegree[100000];
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
	cin>>t;
	while(t--){
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			adj[i].clear();
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
		}
		cnt=0;
		scc_cnt=0;
		memset(discovered,-1,sizeof(discovered));
		memset(sccid,-1,sizeof(sccid));
		memset(indegree,0,sizeof(indegree));
		for(int i=0;i<n;i++){
			if(discovered[i]==-1) scc(i);
		}
		for(int i=0;i<n;i++)
			for(int j:adj[i])
				if(sccid[i]!=sccid[j]) indegree[sccid[j]]++;
		int ans=0;
		int num=0;
		for(int i=0;i<scc_cnt;i++){
			if(indegree[i]==0){
				ans=i;
				num++;
			}
		}
		if(num==1){
			vector<int> result;
			for(int i=0;i<n;i++){
				if(sccid[i]==ans) result.push_back(i);
			}
			sort(result.begin(),result.end());
			for(int ele:result)
				printf("%d\n",ele);
		}else{
			printf("Confused\n");
		}
		printf("\n");
	}
	return 0;
}