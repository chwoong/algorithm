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
int cnt,scccnt(1);
int discovered[20000];
int low[20000];
int sccid[20000];
stack<int> st;
vector<int> adj[20000];

// x! 정점 번호
int notx(int x){
	if(x%2==0) return x+1;
	else return x-1;
}

int scc(int i){
	int ret=discovered[i]=++cnt;
	st.push(i);
	for(int next:adj[i]){
		if(discovered[next]==0){
			ret=min(ret,scc(next));
		}else if(sccid[next]==0) ret=min(ret,discovered[next]);
	}
	if(ret==discovered[i]){
		while(1){
			int here=st.top();
			st.pop();
			sccid[here]=scccnt;
			if(here==i) break;
		}
		++scccnt;
	}
	return ret;
}

int main(){
	cin>>n>>m;
	for(int t=0;t<m;t++){
		int i,j;
		scanf("%d %d",&i,&j);
		i = (i>0 ? i*2-1 : -(i+1)*2);
		j = (j>0 ? j*2-1 : -(j+1)*2);
		adj[notx(i)].push_back(j);
		adj[notx(j)].push_back(i);
	}
	for(int i=0;i<n*2;i++){
		if(discovered[i]==0) scc(i);
	}
	bool flag=true;
	for(int i=0;i<n;i++){
		if(sccid[i*2]==sccid[i*2+1]) flag=false;
	}
	if(flag) puts("1");
	else puts("0");
	return 0;
}