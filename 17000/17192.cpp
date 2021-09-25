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
using namespace std;

int n,k;
int size=1;

int maxseg[1600];
int sumseg[1600];

void update(int pos,int val){
	pos+=size;
	maxseg[pos]+=val;
	sumseg[pos]+=val;
	for(pos/=2;pos>=1;pos/=2){
		maxseg[pos]=max(maxseg[pos*2],maxseg[pos*2+1]);
		sumseg[pos]=sumseg[pos*2]+sumseg[pos*2+1];
	}
}
int maxq(int l,int r){
	l+=size;
	r+=size;
	int s=0;
	while(l<=r){
		if(l%2==1) s=max(s,maxseg[l++]);
		if(r%2==0) s=max(s,maxseg[r--]);
		l/=2; r/=2;
	}
	return s;
}
int sumq(int l,int r){
	l+=size;
	r+=size;
	int s=0;
	while(l<=r){
		if(l%2==1) s+=sumseg[l++];
		if(r%2==0) s+=sumseg[r--];
		l/=2; r/=2;
	}
	return s;
}

int dp[500][500];

//i부터 n까지 num번이하로 나눠서 얻을 수 있는 낭비의 최솟값
int solve(int i,int num){
	int& ret=dp[i][num];
	if(ret!=-1) return ret;
	if(i>=n) return ret=0;
	ret=2000000000;
	if(num==1){
		return ret=maxq(i,n)*(n-i+1)-sumq(i,n);
	}else{
		for(int x=i;x<=n;x++){
			ret=min(ret,maxq(i,x)*(x-i+1)-sumq(i,x)+solve(x+1,num-1));
		}
		return ret;
	}
}

int main(){
	cin>>n>>k;
	while(size<n) size*=2;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		update(i,x);
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(1,k+1);
	return 0;
}