/*
 *  author: chw0501
 *  reference: 
 *  created: 20.04.2020 12:00:26(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int c;
int v[10][10];
int dx[6]={-1,0,1,-1,0,1};
int dy[6]={-1,-1,-1,1,1,1};
int a[100];
int b[100];
bool visited[100];
vector<int> adj[100];
bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin>>c;
	while(c--){
		int n,m;
		scanf("%d %d",&n,&m);
		int ans=0;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				v[i][j]=s[j];
				if(s[j]=='.') ans++;
			}
		}
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				/*짝수열 기준으로 매칭(짝수열이 a에 해당*/
				if(j%2==0 && v[i][j]=='.'){
					for(int k=0;k<6;k++){
						int ni=i+dx[k];
						int nj=j+dy[k];
						if(ni>=0&& ni<n && nj>=0 && nj<m && v[ni][nj]=='.'){
							adj[i*n+j].push_back(ni*n+nj);
						}
					}
				}
			}
		}
		/*이분매칭의 매칭 수를 통해 최소 버텍스 커버의 크기를 구하자*/
		/*이 값을 위에서 구한 전체 정점에서 뺀 값이 답이다.*/
		int ret=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j%2==0 && v[i][j]=='.'){
					memset(visited,0,sizeof(visited));
					if(dfs(i*n+j)) ret++;
				}
			}
		}
		printf("%d\n",ans-ret);
		for(int i=0;i<100;i++){
			adj[i].clear();
		}
	}
	return 0;
}