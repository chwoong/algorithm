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

typedef pair<int,int> P;
int n,s;
vector<P> v;

//dp[i]: i번째 그림을 샀을 때 그 값을 포함하여 얻을 수 있는 최대 금액
long long dp[300000];


int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(P(a,b));
	}
	sort(v.begin(),v.end());
	if(v[0].first>=s) dp[0]=v[0].second;
	for(int i=1;i<n;i++){
		long long val=v[i].second;
		int x=(lower_bound(v.begin(),v.end(),P(v[i].first-s+1,0))-v.begin())-1;
		dp[i]=max(dp[i-1],dp[x]+val);
	}
	cout<<*max_element(dp,dp+n);
	return 0;
}