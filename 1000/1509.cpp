/*
 *  author: chw0501
 *  reference: 
 *  created: 02.05.2020 06:15:23(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define MOD 1000000007 
#define INF 987654321 

string s;
//dp[i][j]: s[i]~s[j] 펠린드롬인가?
bool dp[2500][2500];
//dp2[i]: s[i]~ 의 분할 개수 최솟값 출력
int dp2[2501];
int len;

int solve(int i){
	int&ret=dp2[i];
	if(ret!=-1) return ret;
	if(i==len) return ret=0;
	ret=2500;
	if(dp[i][len-1]) return ret=1;
	for(int j=i;j<len;j++){
		if(dp[i][j]) ret=min(ret,1+solve(j+1));
	}
	return ret;
}

int main(){
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		dp[i][i]=true;
	}
	for(int i=0;i<len-1;i++){
		if(s[i]==s[i+1]) dp[i][i+1]=true;
	}
	//길이 l의 펠린드롬이 가능한지 확인
	for(int l=3;l<=len;l++){
		for(int i=0;i<=len-l;i++){
			if(dp[i+1][i+l-2] && s[i]==s[i+l-1]) dp[i][i+l-1]=true;
		}
	}
	memset(dp2,-1,sizeof(dp2));
	cout<<solve(0);
	return 0;
}