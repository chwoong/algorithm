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

/* dp[i]: i를 포함한 i~의 연속합 중 최대 */
/* 그런데 dp를 반복문으로 해결할 경우 i는 2가지만 필요함 */
int dp[2];
int arr[100001];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d ",arr+i);
	dp[0]=dp[1]=arr[n];
	int tmp=arr[n];
	for(int i=n-1;i>=1;i--){
		dp[i%2]=max(dp[(i+1)%2]+arr[i],arr[i]);
		tmp=max(tmp,dp[i%2]);
	}
	cout<<tmp;
	return 0;
}