#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>

using namespace std;

int n,m,k;
long long size=1;
vector<int> arr(4000000);
vector<pair<int,int>> order(4000000);
int segtree[4000000]={0,};

void changeseg(int node){
	int parent=node/2;
	if(parent<1) return;
	segtree[parent]=max(segtree[parent*2],segtree[parent*2+1]);
	changeseg(parent);
}
/* 구간 내 최솟값을 구하려는 left~right와 node의 양쪽 끝 범위 nodel과 noder */
int query(int left,int right,int node,int nodel,int noder){
	if(left>noder || right<nodel) return 0;
	if(left<=nodel && right>=noder) return segtree[node];
	int mid=(nodel+noder)/2;
	return max(query(left,right,node*2,nodel,mid),query(left,right,node*2+1,mid+1,noder));
}

int main(){
	cin>>n;
	while(size<n)
		size*=2;
	for(int i=1;i<=n;i++){
		scanf("%d ",&arr[i]);
		order[i].first=arr[i];
		order[i].second=-i;
	}
	sort(&order[1],&order[n+1]);
	//세그먼트 트리 계산
	for(int i=1;i<=n;i++){
		int index=-order[i].second;
		int val=query(1,index,1,1,size);
		segtree[size+index-1]=val+1;
		changeseg(size+index-1);
	}
	cout<<segtree[1];
	return 0;
}