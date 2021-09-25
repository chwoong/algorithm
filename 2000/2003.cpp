#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
#include<cmath>
using namespace std;

int arr[10000];
int main(){
	long long n,m;
	cin>>n>>m;
	int ans=0;
	//start, finish
	//arr[s]~arr[f-1]까지의 합을 저장한다
	int s=0,f=0;
	long long sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	while(1){
		if(sum>=m) sum-=arr[s++];
		else if(f==n) break;
		else if(sum<m) sum+=arr[f++];
		if(sum==m) ans++;	
	}
	cout<<ans;
	return 0;
}