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

long long in_ex[7]={1,-1ll,1,-1ll,1,-1ll,1};
long long MAX=5000000000ll;
long long k;
set<long long> s[8];
//32000이하의 소수 저장
//3432개
bool p[50000];
vector<int> prime;
//소수의 제곱 저장
vector<long long> sqprime;
long long pi=1ll;
void solve(int x,int n){
	for(int i=x;i<4500;i++){
		pi*=sqprime[i];
		if(pi<MAX){
			s[n].insert(pi);
			if(n!=7) solve(i+1,n+1);
			pi/=sqprime[i];
		}else {
			pi/=sqprime[i];
			break;
		}
	}
}
int main(){
	cin>>k;
	for(long long i=2;i<50000;i++){
		if(!p[i]){
			prime.push_back(i);
			for(long long j=i*i;j<50000;j+=i){
				p[j]=true;
			}
		}
	}
	for(long long ele:prime)
		sqprime.push_back(ele*ele);
	solve(0,1);
	long long l=1;
	long long h=2ll*k;
	while(l+1<h){
		long long mid=(l+h)/2;
		long long val=mid;
		for(int i=1;i<8;i++){
			for(set<long long>::iterator it=s[i].begin();it!=s[i].end();it++){
				if((*it)>mid) break;
				val-=(in_ex[i-1]*(mid/(*it)));
			}
		}
		if(val>k) h=mid;
		else l=mid;
	}
	for(int i=0;i<3432;i++){
		if(l%sqprime[i]==0) {l--; i=-1;}
	}
	cout<<l;
	return 0;
}