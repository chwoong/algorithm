#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

vector<int> adj[1000001];
/*dp[i][j]: i포함 i부터의 dfs과정에서의 필요한 최소 얼리어답터 수
j=0: i는 얼리어답터x, j=1: i는 얼리어답터*/
int dp[1000001][2];

int sns(int here,int before,int ch){
	int &ret=dp[here][ch];
	if(ret!=-1) return ret;
	/*here정점을 얼리어답터에 포함*/
	if(ch==1){
		ret=1;
		/*다음 정점은 얼리어답터여도 되고 아니여도 된다*/
		for(int ele:adj[here]){
			if(ele!=before){
				ret+=min(sns(ele,here,1),sns(ele,here,0));
			}
		}
	}
	/*here정점을 얼리어답터에 포함 하지 않음*/
	else{
		ret=0;
		/*here과 연결되어 있는 모든 친구(그 전 친구 제외)는 얼리어답터야 함*/
		for(int ele:adj[here]){
			if(ele!=before){
				ret+=sns(ele,here,1);
			}
		}
	}
	return ret;
}

int main(){
	int n;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//1번을 root로 하자
	cout<<min(sns(1,0,0),sns(1,0,1));
	return 0;
}