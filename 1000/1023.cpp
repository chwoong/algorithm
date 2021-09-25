#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>
using namespace std;

/* 길이 2*i의 괄호ㅇㅇ문자열 개수*/
long long cache[26];
/* 길이 n '('로 시작하는 괄호 ㄴㄴ문자열 개수 */
long long dp[51];
/* 안 닫힌 괄호가 s개 있을 때 앞으로의 길이 n의 괄호ㄴㄴ문자열 개수*/
long long ddp[51][51];

/* 길이 n=2*i의 괄호ㅇㅇ문자열 개수를 반환한다. */
long long yesyes(int i){
	long long &ret=cache[i];
	if(ret!=-1) return ret;
	ret=0;
	for(int j=0;j<i;j++)
		ret +=yesyes(j)*yesyes(i-j-1);
	return ret;
}

/* 2^i계산 */
long long calc(int i){
	long long ret=1;
	for(int k=1;k<=i;k++)
		ret*=2;
	return ret;
}

long long f(int n,int s){
	long long &ret=ddp[n][s];
	if(ret!=-1) return ret;
	if(n==0) return ret=1;
	ret=0;
	if(n!=1 || s!=1) ret+=f(n-1,s-1);
	ret+=f(n-1,s+1);
	return ret;
}

/* 원하는 문자열 반환 */
string solve(long long n,long long k){
	if(n==0) return "";
	if(k<=calc(n-1)) return "("+solve(n-1,k);
	else{
		k-=calc(n-1);
		return ")"+solve(n-1,k);
	}
}
string sol(long long n,long long k,long long s){
	if(s<0) return solve(n,k);
	if(n==0) return "";
	if(k<=ddp[n-1][s+1]) return "("+sol(n-1,k,s+1);
	else{
		k-=ddp[n-1][s+1];
		return ")"+sol(n-1,k,s-1);
	}
}

int main(){
	long long N,K;
	cin>>N>>K;
	memset(cache,-1,sizeof(cache));
	memset(ddp,-1,sizeof(ddp));
	cache[0]=1;
	cache[1]=1;
	yesyes(N/2);
	/* ddp계산 */
	ddp[0][0]=1;
	for(int i=1;i<=N;i++){
		if(i%2==1)  ddp[i][0]=calc(i);
		else ddp[i][0]=calc(i)-cache[i/2];
	}
	for(int i=0;i<=N;i++){
		for(int j=1;j<=N;j++){
			if((i+j)<=N) f(i,j);
		}
	}
	/*
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			cout<< ddp[i][j]<<" ";
		}
		cout<<endl;
	}	
	*/
	if(ddp[N][0]<(K+1)) cout<<-1;
	else cout<<sol(N,K+1,0);
	return 0;
}