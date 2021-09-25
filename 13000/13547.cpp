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

//https://www.weeklyps.com/entry/%EB%AA%A8%EC%8A%A4-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Mos-algorithm
//mo's 알고리즘 공부
typedef pair<int,int> P;
int n,q;
int a[1000001];
int cnt[1000001];
int ans[100001];
int val;//서로 다른 숫자 개수
vector<P> v;
//처리 순서
vector<pair<P,int> > order;

void add(int i){
	if(cnt[a[i]]==0) val++;
	cnt[a[i]]++;
}

void erase(int i){
	cnt[a[i]]--;
	if(cnt[a[i]]==0) val--;
}

void mos(int p,int c){
	int l1=v[p].first;
	int r1=v[p].second;
	int l2=v[c].first;
	int r2=v[c].second;
	// l2<l1
	for(int i=l1-1;i>=l2;i--) add(i);
	// l1<l2
	for(int i=l1;i<l2;i++) erase(i);
	// r1<r2
	for(int i=r1+1;i<=r2;i++) add(i);
	// r2<r1
	for(int i=r1;i>r2;i--) erase(i);
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	cin>>q;
	//시작
	v.push_back(P(0,0));
	order.push_back({P(0,0),0});
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		v.push_back(P(x,y));
		order.push_back( { P(x/sqrt(n),y) , i } );
	}
	sort(order.begin(),order.end());
	for(int i=1;i<=q;i++){
		mos(order[i-1].second,order[i].second);
		ans[order[i].second]=val;
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}