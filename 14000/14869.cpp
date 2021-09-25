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
//cost[i][j]: 학원 i에서 강좌 j를 들을 때 가격
int cost[3001][3001];
//sum[i][j]: 학원 i에서 강좌 1~j까지 들을 때 가격
int sum[3001][3001];
//dp[i][j]: 지금까지 강좌 i까지 수강했고 마지막 학원이 j인 경우
int dp[3001][3001];
//notacc[i][j]: i다음에 나올 수 없는 숫자.
bool notacc[3001][3001];

int solve(int i,int j){
	int& ret=dp[i][j];
	if(ret!=-1) return ret;
	if(i==m) return ret=0;
	ret=INF;
	for(int a=1;a<=n;a++){
		//학원 a로 옮김
		if(!notacc[j][a]){
			//강좌를 최소 min(s,m-i) 만큼 들을 수 있고 최대 min(e,m-i)만큼 들을 수 있다.
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