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

int dp[2][3];
int dp2[2][3];
int main(){
	int n;
	cin>>n;
	scanf("%d %d %d",&dp[0][0],&dp[0][1],&dp[0][2]);
	dp2[0][0]=dp[0][0];
	dp2[0][1]=dp[0][1];
	dp2[0][2]=dp[0][2];
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dp[(i+1)%2][0]=max(dp[i%2][0],dp[i%2][1])+a;
		dp[(i+1)%2][1]=max(max(dp[i%2][0],dp[i%2][1]),dp[i%2][2])+b;
		dp[(i+1)%2][2]=max(dp[i%2][1],dp[i%2][2])+c;
		dp2[(i+1)%2][0]=min(dp2[i%2][0],dp2[i%2][1])+a;
		dp2[(i+1)%2][1]=min(min(dp2[i%2][0],dp2[i%2][1]),dp2[i%2][2])+b;
		dp2[(i+1)%2][2]=min(dp2[i%2][1],dp2[i%2][2])+c;
	}
	cout<<max(max(dp[(n-1)%2][0],dp[(n-1)%2][1]),dp[(n-1)%2][2])<<" ";
	cout<<min(min(dp2[(n-1)%2][0],dp2[(n-1)%2][1]),dp2[(n-1)%2][2]);
	return 0;
}