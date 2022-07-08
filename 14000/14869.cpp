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
using namespace std;

#define INF 1000000000
int n,m,s,e,t;
//cost[i][j]: �п� i���� ���� j�� ���� �� ����
int cost[3001][3001];
//sum[i][j]: �п� i���� ���� 1~j���� ���� �� ����
int sum[3001][3001];
//dp[i][j]: ���ݱ��� ���� i���� �����߰� ������ �п��� j�� ���
int dp[3001][3001];
//notacc[i][j]: i������ ���� �� ���� ����.
bool notacc[3001][3001];

int solve(int i,int j){
	int& ret=dp[i][j];
	if(ret!=-1) return ret;
	if(i==m) return ret=0;
	ret=INF;
	for(int a=1;a<=n;a++){
		//�п� a�� �ű�
		if(!notacc[j][a]){
			//���¸� �ּ� min(s,m-i) ��ŭ ���� �� �ְ� �ִ� min(e,m-i)��ŭ ���� �� �ִ�.
			int x=min(s,m-i)+i;
			int y=min(e,m-i)+i;
			for(int k=x;k<=y;k++){
				int tmp;
				if(i==0) tmp=(sum[a][k]-sum[a][i])+solve(k,a);
				else tmp=t+(sum[a][k]-sum[a][i])+solve(k,a);
				ret=min(ret,tmp);
			}
		}
	}
	return ret;
}

int main(){
	cin>>n>>m>>s>>e>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&cost[i][j]);
			sum[i][j]=sum[i][j-1]+cost[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		notacc[x][i]=true;
		notacc[i][i]=true;
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0);
	return 0;
}