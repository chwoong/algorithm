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
char sign[11];
int outdeg[11];
int indeg[11];
vector<int> adj[11];
vector<int> adj1[11];
int ans[11];
int ans1[11];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		char s[10];
		scanf("%s",s);
		sign[i]=s[0];
	}
	for(int i=1;i<=n;i++){
		if(sign[i]=='<'){
			outdeg[i]++;
			indeg[i+1]++;
			adj[i+1].push_back(i);
			adj1[i].push_back(i+1);
		}else{
			outdeg[i+1]++;
			indeg[i]++;
			adj[i].push_back(i+1);
			adj1[i+1].push_back(i);
		}
	}
	priority_queue<int,vector<int>, greater<int> > pq, pq1;
	for(int i=1;i<=n+1;i++){
		if(outdeg[i]==0) pq.push(i);
		if(indeg[i]==0) pq1.push(i);
	}
	int val=9;
	int vam=0;
	for(int i=0;i<n+1;i++){
		int x=pq.top();
		pq.pop();
		ans[x]=val--;
		for(int next:adj[x]){
			if(--outdeg[next]==0) pq.push(next);
		}
		int y=pq1.top();
		pq1.pop();
		ans1[y]=vam++;
		for(int next:adj1[y]){
			if(--indeg[next]==0) pq1.push(next);
		}
	}
	for(int i=1;i<=n+1;i++){
		printf("%d",ans[i]);
	}
	printf("\n");
	for(int i=1;i<=n+1;i++){
		printf("%d",ans1[i]);
	}
	return 0;
}