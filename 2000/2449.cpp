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
#include <cstdio>
#include <fstream>
using namespace std;

int n,k;

int arr[200];
//dp[i][j]: i~j까지의 전구를 arr[i]로 바꾸는데 걸리는 횟수
//맨앞에 있는 전구 색깔로 바꾸기로 해도 최솟값은 그대로이다.
int dp[200][200];

int solve(int i,int j){
	int &ret = dp[i][j];
	if(ret!=-1) return ret;
	if(i==j) return ret=0;
	ret=500;
	for(int k=i; k<j; k++){
		int tmp=(arr[i]!=arr[k+1]? 1:0);
		ret=min(ret,solve(i,k)+solve(k+1,j)+tmp);
	}
	return ret;
}

int main(){
	cin>>n>>k;
	memset(dp,-1,sizeof(dp));
	for(int i=0 ; i<n ; i++){
		scanf("%d",arr+i);
	}
	cout<<solve(0,n-1);
	return 0;
}