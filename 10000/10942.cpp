/*
 *  author: chw0501
 *  reference: 
 *  created: 02.05.2020 05:59:20(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n,m;
//dp[i][j]: arr[i]~arr[j]가 펠린드롬인가
bool dp[2001][2001];
int arr[2001];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",arr+i);
	for(int i=1;i<=n;i++){
		dp[i][i]=true;
	}
	for(int i=1;i<n;i++){
		if(arr[i]==arr[i+1]) dp[i][i+1]=true;
	}
	//길이 l의 펠린드롬이 가능한지 확인
	for(int l=3;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			if(dp[i+1][i+l-2] && arr[i]==arr[i+l-1]) dp[i][i+l-1]=true;
		}
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[a][b]?1:0);
	}
	return 0;
}