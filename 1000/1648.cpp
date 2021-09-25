/*
 *  author: chw0501
 *  reference: https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1648 
 *  created: 18.04.2020 05:51:00(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define MOD 9901

int n,m;

int dp[300][1<<14];
/*칸 넘버링
0 1 2
3 4 5
6 7 8
*/
/*현재 확인해야하는 칸이 c칸, c~(c+m-1)까지의 타일 채워져 있는 정보 b*/
int solve(int c,int b){
	int & ret=dp[c][b];
	if(ret!=-1) return ret;
	if(c==n*m) return ret=(b==0);
	if(c>n*m) return 0;
	ret=0;
	/*현재칸이 칠해져 있는 지 확인*/
	if(b&1) ret=solve(c+1,b>>1);
	else{
		/*세로로 까는 경우*/
		ret=solve(c+1,(b>>1)|(1<<(m-1)));
		/*가로로 까는 경우*/
		if((c%m)!=m-1 && (b&2)==0){
			ret=(ret+solve(c+2,b>>2))%MOD;
		}
	}
	return ret;
}

int main(){
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0);
	return 0;
} 