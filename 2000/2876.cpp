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
using namespace std;

int n;
int arr[200000];
int dp[100001][6];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",arr+2*i,arr+2*i+1);
	}
	for(int i=1;i<=n;i++){
		dp[i][arr[(i-1)*2]]=dp[i-1][arr[(i-1)*2]]+1;
		dp[i][arr[(i-1)*2+1]]=dp[i-1][arr[(i-1)*2+1]]+1;
	}
	int m=0;
	int k=1;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=n;j++){
			if(m<dp[j][i]) {m=dp[j][i]; k=i;}
		}
	}
	cout<<m<<' '<<k;
	return 0;
}