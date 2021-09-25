/*
 *  author: chw0501
 *  reference: 
 *  created: 02.05.2020 05:19:11(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

int n,l,r;
//dp[i][j][k]: i개, 왼쪽보이는 개수 j, 오른쪽 보이는 개수 k개
ll dp[101][101][101];
ll comb[210][210];

ll solve(int i,int j,int k){
	ll&ret=dp[i][j][k];
	if(ret!=-1ll) return ret;
	if(j==0 || i==0 || k==0) return ret=0;
	if(i<j+k-1) return ret=0;
	if(i==j+k-1) return ret=comb[i-1][j-1];
	//i-1개의 빌딩이 세워져 있을 때 모든 빌딩의 높이를 1씩 증가시키고 높이 1짜리 빌딩을 끼워놓자
	//양쪽에 끼워 넣을 때
	ret=(solve(i-1,j-1,k)+solve(i-1,j,k-1))%MOD;
	//사이에 끼워 넣을 때
	ret=(ret+(solve(i-1,j,k)*(ll)(i-2))%MOD)%MOD;
	return ret;
}

int main(){
	cin>>n>>l>>r;
	comb[1][0]=1;
	comb[1][1]=1;
	for(int i=2;i<=200;i++){
		comb[i][0]=1;
		for(int j=1;j<i;j++){
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
		}
		comb[i][i]=1;
	}
	memset(dp,-1ll,sizeof(dp));
	dp[1][1][1]=1;
	dp[2][1][1]=0;
	dp[2][1][2]=1;
	dp[2][2][1]=1;
	cout<<solve(n,l,r);
	
	return 0;
}