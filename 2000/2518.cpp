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

#define INF 1000000000
int n;
//1, n/3+1, 2*n/3+1 
//dp[i][j][k]: 각 사람마다 i,j,k번째까지 먹은 상황이고 마지막 먹은 사람이 p인 상황일 때 
//앞으로 남은 최소 회전수
int dp[110][110][110][4];
int l[5];
int x[5][102];

//i만큼 왼쪽으로 돌아가 있고 원하는 번호는 j,원하는 사람이 p일 때 회전수	
int f(int i,int j,int p){
	int v=1+p*n/3;
	int y=(n+j+i)%n;
	if(y==0) y=n;
	return min(abs(v-y),n-abs(v-y));
}

int solve(int i,int j,int k,int p){
	int &ret=dp[i][j][k][p];
	if(ret!=-1) return ret;
	ret=INF;
	if(i==l[0] && j==l[1] && k==l[2]) ret=0;
	//왼쪽으로 돌아간 거리
	int v;
	if(p==0) {v=x[p][i];v-=1;v=n-v;}
	if(p==1) {v=x[p][j];v-=(1+n/3);v=n-v;}
	if(p==2) {v=x[p][k];v-=(1+2*n/3);v=n-v;}
	//그 다음 사람
	
	for(int q=0;q<3;q++){
		if(q==0 && l[q]==i) continue;
		if(q==1 && l[q]==j) continue;
		if(q==2 && l[q]==k) continue;
		if(q==0) ret=min(ret,f(v,x[0][i+1],0)+solve(i+1,j,k,q));
		if(q==1) ret=min(ret,f(v,x[1][j+1],1)+solve(i,j+1,k,q));
		if(q==2) ret=min(ret,f(v,x[2][k+1],2)+solve(i,j,k+1,q));
	}
	
	return ret;
}

int main(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<3;i++){
		scanf("%d",l+i);
		for(int j=1;j<=l[i];j++){
			scanf("%d",&x[i][j]);
		}
	}
	int ans=INF;
	ans=min(ans,f(0,x[0][1],0)+solve(1,0,0,0));
	ans=min(ans,f(0,x[1][1],1)+solve(0,1,0,1));
	ans=min(ans,f(0,x[2][1],2)+solve(0,0,1,2));
	cout<<ans;
	return 0;
}