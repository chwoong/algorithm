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

/* dp[i]: i�� ������ i~�� ������ �� �ִ� */
/* �׷��� dp�� �ݺ������� �ذ��� ��� i�� 2������ �ʿ��� */
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