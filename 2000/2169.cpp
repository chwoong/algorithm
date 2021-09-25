/*
 *  author: chw0501
 *  reference: 
 *  created: 28.12.2020 06:44:45(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321

int n, m;
ll terr[1000][1000];
//마지막에 왼쪽에서 오면 0, 위에서 오면 1, 오른쪽에서 오면 2, (i, j) 포함한 가치 누적
ll dp[3][1000][1000];


int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%lld", &terr[i][j]);
		}
	}
	dp[0][0][0] = terr[0][0];
	dp[1][0][0] = terr[0][0];
	dp[2][0][0] = -INF;
	for(int i = 0; i < n; i++){
		if(i != 0){
			dp[0][i][0] = -INF;
		}
		dp[2][i][m-1] = -INF;
		for(int j = 0; j < m; j++){
			if(i == 0){
				dp[1][i][j] = -INF;
				dp[1][0][0] = terr[0][0];
			}else{
				dp[1][i][j] = max(max(dp[0][i-1][j], dp[1][i-1][j]), dp[2][i-1][j]) + terr[i][j];
			}
		}
		for(int j = 1; j < m; j++){
			dp[0][i][j] = max(dp[0][i][j-1], dp[1][i][j-1]) + terr[i][j];
		}
		for(int j = m - 2; j >= 0; j--){
			if(i == 0){
				dp[2][i][j] = -INF;
			}else{
				dp[2][i][j] = max(dp[2][i][j+1], dp[1][i][j+1]) + terr[i][j];	
			}
		}
	}
	printf("%lld", max(dp[0][n-1][m-1], dp[1][n-1][m-1]));
	return 0;
}