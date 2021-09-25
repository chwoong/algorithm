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

int n,m;
vector<int> adj[20000];
int discovered[20000];
stack<int> st;
int cnt,scnt(1);
int sccid[20000];

int scc(int i){
	int ret=discovered[i]=++cnt;
	st.push(i);
	for(int next:adj[i]){
		if(discovered[next]==0){
			ret=min(ret,scc(next));
		}else if(sccid[next]==0){
			ret=min(ret,discovered[next]);
		}
	}
	if(ret==discovered[i]){
		while(!st.empty()){
			int here=st.top();
			st.pop();
			sccid[here]=scnt;
			if(here==i) break;
		}
		scnt++;
	}
	return ret;
}

int main(){
	int t;
	int tmp=1;
	cin>>t;
	while(t--){
		printf("Scenario #%d: \n",tmp++);
		cin>>n>>m;
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[2*a-1].push_back(2*b-2);
			adj[2*b-1].push_back(2*a-2);
			adj[2*a-2].push_back(2*b-1);
			adj[2*b-2].push_back(2*a-1);
		}
		for(int i=0;i<2*n;i++)
			if(discovered[i]==0) scc(i);
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(sccid[i*2-1]==sccid[i*2-2]) flag=false;
		}
		if(flag) printf("No suspicious bugs found!\n\n");
		else printf("Suspicious bugs found!\n\n");
		for(int i=0;i<2*n;i++){
			discovered[i]=sccid[i]=0;
			adj[i].clear();
		}
		cnt=0; scnt=1;
	}
	return 0;
}