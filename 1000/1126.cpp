/*
 *  author: chw0501
 *  reference: https://blog.encrypted.gg/476
 *  created: 02.05.2020 02:33:06(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

//dp[i][j]: i��° ��ϱ��� ���� �� ���� ���� j�� ���� Ÿ�� 2�� �� �ִ� ����
int dp[51][500001];
int n;
int arr[51];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][arr[i]]=arr[i];
		for(int j=0;j<=500000;j++){
			if(dp[i-1][j]==-1) continue;
			if(j+arr[i]<=500000)
				dp[i][j+arr[i]]=max(dp[i][j+arr[i]],dp[i-1][j]+arr[i]);
			if(j<arr[i]) dp[i][abs(j-arr[i])]=max(dp[i][abs(j-arr[i])],dp[i-1][j]-j+arr[i]);
			else dp[i][abs(j-arr[i])]=max(dp[i][abs(j-arr[i])],dp[i-1][j]);
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
	}
	if(dp[n][0]==0) puts("-1");
	else printf("%d",dp[n][0]);
	return 0;
}