#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int n;
int col[1001][3];
/*dp[i]: i번째 집부터 쭉 채울 때 최소 비용
이 때 i번째 집을 칠하는 색은
0: r
1: g
2: b
*/
int dp[1001][3];

int solve(int i,int color){
	int& ret=dp[i][color];
	if(ret!=-1) return ret;
	if(color==0) ret=min(solve(i+1,1),solve(i+1,2))+col[i][0];
	else if(color==1)	ret=min(solve(i+1,0),solve(i+1,2))+col[i][1];
	else	ret=min(solve(i+1,0),solve(i+1,1))+col[i][2];
	return ret;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&col[i][0],&col[i][1],&col[i][2]);
	}
	memset(dp,-1,sizeof(dp));
	cout<< min(min(solve(1,0),solve(1,1)),solve(1,2));
	
	return 0;
}