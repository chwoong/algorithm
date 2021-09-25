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
map<string,int>m;
int n;
int num;
vector<int> adj[3000];
int cnt,scc_cnt;
int discovered[3000];
int sccid[3000];
stack<int> st;
long long result[3000];
int indegree[3000];
vector<P> v[3000];

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
	cin>>n;
	for(int i=0;i<3000;i++)
		result[i]=1;
	memset(discovered,-1,sizeof(discovered));
	memset(sccid,-1,sizeof(sccid));
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(m.count(s)==0) m[s]=num++;
		int l;
		scanf("%d",&l);
		for(int j=0;j<l;j++){
			string k;
			cin>>k;
			if(m.count(k)==0) m[k]=num++;
			adj[m[k]].push_back(m[s]);
		}
	}
	for(int i=0;i<num;i++){
		if(discovered[i]==-1) scc(i);
	}
	for(int i=0;i<num;i++){
		for(int j:adj[i]){
			if(sccid[i]!=sccid[j]){
				indegree[sccid[j]]++;
				v[sccid[i]].push_back(P(i,j));
			}
		}
	}
	queue<int> q;
	for(int i=0;i<scc_cnt;i++)
		if(indegree[i]==0) q.push(i);
	while(!q.empty()){
		int h=q.front();
		q.pop();
		for(P con:v[h]){
			int f=con.first;
			int g=con.second;
			result[g]+=result[f];
			if(--indegree[sccid[g]]==0) q.push(sccid[g]);
		}
	}
	string key;
	cin>>key;
	if(m.count(key)==0) cout<<1;
	else cout<<result[m[key]];
	return 0;
}