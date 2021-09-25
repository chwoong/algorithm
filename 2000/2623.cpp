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

int n,m;
vector<int> adj[1001];
int indegree[1001];
vector<int> ans;
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		vector<int> v;
		int prev;
		scanf("%d",&prev);
		for(int i=0;i<x-1;i++){
			int a;
			scanf("%d",&a);
			indegree[a]++;
			adj[prev].push_back(a);
			prev=a;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(indegree[i]==0) q.push(i);
	}
	
	for(int i=0;i<n;i++){
		if(q.empty()){
			puts("0");
			return 0;
		}
		int x=q.front();
		ans.push_back(x);
		q.pop();
		for(int ele:adj[x]){
			if(--indegree[ele]==0) q.push(ele);
		}
	}
	for(int ele:ans)
		printf("%d\n",ele);
	return 0;
}