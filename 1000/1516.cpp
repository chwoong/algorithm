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

int n;
vector<int> adj[501];
int indegree[501];
int t[501];
int ans[501];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",t+i);
		while(1){
			int x;
			scanf("%d",&x);
			if(x==-1) break;
			adj[x].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0){
			q.push(i);
			ans[i]=t[i];
		}
	}
	
	for(int i=0;i<n;i++){
		int x=q.front();
		q.pop();
		for(int ele:adj[x]){
			ans[ele]=max(ans[ele],ans[x]+t[ele]);
			if(--indegree[ele]==0) q.push(ele);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}