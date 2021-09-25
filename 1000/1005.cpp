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

int n,k,test,w;
vector<int> adj[1001];
int indeg[1001];
int t[1001];
int result[1001];
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
	cin>>test;
	while(test--){
		memset(indeg,0,sizeof(indeg));
		memset(result,0,sizeof(result));
		vector<int> v[1001];
		swap(adj,v);
		queue<int> q;
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",t+i);
		}
		for(int i=0;i<k;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			indeg[b]++;
			adj[a].push_back(b);
		}
		scanf("%d",&w);
		for(int i=1;i<=n;i++)
			if(indeg[i]==0) {result[i]=t[i]; q.push(i);}
		for(int i=0;i<n;i++){
			int x=q.front();
			q.pop();
			for(int next:adj[x]){
				result[next]=max(result[next],t[next]+result[x]);
				if(--indeg[next]==0) q.push(next);
			}
		}
		printf("%d\n",result[w]);
	}
	return 0;
}