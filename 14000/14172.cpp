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

typedef pair<long long,long long> P;

long long x[200];
long long y[200];
long long power[200];
vector<int> adj[200];
bool visited[200];
int dfs(int here){
	int ret=1;
	visited[here]=true;
	for(int next:adj[here]){
		if(!visited[next]) ret+=dfs(next);
	}
	return ret;
}
int n;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld %lld %lld",x+i,y+i,power+i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				//i->j통신이 가능한지 확인하자
				long long dist=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
				if(dist<=power[i]*power[i])	adj[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		memset(visited,false,sizeof(visited));
		ans=max(ans,dfs(i));
	}
	cout<<ans;
	return 0;
}