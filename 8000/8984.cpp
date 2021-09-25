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
long long n,l;
P bar[100000];
P com[100000];
vector<long long> t;
vector<long long> b;
vector<P> adj1[100000];
vector<P> adj2[100000];

long long dp[100000][2];
//i번 막대를 포함하여 오른쪽만 사용하여 구해지는 최대 지그재그 길이
//k가 0이면 이번 막대의 아래에서 연결
//k가 1이면 이번 막대의 위에서 연결
long long solve(int i,int k){
	long long& ret=dp[i][k];
	if(ret!=-1ll) return ret;
	ret=l+abs(bar[i].first-bar[i].second);
	long long val=0;
	//막대의 top에서 지그재그 연결
	if(k==1)
		for(auto& next:adj1[com[i].first]){
			if(next.first>com[i].second){
				val=max(val,solve(next.second,0));
			}
		}
	//막대의 bottom에서 지그재그 연결
	else
		for(auto&next:adj2[com[i].second]){
			if(next.first>com[i].first){
				val=max(val,solve(next.second,1));
			}
		}
	return ret=ret+val;
}

int main(){
	cin>>n>>l;
	for(int i=0;i<n;i++){
		long long a,c;
		scanf("%lld %lld",&a,&c);
		t.push_back(a);
		b.push_back(c);
		bar[i]=P(a,c);
	}
	sort(t.begin(),t.end());
	sort(b.begin(),b.end());
	for(int i=0;i<n;i++){
		long long f=bar[i].first;
		long long s=bar[i].second;
		long long x=lower_bound(t.begin(),t.end(),f)-t.begin();
		long long y=lower_bound(b.begin(),b.end(),s)-b.begin();
		com[i]=P(x,y);
		adj1[x].push_back(P(y,i));
		adj2[y].push_back(P(x,i));
	}
	memset(dp,-1ll,sizeof(dp));
	long long m=0;
	for(int i=0;i<n;i++){
		m=max(m,solve(i,0));
		m=max(m,solve(i,1));
	}
	cout<<m;
	
	return 0;
}