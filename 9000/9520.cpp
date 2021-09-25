#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define INF 10000000
//dp[i][j]: 맨 왼쪽이 i이고 오른쪽이 j(1,2..j까지 숫자 사용) 일 때 최솟값
int dp[1501][1501];
int n;
int dist[1501][1501];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&dist[i][j]);
		}
	}
	dp[1][2]=dist[1][2];
	for(int i=3;i<=n;i++){
		int tmp=INF;
		for(int j=1;j<=i-2;j++){
			dp[j][i]=dp[j][i-1]+dist[i-1][i];
		}
		tmp=INF;
		for(int j=1;j<=i-2;j++){
			tmp=min(tmp,dp[j][i-1]+dist[j][i]);
		}
		dp[i-1][i]=tmp;
	}
	int ans=INF;
	for(int i=1;i<=n-1;i++){
		ans=min(ans,dp[i][n]);
	}
	ans=min(ans,dp[n-1][n]);
	cout<<ans;
	return 0;
}