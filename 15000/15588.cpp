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

#define MOD 1000000007
long long n,m,k;
//dp[i]: iÄ­ Áß k°³ÀÇ ¿¬¼Ó Ä­ ¾ø´Â °¡Áþ¼ö
long long dp[1000001];
long long solve(int n){
	long long& ret=dp[n];
	if(ret!=-1ll) return ret;
	return ret=(MOD+(solve(n-1)*m)%MOD-(solve(n-k)*(m-1))%MOD)%MOD;
}

int main(){
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<k;i++){
		dp[i]=(dp[i-1]*m)%MOD;
	}
	dp[k]=(dp[k-1]*m-m)%MOD;
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*m)%MOD;
	}
	printf("%lld",(MOD+ans-solve(n))%MOD);
	return 0;
}