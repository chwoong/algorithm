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
int n;
vector<int> adj[100000];
int discovered[100000];
int low[100000];
int cnt,col;
int visited[100000];
vector<int> bcc[100000];
vector<int> sec[100000];

void dfs(int i,int p){
	discovered[i]=low[i]=++cnt;
	for(int next:adj[i]){
		if(next==p) continue;
		if(discovered[next]==0){
			dfs(next,i);
			low[i]=min(low[i],low[next]);
		}else{
			low[i]=min(low[i],discovered[next]);
		}
	}
}

void color(int i,int c){
	if(c>0) {
		bcc[i].push_back(c);
		sec[c].push_back(i);
	}
	visited[i]=true;
	for(int next:adj[i]){
		if(visited[next]) continue;
		if(low[next]>=discovered[i]){
			bcc[i].push_back(++col);
			sec[col].push_back(i);
			color(next,col);
		}else color(next,c);
	}
}

int main(){
	int t=0;
	while(1){
		t++;
		cin>>n;
		if(n==0) break;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(1,0);
		color(1,0);
		/* 각 bcc중 하나의 bcc에 속한 정점들 생각 */
		/* 딱 하나에만 여러 색깔 들어있는 경우. 모두 같은 색깔인 것도 가능 */
		/* 그 경우가 bcc 트리의 leaf일 때이기 때문이다. */
		/* 대피소 개수는 최소 2개다 */
		long long ans=1;
		long long num=0;
		//그 색깔로 저장된 정점들
		for(int i=1;i<=col;i++){
			int x=0;
			for(int j:sec[i]){
				if(bcc[j].size()>=2) x++;
			}
			if(x<2) {
				num++;
				ans*=(long long)(sec[i].size()-1);
			}
		}
		if(num>=2) printf("Case %d: %lld %lld\n",t,num,ans);
		else{
			printf("Case %d: %lld %lld\n",t,2ll,((long long)sec[1].size()*(long long)(sec[1].size()-1))/2ll);
		}
		
		/*reset*/
		for(int i=0;i<=n+1;i++){
			adj[i].clear();
			sec[i].clear();
			bcc[i].clear();
			discovered[i]=low[i]=visited[i]=0;
		}
		cnt=col=0;
	}
	return 0;
}