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

typedef pair<long long,long long> P;
int n,m,r;
vector<long long> milk;
vector<P> sellm; //밀크 판매
vector<long long> sellc; //소 판매
long long p[100010]; //밀크 판매
long long q[100010]; //소 판매
int main(){
	cin>>n>>m>>r;
	for(int i=0;i<n;i++){
		long long x;
		scanf("%lld",&x);
		milk.push_back(x);
	}
	sort(milk.begin(),milk.end(),greater<long long>() );
	for(int i=0;i<m;i++){
		long long a,b;
		scanf("%lld%lld",&a,&b);
		sellm.push_back(P(b,a));
	}
	sort(sellm.begin(),sellm.end(),greater<P>() );
	for(int i=0;i<r;i++){
		long long x;
		scanf("%lld",&x);
		sellc.push_back(x);
	}
	sort(sellc.begin(),sellc.end(),greater<long long>() );
	//현재 사용하고 있는 우유 가게의 순서
	int order=0;
	//현재 사용하고 있는 우유 가게에 판매한 양
	long long amount=0;
	for(int i=1;i<=n;i++){
		//소를 판매한 수가 i마리일때
		if(i<=r) q[i]=q[i-1]+sellc[i-1];
		else q[i]=q[i-1];
		//그리고 소의 밀크를 판매한 수가 i마리 일때
		//현재 소의 우유 생산량
		long long s=milk[i-1];
		long long val=0;
		while(1){
			if(s==0) break;
			if(order==m) break;
			if(amount+s<=sellm[order].second){
				val+=s*sellm[order].first;
				amount+=s;
				break;
			}
			val+=(sellm[order].second-amount)*sellm[order].first;
			s-=(sellm[order].second-amount);
			amount=0;
			order++;
		}
		p[i]=p[i-1]+val;
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,p[i]+q[n-i]);
	}
	cout<<ans;
	return 0;
}