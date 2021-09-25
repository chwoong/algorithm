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
const int N=100000;
const int MAX=18;
const int INF=1000000;
int n,k;
vector<P> adj[N];
int par[N][MAX];
int dmin[N][MAX];
int dmax[N][MAX];
int depth[N];

void dfs(int curr){
	for(P there:adj[curr]){
		int next=there.first;
		if(depth[next]==-1){
			par[next][0]=curr;
			dmin[next][0]=there.second;
			dmax[next][0]=there.second;
			depth[next]=depth[curr]+1;
			dfs(next);
		}
	}
}
void init(){
	for(int j=0;j<MAX-1;j++)
		for(int i=0;i<n;i++)
			if(par[i][j]!=-1){
				par[i][j+1]=par[par[i][j]][j];
				dmin[i][j+1]=min(dmin[i][j],dmin[par[i][j]][j]);
				dmax[i][j+1]=max(dmax[i][j],dmax[par[i][j]][j]);
			}
}

P lca(int a,int b){
	int x=INF;
	int y=0;
	//depth[a]<=depth[b]
	if(depth[a]>depth[b]) swap(a,b);
	for(int i=MAX-1;i>=0;i--){
		if(depth[b]-depth[a]>=(1<<i) ){
			x=min(x,dmin[b][i]);
			y=max(y,dmax[b][i]);
			b=par[b][i];	
		}
	}
	if(a==b) return P(x,y);
	for(int i=MAX-1;i>=0;i--){
		if(par[a][i]!=par[b][i]){
			x=min(x,min(dmin[a][i],dmin[b][i]));
			y=max(y,max(dmax[a][i],dmax[b][i]));
			a=par[a][i];
			b=par[b][i];
		}
	}
	//마지막엔 a,b의 부모가 같음
	x=min(x,min(dmin[a][0],dmin[b][0]));
	y=max(y,max(dmax[a][0],dmax[b][0]));
	return P(x,y);
}

int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--; b--;
		adj[a].push_back(P(b,c));
		adj[b].push_back(P(a,c));
	}
	memset(par,-1,sizeof(par));
	memset(depth,-1,sizeof(depth));
	depth[0]=0;
	//0번 점에서 초기화
	dfs(0);
	init();
	
	cin>>k;
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--; b--;
		P ans=lca(a,b);
		printf("%d %d\n",ans.first,ans.second);
	}
	return 0;
}