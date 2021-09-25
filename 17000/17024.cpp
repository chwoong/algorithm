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
using namespace std;

int n;
int col[101010];
vector<int> adj[101010];

void dfs(int here,int prev){
	int cnt=1;
	for(int next:adj[here]){
		if(next!=prev){
			while(1){
			if(col[here]!=cnt && col[prev]!=cnt) {
				col[next]=cnt++;
				dfs(next,here);
				break;}
			else cnt++;
			}
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	col[1]=1;
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,col[i]);
	}
	cout<<ans;
	return 0;
}