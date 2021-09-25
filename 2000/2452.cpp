#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int m,n;
int g[100][100];
int ind[100][100];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int cnt=1;
bool visited[10101];
vector<int> adj[10101];
int ans=1000000;

void dfs(int i,int j,int col){	
	ind[i][j]=cnt;
	for(int k=0;k<4;k++){
		int ni=i+dx[k];
		int nj=j+dy[k];
		if(ni>=0 && ni<m && nj>=0 && nj<n && ind[ni][nj]==0 && g[ni][nj]==col){
			dfs(ni,nj,col);
		}
	}
}

//i번 정점으로부터 가장 멀리 떨어져있는 거리를 반환
int bfs(int i){
	memset(visited,0,sizeof(visited));
	visited[i]=true;
	queue<int> q;
	q.push(i);
	int d=0;
	while(!q.empty()){
		d++;
		if(d>ans) return ans;
		int len=q.size();
		for(int j=0;j<len;j++){
			int here=q.front();
			q.pop();
			for(int next:adj[here]){
				if(!visited[next]){
					q.push(next);
					visited[next]=true;
				}
			}
		}
	}
	return d-1;
}


int main(){
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	//그래프 정점 생성
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(ind[i][j]==0){
				dfs(i,j,g[i][j]);
				cnt++;
			}
		}
	}
	//그래프 연결 정보
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<2;k++){
				int ni=i+dx[k];
				int nj=j+dy[k];
				if(ni>=0 && ni<m && nj>=0 && nj<n && ind[i][j]!=ind[ni][nj]){
					adj[ind[i][j]].push_back(ind[ni][nj]);
					adj[ind[ni][nj]].push_back(ind[i][j]);
				}
			}
		}
	}
	for(int i=1;i<cnt;i++){
		sort(adj[i].begin(),adj[i].end());
		adj[i].resize(unique(adj[i].begin(),adj[i].end()) - adj[i].begin());
	}
	//정점은 1 ~ (cnt-1)까지이다.
	for(int i=1;i<cnt;i++){
		int res=bfs(i);
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}