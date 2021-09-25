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
long long arr[4000000]={0,};
long long segtree[4000000];

long long makeseg(int left,int right,int node){
	if(left==right) segtree[node]=arr[left];
	else{
		int mid=(left+right)/2;
		segtree[node]=makeseg(left,mid,2*node)+makeseg(mid+1,right,2*node+1);
	}
	return segtree[node];
}

void changeseg(int node){
	int parent=node/2;
	if(parent<1) return;
	segtree[parent]=segtree[parent*2]+segtree[parent*2+1];
	changeseg(parent);
}
/* 합을 구하려는 left~right와 node의 양쪽 끝 범위 nodel과 noder */
long long sum(int left,int right,int node,int nodel,int noder){
	if(left>noder || right<nodel) return 0;
	if(left<=nodel && right>=noder) return segtree[node];
	int mid=(nodel+noder)/2;
	return sum(left,right,node*2,nodel,mid)+sum(left,right,node*2+1,mid+1,noder);
}

int main(){
	cin>>n>>m>>k;
	while(size<n)
		size*=2;
	for(int i=0;i<n;i++){
		scanf("%lld",arr+1+i);
	}
	//세그먼트 트리 계산
	makeseg(1,size,1);
	/* 연산 수행 */
	long long a,b,c;
	for(int i=0;i<m+k;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==1) {segtree[size+b-1]=c; changeseg(size+b-1);}
		if(a==2) printf("%lld\n",sum(b,c,1,1,size));
	}
	return 0;
}