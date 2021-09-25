/*
 *  author: chw0501
 *  created: 18.04.2020 02:21:08(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define MOD 1000000007

//fac[i]: i!의 mod 값 저장
ll fac[4000001];
//inv[i]: 1/i의 mod값 저장
ll inv[4000001];
//invfac[i]: 1/(i!)의 mod값 저장
ll invfac[4000001];
int n,k;

int main(){
	cin>>n>>k;
	if(k==0 || n==k){
		puts("1");
		return 0;
	}
	fac[1]=1;
	for(ll i=2;i<=n;i++){
		fac[i]=(fac[i-1]*i)%MOD;
	}
	inv[1]=1;
	for(ll i=2;i<=n;i++){
		inv[i]=(MOD-((MOD/i)*inv[MOD%i])%MOD)%MOD;
	}
	invfac[1]=1;
	for(ll i=2;i<=n;i++){
		invfac[i]=(invfac[i-1]*inv[i])%MOD;
	}
	ll ans=(fac[n]*invfac[k])%MOD;
	ans=(ans*invfac[n-k])%MOD;
	printf("%lld",ans);
	return 0;
}