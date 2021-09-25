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
int cnt,scc_cnt;
int discovered[500001];
vector<int> adj[500001];
int sccid[500001]; // 각 정점이 속한 scc 번호
int money[500001]; // scc컴포넌트에서 얻을 수 있는 돈의 총합
int arr[500001]; //각 atm인출 금액
vector<int> rest;
int indegree[500001];
//scc간의 adj
vector<int> sadj[500001];
//ans
int ans[500001];
//시작점에서 도달가능?
bool ispos[500001];
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
			money[scc_cnt]+=arr[p];
			if(p==here) break;
		}
		scc_cnt++;
	}
	
	return ret;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	memset(discovered,-1,sizeof(discovered));
	memset(sccid,-1,sizeof(sccid));
	for(int i=1;i<=n;i++){
		if(discovered[i]==-1) scc(i);
	}
	int s,num; //출발점과 레스토랑 개수
	scanf("%d %d",&s,&num);
	for(int i=0;i<num;i++){
		int x;
		scanf("%d",&x);
		rest.push_back(x);
	}
	//scc간의 방향 설정
	for(int i=1;i<=n;i++){
		for(int j:adj[i]){
			if(sccid[i]!=sccid[j]){
				sadj[sccid[i]].push_back(sccid[j]);
				indegree[sccid[j]]++;
			}
		}
	}
	queue<int> q;
	for(int i=0;i<scc_cnt;i++){
		ans[i]=money[i];
		if(i==sccid[s]) ispos[i]=true;
		if(indegree[i]==0) q.push(i);
	}
	while(!q.empty()){
		int here=q.front();
		q.pop();
		for(int next:sadj[here]){
			if(ispos[here]){
				ans[next]=max(ans[next],ans[here]+money[next]);
				ispos[next]=true;
			}
			if(--indegree[next]==0) q.push(next);
		}
	}
	int res=0;
	for(int ele:rest){
		if(ispos[sccid[ele]]) res=max(res,ans[sccid[ele]]);
	}
	cout<<res;
	return 0;
}