#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>
using namespace std;

long long n,s;
int arr[100000];
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	int p=0,e=0;
	int ans=100001;
	long long sum=0;
	while(1){
		if(sum>=s) sum-=arr[p++];
		else if(e==n) break;
		else if(sum<s) sum+=arr[e++];
		if(sum>=s) ans=min(ans,e-p);
	}
	printf("%d",ans==100001?0:ans);
	return 0;
}