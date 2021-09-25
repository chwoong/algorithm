/*
 *  author: chw0501
 *  reference: 
 *  created: 26.12.2020 06:21:42(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 


int seq[100001];
int n = 0;
int dp[5][5][100001];
//(l,r)에 발이 올려져 있고 이제 k번째 입력부터 옮길때 필요한 최소 힘
int solve(int l, int r, int k){
	int& ret = dp[l][r][k];
	if(k == n - 1) return 0;
	if(ret != -1) return ret;
	if(seq[k] == l || seq[k] == r) return ret = 1 + solve(l, r, k + 1);
	ret = INF;
	// l을 seq[k]로 옮김
	if(l == 0) ret = min(ret, 2 + solve(seq[k], r, k + 1));
	int p, m;
	p = l + 1 == 5? 1: l + 1;
	m = l - 1 == 0? 4: l - 1;
	if(p == seq[k] || m == seq[k]) ret = min(ret, 3 + solve(seq[k], r, k + 1));
	else ret = min(ret, 4 + solve(seq[k], r, k + 1));
	// r을 k로 옮김
	if(r == 0) ret = min(ret, 2 + solve(l, seq[k], k + 1));
	p = r + 1 == 5? 1: r + 1;
	m = r - 1 == 0? 4: r - 1;
	if(p == seq[k] || m == seq[k]) ret = min(ret, 3 + solve(l, seq[k], k + 1));
	else ret = min(ret, 4 + solve(l, seq[k], k + 1));
	return ret;
}
int main(){
	while(scanf("%d",seq+n) != EOF && ++n);
	memset(dp, -1, sizeof(dp));
	printf("%d", solve(0, 0, 0));
	return 0;
}