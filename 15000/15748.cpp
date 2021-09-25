#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

#define MAX 1000000
typedef pair<int,int> P;
bool cmp(P a,P b){
	return a>b;
}
long long l,n,rf,rb,ans;
vector<P> v;
int main(){
	cin>>l>>n>>rf>>rb;
	long long time=rf-rb;
	for(int i=0;i<n;i++){
		int x,c;
		scanf("%d%d",&x,&c);
		v.push_back(P(c,x));
	}
	sort(v.begin(),v.end(),cmp);
	int dist=0;
	for(int i=0;i<n;i++){
		if(dist<v[i].second){
			ans+=time*(v[i].second-dist)*v[i].first;
			dist=v[i].second;
		}
	}
	cout<<ans;
	return 0;
}