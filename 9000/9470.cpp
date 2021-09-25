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
int test,k,m,p;
int main(){
	cin>>test;
	while(test--){
		int indeg[1001];
		int result[1001];
		vector<int> adj[1001];
		scanf("%d %d %d",&k,&m,&p);
		for(int i=0;i<p;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			indeg[b]++;
			adj[a].push_back(b);
		}
		queue<int> q;
		P info[1001];
		for(int i=1;i<=m;i++)
			if(indeg[i]==0) {result[i]=1; info[i].first=1; q.push(i);}
		for(int i=0;i<m;i++){
			int x=q.front();
			q.pop();
			for(int next:adj[x]){
				if(info[next].first<result[x]) {info[next].first=result[x]; info[next].second=1;}
				else if(info[next].first==result[x]) info[next].second=2;
				if(--indeg[next]==0){
					if(info[next].second==1) result[next]=info[next].first;
					else result[next]=info[next].first+1;
					q.push(next);
				}
			}
		}
		int ans=1;
		for(int i=1;i<=m;i++)
			ans=max(ans,result[i]);
		printf("%d %d\n",k,ans);
	}
	return 0;
}