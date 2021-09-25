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

#define MOD 1000000007

int n,m,k;
vector<int> cla[5010];
vector<long long> num;
//dp[i]: 길이 i의 문장을 만들 수 있는 가짓수
long long dp[5010];
vector<int> w;
int arr[26];
//길이 i의 문장 만드는 가짓수
long long solve(int i){
	if(i<0) return 0;
	else if(i==0) return 1;
	long long& ret=dp[i];
	if(ret!=-1ll) return ret;
	ret=0;
	for(int ele:w){
		ret=(ret+solve(i-ele))%MOD;
	}
	return ret;
}
//x^i를 반환
long long pow(long long x,int i){
	if(i==0) return 1;
	else if(i==1) return x;
	else{
		long long a=pow(x,i/2);
		if(i%2==1) return x*((a*a)%MOD)%MOD;
		else return (a*a)%MOD;
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		int s,c;
		scanf("%d %d",&s,&c);
		cla[c].push_back(s);
		w.push_back(s);
	}
	memset(dp,-1ll,sizeof(dp));
	for(int i=1;i<=n;i++){
		//cla[i]에 포함된 단어들이 마지막에 들어가 있어야 함
		if(!cla[i].empty()){
			long long x=0;
			for(int ele:cla[i]){
				x=(x+solve(k-ele))%MOD;
			}
			num.push_back(x);
		}
	}
	
	for(int i=0;i<m;i++){
		char p[2];
		scanf("%s",p);
		arr[p[0]-'A']++;
	}
	long long ans=1;
	for(int i=0;i<26;i++){
		if(arr[i]!=0){
			long long t=0;
			for(long long ele:num){
				//ele^arr[i]의 전체 합
				t=(t+pow(ele,arr[i]))%MOD;
			}
			ans=(ans*t)%MOD;
		}
	}
	cout<<ans;
	return 0;
}