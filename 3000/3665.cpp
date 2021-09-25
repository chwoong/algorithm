#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef pair<int,int> P;
int n,m,t;
int main(){
	cin>>t;
	while(t--){
		int result[500]={0,};
		int val[501]={0,};
		vector<int> adj[501];
		int indeg[501]={0,};
		set<P> s;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",result+i);
			val[result[i]]=i;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			if(val[a]<val[b]){
				adj[b].push_back(a);
				indeg[a]++;
				s.insert(P(a,b));
			}else{
				adj[a].push_back(b);
				indeg[b]++;
				s.insert(P(b,a));
			}
		}
		
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(s.count(P(result[i],result[j]))) continue;
				else{
					adj[result[i]].push_back(result[j]);
					indeg[result[j]]++;
				}
			}
		}
		queue<int> q;
		for(int i=1;i<=n;i++){
			if(indeg[i]==0) q.push(i);
		}
		bool tmp=true;
		int ans[500]={0,};
		for(int i=0;i<n;i++){
			if(q.empty()) {puts("IMPOSSIBLE"); tmp=false; break;}
			if(q.size()>=2) {puts("?"); tmp=false;break;}
			int x=q.front();
			ans[i]=x;
			q.pop();
			for(int next:adj[x]){
				if(--indeg[next]==0) q.push(next);
			}
		}
		if(tmp){
			for(int i=0;i<n;i++)
				printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}