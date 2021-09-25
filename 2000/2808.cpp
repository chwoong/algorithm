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
#include<time.h>
using namespace std;

int n;
int m[300001];
double dp[300001][2];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",m+i);
	}
	long long sum=0;
	double ans=0;
	
	for(int i=n-1;i>=1;i--){
		double x=(double)(2*sum+m[i])/(double)(sum+m[i]);
		sum+=m[i];
		dp[i][1]=max(dp[i+1][0]+2.0-x, dp[i+1][1]+2.0-x);
		dp[i][0]=x;
	}
	printf("%.6f",max(dp[1][0],dp[1][1]));
	return 0;
}