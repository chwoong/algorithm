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
using namespace std;

#define INF 2000000000000
int n,num;
long long dp[1001][1001][10];
long long m[1001][3];

long long solve(int i,int k,int state){
	if(k<0) return -(long long)INF;
	long long& ret=dp[i][k][state];
	if(ret!=-(long long)1) return ret;
	//base case
	if(k==0) return ret=0;
	if(i==0 && k>0) return ret=-(long long)INF;
	if(i==1 && (state==1 || state==2 ||state==4 ||state==5) &&k>0) return ret=-(long long)INF;
	if(i==1 && state==3){
		if(k>=2) return ret=-(long long)INF;
		else return ret=m[n-1][1]+m[n-1][2];
	}
	if(i==1 && state==6){
		if(k>=2) return ret=-(long long)INF;
		else return ret=m[n-1][0]+m[n-1][1];
	}
	if(i==1 && state==7){
		if(k>=2) return ret=-(long long)INF;
		else return ret=max(m[n-1][1]+m[n-1][2],m[n-1][0]+m[n-1][1]);
	}
	//call
	switch(state){
		case 1:
			return ret=max(m[n-i][2]+m[n-i+1][2]+solve(i-1,k-1,6),solve(i-1,k,7));
			
		case 2:
			return ret=max(m[n-i][1]+m[n-i+1][1]+solve(i-1,k-1,5),solve(i-1,k,7));
			
		case 3:
			ret=max(m[n-i][1]+m[n-i][2]+solve(i-1,k-1,7),max(m[n-i][1]+m[n-i+1][1]+solve(i-1,k-1,5),m[n-i][2]+m[n-i+1][2]+solve(i-1,k-1,6)));
			ret=ret=max(ret,solve(i-1,k,7));
			return ret;
		case 4:
			return ret=max(m[n-i][0]+m[n-i+1][0]+solve(i-1,k-1,3),solve(i-1,k,7));
			
		case 5:
			return ret=max(max(m[n-i][0]+m[n-i+1][0]+solve(i-1,k-1,3),m[n-i][2]+m[n-i+1][2]+solve(i-1,k-1,6)),max(m[n-i][0]+m[n-i+1][0]+m[n-i][2]+m[n-i+1][2]+solve(i-1,k-2,2),solve(i-1,k,7)));
			
		case 6:
			ret=max(m[n-i][0]+m[n-i][1]+solve(i-1,k-1,7),max(m[n-i][0]+m[n-i+1][0]+solve(i-1,k-1,3),m[n-i][1]+m[n-i+1][1]+solve(i-1,k-1,5)));
			ret=max(ret,solve(i-1,k,7));
			return ret;
			
		case 7:
			ret=m[n-i][0]+m[n-i][1]+solve(i,k-1,1);
			ret=max(ret,m[n-i][1]+m[n-i][2]+solve(i,k-1,4));
			ret=max(ret,solve(i-1,k,7));
			ret=max(ret,m[n-i][0]+m[n-i+1][0]+solve(i-1,k-1,3));
			ret=max(ret,m[n-i][2]+m[n-i+1][2]+solve(i-1,k-1,6));
			ret=max(ret,m[n-i][0]+m[n-i+1][0]+m[n-i][2]+m[n-i+1][2]+solve(i-1,k-2,2));
			ret=max(ret,m[n-i][1]+m[n-i+1][1]+solve(i-1,k-1,5));
			return ret;
	}
}

int main(){
	cin>>n>>num;
	memset(dp,-(long long)1,sizeof(dp));
	for(int i=0;i<n;i++){
		scanf("%lld %lld %lld",&m[i][0],&m[i][1],&m[i][2]);
	}
	cout<<solve(n,num,7);
	return 0;
}