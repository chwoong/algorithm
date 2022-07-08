#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;
int N;
int people[10001];
vector<vector<int>> adj;
/* dp[i][x]: i�� ����(���)�� ��Ʈ�� ����Ʈ���� ������ ������� �ֹ� �� �� 
�� �� x=0: i�� ���� ���� ����
x=1: i�� ���� ������
*/
int dp[10001][2];
/* curr�� �����ϴ� dfs, dp[curr]�� ��ȯ
ch=0: curr���� ����
ch=1: curr������ 
*/
int dfs(int curr,int from, int ch){
	if(ch==0){
		int& ret0= dp[curr][0];
		if(ret0!=-1) return ret0;
		ret0=0;
		for(int next:adj[curr]){
			if(next!=from) {ret0+=max(dfs(next,curr,0),dfs(next,curr,1));}
		}
		return ret0;
	}
	if(ch==1){
		int& ret1= dp[curr][1];
		if(ret1 !=-1) return ret1;
		ret1=people[curr];
		for(int next:adj[curr]){
			if(next!=from) {ret1+=dfs(next,curr,0);}
		}
		return ret1;
	}
}


int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		scanf("%d",people+i);
	}
	adj.reserve(N+1);
	memset(&dp[0][0],-1,sizeof(dp));
	int u,v;
	for(int i=0;i<N-1;i++){
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << max(dfs(1,0,0),dfs(1,0,1));
	return 0;
}