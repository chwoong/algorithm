#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
using namespace std;

int N;
int a[2000];
int b[2000];

//dp[i][j]: 왼쪽이 i개 남고 오른쪽이 j개 남았을 때 얻을 수 있는 최대 점수
int dp[2001][2001];

int solve(int i,int j){
	//a[N-i]와 b[N-j]의 비교
	int& ret=dp[i][j];
	if(ret!=-1) return ret;
	if(i==0 || j==0) return 0;
	ret=0;
	int x=a[N-i];
	int y=b[N-j];
	if(x>y) ret=max(ret,y+solve(i,j-1));
	ret=max(ret,solve(i-1,j-1));
	ret=max(ret,solve(i-1,j));
	return ret;
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		scanf("%d",a+i);
	}
	for(int i=0;i<N;i++){
		scanf("%d",b+i);
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(N,N);
	return 0;
}