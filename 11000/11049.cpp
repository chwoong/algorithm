/*
 *  author: chw0501
 *  reference: 
 *  created: 18.04.2020 12:08:55(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define INF 2147483647
int n;
int f[500];
int b[500];
//dp[i][j]: i~j까지의 행렬을 곱하는 최소 연산 횟수
int dp[500][500];

int solve(int i,int j){
	int&ret=dp[i][j];
	if(ret!=-1) return ret;
	if(i==j) return ret=0;
	if(i+1==j) return ret=f[i]*b[i]*b[j];
	ret=INF;
	for(int k=i;k<j;k++){
		ret=min(ret,solve(i,k)+solve(k+1,j)+f[i]*b[k]*b[j]);
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",f+i,b+i);
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,n-1);
	return 0;
}