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
int n,t;
int a[100010];
P query[100010];
vector<pair<P,int> > v;
long long res=0;
//num[i]: 구간 내 i의 개수
long long num[1000001];
long long ans[100010];
void add(int i){
	long long p=a[i];
	long long q=num[p];
	res+=(2*q+1)*p;
	num[p]++;
}

void erase(int i){
	long long p=a[i];
	long long q=num[p];
	res-=(2*q-1)*p;
	num[p]--;
}

void solve(int i,int j){
	int l1=query[i].first;
	int r1=query[i].second;
	int l2=query[j].first;
	int r2=query[j].second;
	if(l1<l2) for(int x=l1;x<l2;x++) erase(x);
	if(l2<l1) for(int x=l1-1;x>=l2;x--) add(x);
	if(r1<r2) for(int x=r1+1;x<=r2;x++) add(x);
	if(r2<r1) for(int x=r1;x>r2;x--) erase(x);
}

int main(){
	cin>>n>>t;
	int s=sqrt(n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=1;i<=t;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		query[i]=P(l,r);
		v.push_back(make_pair(P(l/s,r),i));
	}
	query[0]={0,0};
	v.push_back(make_pair(make_pair(0,0),0));
	sort(v.begin(),v.end());
	for(int i=0;i<t;i++){
		int x=v[i].second;
		int y=v[i+1].second;
		solve(x,y);
		ans[y]=res;
	}
	for(int i=1;i<=t;i++)
		printf("%lld\n",ans[i]);
	return 0;
}