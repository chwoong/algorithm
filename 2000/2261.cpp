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
int n;

vector<P> v;
vector<P> a;

int dist(int i,int j){
	return (v[i].first-v[j].first)*(v[i].first-v[j].first)+(v[i].second-v[j].second)*(v[i].second-v[j].second);
}

int solve(int l,int r){
	if(l==r){
		return 1000000000;
	}
	if(l+1==r){
		return dist(l,r);
	}
	int mid=(l+r)/2;
	int d=solve(l,mid);
	d=min(d,solve(mid+1,r));
	//기준선(mid)로 부터 양쪽 d만큼 간격안에서 확인
	//각 점에 대해 최대 7번만 확인하면 된다.
	a.clear();
	for(int i=l;i<=r;i++){
		if((v[i].first-v[mid].first)*(v[i].first-v[mid].first)<=d) a.push_back(P(v[i].second,v[i].first));
	}
	sort(a.begin(),a.end());
	int len=a.size();
	for(int i=0;i<len;i++){
		for(int j=i+1;j<min(i+8,len);j++){
			int k=(a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second);
			d=min(d,k);
		}
	}
	return d;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(P(a,b));
	}
	sort(v.begin(),v.end());
	cout<< solve(0,n-1);
	return 0;
}