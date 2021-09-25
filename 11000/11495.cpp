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

#define INF 987654321
struct Edge{
	int to,cap,flow;
	Edge* reverse;
	Edge(int t,int c):to(t),cap(c),flow(0),reverse(nullptr){}
	int residual(){
		return cap-flow;
	}
	void push(int amt){
		flow += amt;
		reverse->flow -= amt;
	}
};

vector<Edge*> adj[3000];
//窜规氢
void addEdge(int u,int v,int c){
	Edge* uv = new Edge(v,c);
	Edge* vu = new Edge(u,0);
	uv -> reverse = vu;
	vu -> reverse = uv;
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}


int networkflow(int source,int sink){
	int total=0;
	while(1){
		vector<int>par(3000,-1);
		Edge* path[3000]={0};
		queue<int> q;;
		//par[source]=source;
		q.push(source);
		while(!q.empty() && par[sink]==-1){
			int here=q.front(); q.pop();
			for(Edge* e:adj[here]){
				int next=e->to;
				if(e->residual()>0 && par[next]==-1){
					q.push(next);
					par[next]=here;
					path[next]=e;
				}
			}
		}
		if(par[sink]==-1) break;
		int amount=INF;
		for(int i=sink;i!=source;i=par[i]){
			amount=min(amount,path[i]->residual());
		}
		for(int i=sink;i!=source;i=par[i]){
			path[i]->push(amount);
		}
		total+=amount;
	}
	return total;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		int sum=0;
		int arr[50][50];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&arr[i][j]);
				sum+=arr[i][j];
			}
		}
		int st=2500; //家胶
		int en=2501; //教农
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if((i+j)%2){
					addEdge(st,i*50+j,arr[i][j]);
					for(int k=0;k<4;k++){
						int ni=i+dx[k];
						int nj=j+dy[k];
						if(ni>=0&&ni<n&&nj>=0&&nj<m){
							addEdge(i*50+j,ni*50+nj,INF);
						}
					}
				}else{
					addEdge(i*50+j,en,arr[i][j]);
				}
			}
		}
		printf("%d\n",sum-networkflow(st,en));
		for(int i=0;i<3000;i++){
			adj[i].clear();
		}
	}
	return 0;
}