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
#include<time.h>
using namespace std;

typedef pair<int,int> P;
int n,k;
vector<int> adj[100001];
int depth[100001];
int cnt=0;
bool visited[100001];
int indegree[100001];
bool check[100001];

void bfs(int i){
	visited[i]=true;
	queue<int> q;
	q.push(i);
	while(!q.empty()){
		int len=q.size();
		for(int j=0;j<len;j++){
			int here=q.front();
			depth[here]=cnt;
			q.pop();
			for(int next:adj[here]){
				if(!visited[next]) {visited[here]=true; q.push(next);}
			}
		}
		cnt++;
	}
}

//depth이하로만 갈 수 있으면 다 check
void dfs(int i,int p,int l){
	if(indegree[i]==1 && depth[i]>=l) check[i]=true; 
	for(int next:adj[i]){
		if(next==p) continue;
		if(depth[next]>=l) dfs(next,i,l+1);
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		indegree[a]++;
		indegree[b]++;
	}
	bfs(k);
	vector<P> v;
	for(int i=1;i<=n;i++){
		if(indegree[i]==1) v.push_back(P(depth[i],i));
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(auto& i:v){
		int dist=i.first;
		int p=i.second;
		if(!check[p]){
			ans++;
			check[p]=true;
			dfs(p,0,0);
		}
	}
	cout<<ans;
	return 0;
}