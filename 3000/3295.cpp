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

vector<int> adj[2000];
int a[2000];
int b[2000];
bool visited[2000];

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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		memset(a,-1,sizeof(a));
		memset(b,-1,sizeof(b));
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++){
			int x,y;
			scanf("%d",&x);
			scanf("%d",&y);
			//�� ������ ������ ������ ������ �������� �и�
			//�̺и�Ī�� ��Ī �ִ�
			//������ �� ������ indegree�� outdegree ������ 1�����̴�.
			//x->y �̹Ƿ� 2*x -> 2*y+1
			adj[2*x].push_back(2*y+1);
		}
		int ans=0;
		for(int i=0;i<n;i++){
			memset(visited,0,sizeof(visited));
			if(dfs(2*i)) ans++;
		}
		printf("%d\n",ans);
		for(int i=0;i<n;i++){
			adj[2*i].clear();
			adj[2*i+1].clear();
		}
	}
	return 0;
}