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

long long n,m;
long long arr[100000];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%lld",arr+i);
	sort(arr,arr+n);
	int s=0,e=0;
	//시작은 arr[s=0]과 arr[e=0]의 차이
	long long diff=0;
	long long ans=2000000000;
	while(1){
		if(diff>=m) diff=(diff+arr[s]-arr[++s]);
		else if(e==n) break;
		else if(diff<m) diff=(diff-arr[e]+arr[++e]);
		if(diff>=m) ans=min(ans,diff);
	}
	cout<<ans;
	return 0;
}