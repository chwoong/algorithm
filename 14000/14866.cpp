#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

//√‚√≥: https://blog.myungwoo.kr/116
int N,M;
vector<int> adj[300001];
vector<int> child[300001];
int discovered[300001];
int cnt=1;
int inback[300001];
int parentback[300001];
int allback[300001];


void dfs(int here,int prev){
	if(discovered[here]==0) discovered[here]=cnt++;
	for(int next:adj[here]){
		if(next!=prev){
			//tree edge
			if(discovered[next]==0){
				child[here].push_back(next);
				int tmp=inback[here];
				dfs(next,here);
				parentback[next]+=inback[here]-tmp;
				inback[here]+=inback[next];
				allback[here]+=allback[next];
			}
			//back edge
			else if(discovered[here]>discovered[next]){
				inback[next]++;
				allback[here]++;
			}
		}
	}
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,0);
	long long ans=0;
	for(int i=1;i<=N;i++){
		int judge=0;
		for(int ch:child[i]){
			if(inback[ch]>0) judge=1;
			if(allback[ch]-parentback[ch]-inback[ch]>1) judge=1;
		}
		if(judge || M-(N-1)-allback[i] >0) continue;
		ans+=i;
	}
	cout<<ans;
	return 0;
}