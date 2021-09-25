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
int a[3][150000];
//dp[i][j][k]: i~(n-1)까지 문제 중에 이분할 할건데 k가 j보다 문제 푼 순서가 앞에 있어야 함
int dp[150000][3][3];

//psum[x][i]: x사람의 0..i-1까지의 합
int psum[3][150010];

int main(){
	cin>>n;
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			psum[i][j+1]=psum[i][j]+a[i][j];
		}
	}
	int ans=1000000;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			//j가 앞의 문제 푼다.
			if(i!=j){
				int t;
				for(t=0;t<3;t++){
					if(t!=i && t!=j) break;
				}
				dp[n-2][i][j]=a[j][n-2]+a[i][n-1];
				ans=min(ans,dp[n-2][i][j]+psum[t][n-2]);
				for(int k=n-3;k>=1;k--){
					dp[k][i][j]=min(dp[k+1][i][j]+a[j][k],(psum[i][n]-psum[i][k+1])+a[j][k]);
					ans=min(ans,dp[k][i][j]+psum[t][k]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}