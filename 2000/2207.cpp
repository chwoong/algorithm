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
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a=(a>0?2*a-1:-2*(a+1));
		b=(b>0?2*b-1:-2*(b+1));
		adj[notx(a)].push_back(b);
		adj[notx(b)].push_back(a);
	}
	for(int i=0;i<2*m;i++){
		if(discovered[i]==0) scc(i);
	}
	//같은 scc내에 x와 !x가 같이 들어있으면 불가능
	bool flag=true;
	for(int i=1;i<=m;i++){
		if(sccid[i*2-2]==sccid[i*2-1]) flag=false;
	}
	if(flag) puts("^_^");
	else puts("OTL");
	
	return 0;
}