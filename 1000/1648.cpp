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
/*ĭ �ѹ���
0 1 2
3 4 5
6 7 8
*/
/*���� Ȯ���ؾ��ϴ� ĭ�� cĭ, c~(c+m-1)������ Ÿ�� ä���� �ִ� ���� b*/
int solve(int c,int b){
	int & ret=dp[c][b];
	if(ret!=-1) return ret;
	if(c==n*m) return ret=(b==0);
	if(c>n*m) return 0;
	ret=0;
	/*����ĭ�� ĥ���� �ִ� �� Ȯ��*/
	if(b&1) ret=solve(c+1,b>>1);
	else{
		/*���η� ��� ���*/
		ret=solve(c+1,(b>>1)|(1<<(m-1)));
		/*���η� ��� ���*/
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