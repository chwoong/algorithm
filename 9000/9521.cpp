#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define MAX 1000001
#define MOD 1000000007
int n;
long long k;
long long ans=1;
int p[MAX];
bool visited[MAX];
bool finished[MAX];
vector<int> cyc;
//dp[i]: cycle 길이 i의 칠하는 방법 수
long long dp[MAX];

long long f(int i){
	long long& ret=dp[i];
	if(ret!=-1ll) return ret;
	if(i==1) return ret=k;
	if(i==2) return ret=k*(k-1) %MOD;
	if(i==3) return ret=( (k-2)*f(i-1) )%MOD;
	return ret=( ( (k-1)*f(i-2) )%MOD+( (k-2)*f(i-1) )%MOD )%MOD;
}

void dfs(int i){
	visited[i]=true;
	int next=p[i];
	if(next!=0){
		//cycle을 이루는 원소
		if(visited[next] && !finished[next]){
			int len=1;
			for(;next!=i;next=p[next]){
				len++;
			}
			cyc.push_back(len);
		}
		//새로운 dfs
		if(!visited[next]){
			dfs(next);
		}
	}
	finished[i]=true;
}

int main(){
	cin>>n>>k;
	memset(dp,-1ll,sizeof(dp));
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		p[i]=x;
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]) dfs(i);
	}
	int num=n;
	for(int ele:cyc){
		num-=ele;
		ans=(ans*f(ele))%MOD;
	}
	while(num--){
		ans=(ans*(k-1))%MOD;
	}
	cout<<ans;
	return 0;
}