#include <iostream>
#include <string.h>

using namespace std;

int N;
/* dp[n][i]: n줄까지 벽돌이 있고, 마지막 열의 상태가 i  
i=0:꽉 차있음 
i=1:하나만 삐져나와 있음
*/
int dp[30][2];

int tiling(int n,int i){
	/* base cases */
	int &ret= dp[n][i];
	if(ret!=-1) return ret;
	if(i==0){
		ret = 3*tiling(n-2,0)+2*tiling(n-2,1);
	}else{
		ret = tiling(n-2,0)+tiling(n-2,1);
	}
	return ret;
}

int main(){
	cin >> N;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	dp[1][0]=3;
	dp[1][1]=1;
	cout<< tiling(N-1,0);
	return 0;
}