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
int t,n;
char s[500];
int adj[301][301];
int cnt,scc_cnt;
int discovered[301];
int sccid[301];
stack<int> st;
vector<int> id[301]; // sccid가 같은 거 끼리 vector로 저장
int sadj[301][301];

int scc(int here){
	int ret=discovered[here]=cnt++;
	st.push(here);
	for(int next=1;next<=n;next++){
		if(next!=here && adj[here][next]==1){
			if(discovered[next]==-1) ret=min(ret,scc(next));
			else if(sccid[next]==-1) ret=min(ret,discovered[next]);
		}
	}
	if(ret==discovered[here]){
		while(1){
			int p=st.top();
			st.pop();
			sccid[p]=scc_cnt;
			id[scc_cnt].push_back(p);
			if(p==here) break;
		}
		scc_cnt++;
	}
	return ret;
}

int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		memset(adj,0,sizeof(adj));
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			for(int j=1;j<=n;j++)
				adj[i][j]=s[j-1]-'0';
		}
		/*초기화*/
		memset(discovered,-1,sizeof(discovered));
		memset(sccid,-1,sizeof(sccid));
		cnt=0; scc_cnt=0;
		memset(sadj,0,sizeof(sadj));
		for(int i=0;i<n;i++)
			id[i].clear();
		/*end*/
		for(int i=1;i<=n;i++){
			if(discovered[i]==-1) scc(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(adj[i][j]==1 && adj[j][i]==0) sadj[sccid[i]][sccid[j]]=1;
			}
		}
		for(int k=0;k<scc_cnt;k++){
			for(int i=0;i<scc_cnt;i++){
				for(int j=0;j<scc_cnt;j++){
					if(sadj[i][k]==1 && sadj[k][j]==1 && sadj[i][j]==1) sadj[i][j]=0;
				}
			}
		}
		int m=0;
		vector<P> v;
		for(int i=0;i<scc_cnt;i++){
			for(int j=0;j<scc_cnt;j++){
				if(sadj[i][j]==1){
					m++;
					v.push_back(P(id[i][0],id[j][0]));
				}
			}
		}
		for(int i=0;i<scc_cnt;i++){
			int k=id[i].size();
			if(k>=2){
				for(int j=0;j<k;j++){
					m++;
					v.push_back(P(id[i][j],id[i][(j+1)%k]));
				}
			}
		}
		printf("%d\n",m);
		for(P ele:v){
			printf("%d %d\n",ele.first,ele.second);
		}
		printf("\n");
	}
	return 0;
}