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
/*dp[i][j]: i���� i������ dfs���������� �ʿ��� �ּ� �󸮾���� ��
j=0: i�� �󸮾����x, j=1: i�� �󸮾����*/
int dp[1000001][2];

int sns(int here,int before,int ch){
	int &ret=dp[here][ch];
	if(ret!=-1) return ret;
	/*here������ �󸮾���Ϳ� ����*/
	if(ch==1){
		ret=1;
		/*���� ������ �󸮾���Ϳ��� �ǰ� �ƴϿ��� �ȴ�*/
		for(int ele:adj[here]){
			if(ele!=before){
				ret+=min(sns(ele,here,1),sns(ele,here,0));
			}
		}
	}
	/*here������ �󸮾���Ϳ� ���� ���� ����*/
	else{
		ret=0;
		/*here�� ����Ǿ� �ִ� ��� ģ��(�� �� ģ�� ����)�� �󸮾���;� ��*/
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
	//1���� root�� ����
	cout<<min(sns(1,0,0),sns(1,0,1));
	return 0;
}