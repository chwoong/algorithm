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

int N,M;
int cnt;
vector<int> adj[300001];
int low[300001];
int discovered[300001];
vector<P> ans;

void dfs(int i,int prev){
	discovered[i]=low[i]=++cnt;
	for(int next:adj[i]){
		if(next==prev) continue;
		if(discovered[next]==0){
			dfs(next,i);
			low[i]=min(low[next],low[i]);
			if(low[next]>discovered[i]){
				ans.push_back(P(min(next,i),max(next,i)));
			}
		}
		else low[i]=min(low[i],discovered[next]);
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
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto& ele: ans){
		printf("%d %d\n",ele.first,ele.second);
	}
	
	return 0;
}