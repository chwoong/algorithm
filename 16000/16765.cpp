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
int s=1;
int seg[50000];
void update(int pos,int val){
	pos+=s;
	seg[pos]=val;
	for(pos/=2;pos>=1;pos/=2)
		seg[pos]=max(seg[pos*2],seg[pos*2+1]);
}
int query(int l,int r){
	l+=s; r+=s;
	int ret=0;
	while(l<=r){
		if((l&1)==1) ret=max(ret,seg[l++]);
		if((r&1)==0) ret=max(ret,seg[r--]);
		l/=2; r/=2;
	}
	return ret;
}
//dp[i]: i~(n-1)까지 만들수 있는 최댓값 
int dp[50000];
int solve(int i){
	int &ret=dp[i];
	if(ret!=-1) return ret;
	if(i==n) return ret=0;
	ret=0;
	//i부터 시작하는 연속한 j(<=k)개 팀 가능
	for(int j=1;j<=k;j++){
		if(n-i>=j){
			int x=query(i,i+j-1);
			ret=max(ret,x*j+solve(i+j));
		}
	}
	ret=max(ret,seg[i+s]+solve(i+1));
	return ret;
}

int main(){
	cin>>n>>k;
	while(s<=n) s*=2;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		update(i,x);
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0);
	return 0;
}