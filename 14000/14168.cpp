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

typedef pair<long long,long long> P;
int h,g;
P point[5010];

//dp[i][j][k]: h는 i번째까지 지나갔고, g는 j번째까지 지나감
//앞으로 필요한 에너지 반환
//k=0: h, k=1: g 에서 시작
long long dp[1010][1010][2];

long long f(int i,int j){
	return (point[i].first-point[j].first)*(point[i].first-point[j].first)+(point[i].second-point[j].second)*(point[i].second-point[j].second);
}

long long solve(int i,int j,int k){
	long long &ret=dp[i][j][k];
	if(ret!=-1ll) return ret;
	ret=0;
	if(k==0){
		if(i==h){
			ret=0;
		}else if(i==h-1){
			if(j==g) ret=f(i,i+1)+solve(i+1,j,0); 
			else ret=solve(i,j+1,1)+f(i,2000+j+1);
		}else{
			if(j==g) ret=solve(i+1,j,0)+f(i,i+1);
			else ret=min(solve(i,j+1,1)+f(i,2000+j+1),solve(i+1,j,0)+f(i,i+1));
		}
	}else{
		if(j==g){
			ret=f(i+1,2000+j)+solve(i+1,j,0);
		}else{
			if(i==h-1){
				ret=f(2000+j,2000+j+1)+solve(i,j+1,1);
			}else{
				ret=min(solve(i+1,j,0)+f(i+1,2000+j),solve(i,j+1,1)+f(2000+j,2000+j+1));
			}
		}
	}
	return ret;
}

int main(){
	cin>>h>>g;
	memset(dp,-1ll,sizeof(dp));
	for(int i=1;i<=h;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		point[i]=P(a,b);
	}
	for(int i=1;i<=g;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		point[i+2000]=P(a,b);
	}
	cout<<solve(1,0,0);
	return 0;
}