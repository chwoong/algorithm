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
#define MAX 1000
#define INF 987654321
struct maxflow{
	struct edge{
		int to,cap,flow,rev;
		int residual(){
			return cap-flow;
		}
	};
	vector<edge> adj[MAX];
	int par[MAX], ind[MAX];
	bool visited[MAX]={0,};
	
	void clear(){
		for(int i=0;i<MAX;i++) adj[i].clear();
		memset(visited,0,sizeof(visited));
	}
	void addEdge(int u,int v,int c){
		adj[u].push_back((edge){v,c,0,(int)adj[v].size()});
		adj[v].push_back((edge){u,0,0,(int)adj[u].size()-1});
	}
	
	bool bfs(int src,int sink){
		memset(visited,0,sizeof(visited));
		queue<int> q;
		q.push(src);
		visited[src]=true;
		while(!q.empty() && !visited[sink]){
			int here=q.front(); q.pop();
			int len=adj[here].size();
			for(int i=0;i<len;i++){
				edge e=adj[here][i];
				if(e.residual()>0 && !visited[e.to]){
					visited[e.to]=true;
					par[e.to]=here;
					ind[e.to]=i;
					q.push(e.to);
				}
			}
		}
		return visited[sink];
	}
	int match(int src,int sink){
		int total=0;
		while(bfs(src,sink)){
			int amount=INF;
			for(int i=sink;i!=src;i=par[i]){
				amount=min(amount,adj[par[i]][ind[i]].residual());
			}
			for(int i=sink;i!=src;i=par[i]){
				int r=adj[par[i]][ind[i]].rev;
				adj[par[i]][ind[i]].flow+=amount;
				adj[i][r].flow-=amount;
			}
			total+=amount;
		}
		return total;
	}
};


int main(){
	int t;
	cin>>t;
	int n;
	while(t--){
		int p=0;
		maxflow mf;
		scanf("%d",&n);
		bool arr[101][101];
		/*연결 상태*/
		memset(arr,0,sizeof(arr));
		//src:0, sink: 2*n+1
		int en[101];
		for(int i=1;i<=n;i++){
			scanf("%d",en+i);
			p+=en[i];
		}
		for(int i=1;i<=n;i++){
			string s;
			cin>>s;
			for(int j=0;j<n;j++){
				if(s[j]=='Y') arr[i][j+1]=true;
			}
		}
		bool weak[101];
		memset(weak,0,sizeof(weak));
		//적 i와 인접한 곳 중에 적이 아닌 곳이 취약점이다.
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!en[i] && arr[i][j] && en[j]) weak[j]=true;
			}
		}
		int l=1;
		int h=p+1;
		while(l+1<h){
			int mid=(l+h)/2;
			//취약점에 대해서는 용량 mid의 간선을 추가하고 아닌 곳은 용량 1의 간선을 추가한다.
			int ret=0;
			for(int i=1;i<=n;i++){
				if(weak[i]){
					ret+=mid;
					mf.addEdge(n+i,2*n+1,mid);
				}else if(en[i]){
					ret+=1;
					mf.addEdge(n+i,2*n+1,1);
				}
			}
			//src에서 아군 연결
			for(int i=1;i<=n;i++){
				if(en[i]) mf.addEdge(0,i,en[i]);
			}
			//아군 군대 끼리의 연결
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j) mf.addEdge(i,n+j,INF);
					else{
						if(en[i] && arr[i][j] && en[j]) mf.addEdge(i,n+j,INF);
					}
				}
			}
			int val=mf.match(0,2*n+1);
			if(val==ret) l=mid;
			else h=mid;
			
			mf.clear();
		}
		printf("%d\n",l);
	}
	return 0;
}