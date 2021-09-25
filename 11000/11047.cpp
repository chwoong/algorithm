#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
using namespace std;

long long n,k;
long long coin[11];

int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%lld",coin+i);
	int ans=0;
	while(k){
		ans+=(k/coin[n]);
		k%=coin[n];
		n--;
	}
	cout<<ans;
	return 0;
}