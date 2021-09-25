/*
 *  author: chw0501
 *  reference: 
 *  created: 02.05.2020 06:41:33(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n,k;
string arr[15];
int len[15];
int a[15];
//ten[i]: 10^i 의 k로 나눈 나머지
int ten[51];
ll dp[1<<15][110];

ll gcd(ll p,ll q){
	if(p>q) swap(p,q);
	if(p==0) return q;
	return gcd(q%p,p);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		len[i]=arr[i].size();
	}
	cin>>k;
	ten[0]=1%k;
	for(int i=1;i<=50;i++){
		ten[i]=(ten[i-1]*10)%k;
	}
	//arr[i]의 k로 나눈 나머지 a[i]
	for(int i=0;i<n;i++){
		for(int j=0;j<len[i];j++){
			a[i]=(a[i]+ten[j]*(arr[i][len[i]-1-j]-'0'))%k;
		}
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i&(1<<j))==0){
				for(int p=0;p<k;p++){
					int v=(p*ten[len[j]])%k;
					v=(v+a[j])%k;
					dp[i|(1<<j)][v]+=dp[i][p];
				}
			}
		}
	}
	ll p=dp[(1<<n)-1][0];
	ll q=1;
	for(ll i=2;i<=n;i++) q=q*i;
	if(p==0){
		printf("0/1");
	}else{
		ll g=gcd(p,q);
		printf("%lld/%lld",p/g,q/g);
	}
	return 0;
}