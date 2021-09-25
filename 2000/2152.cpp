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

int n,m,s,t;
vector<int> adj[100001];
int cnt(1),scc_cnt(1);
int sccid[100001];
int num[100001];
int discovered[100001];
stack<int> st;

vector<int> sadj[100001];
int indegree[100001];
bool ispos[100001];
int result[100001];
int scc(int here){
	int ret=discovered[here]=cnt++;
	st.push(here);
	for(int next:adj[here]){
		if(!discovered[next]) ret=min(ret,scc(next));
		else if(!sccid[next]) ret=min(ret,discovered[next]);
	}
	if(ret==discovered[here]){
		while(1){
			int p=st.top();
			st.pop();
			sccid[p]=scc_cnt;
			num[scc_cnt]++;
			result[scc_cnt]++;
			if(p==here) break;
		}
		scc_cnt++;
	}
	return ret;
}

int main(){
	cin>>n>>m>>s>>t;
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!discovered[i]) scc(i);
	for(int i=1;i<=n;i++){
		for(int j:adj[i]){
			if(sccid[i]!=sccid[j]){
				sadj[sccid[i]].push_back(sccid[j]);
				indegree[sccid[j]]++;
			}
		}
	}
	queue<int> q;
	int a=sccid[s];
	ispos[a]=true;
	for(int i=1;i<=scc_cnt;i++){
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int here=q.front();
		q.pop();
		for(int next:sadj[here]){
			if(ispos[here]){
				result[next]=max(result[next],num[next]+result[here]);
				ispos[next]=true;
			}
			if(--indegree[next]==0) q.push(next);
		}
	}
	int b=sccid[t];
	if(ispos[b]){
		cout<<result[b];
	}else cout<<0;
	return 0;
}