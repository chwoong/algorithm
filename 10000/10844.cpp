#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
using namespace std;

#define MOD 1000000000
/*전 숫자, 남은 숫자 개수*/
long long dp[10][100];

/*바로 앞 숫자, 앞으로 남은 숫자 n*/
long long solve(int prev,int n){
	long long& ret= dp[prev][n];
	if(ret!=-(long long)1) return ret;
	if(n==0) return ret=1;
	if(prev==0) return ret=solve(1,n-1);
	if(prev==9) return ret=solve(8,n-1);
	return ret=(solve(prev-1,n-1)+solve(prev+1,n-1))%MOD;
}

int main(){
	int n;
	cin>>n;
	memset(dp,-(long long)1,sizeof(dp));
	long long ans=0;
	for(int i=1;i<=9;i++)
		ans=(ans+solve(i,n-1))%MOD;
	cout<<ans;
	return 0;
}