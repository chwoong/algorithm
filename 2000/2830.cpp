#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

long long arr[21];

int main(){
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		int cnt=0;
		while(x>0){
			if(x&1==1) arr[cnt]++;
			x>>=1;
			cnt++;
		}
	}
	long long ans=0;
	for(int i=0;i<=20;i++){
		long long val=1<<i;
		val*=(arr[i]*(n-arr[i]));
		ans+=val;
	}
	cout<<ans;
	return 0;
}