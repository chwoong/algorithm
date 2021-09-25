#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

/*구간 합 세그먼트 트리, k번째 수 찾기*/
#define MAX 100000
int n,m,size(1);
long long segtree[MAX*4];

void build(){
	for(int i=size-1;i>0;i--)
		segtree[i]=min(segtree[i*2],segtree[i*2+1]);
}

long long query(int l,int r){
	long long ret=1000000000;
	for(l+=(size-1),r+=(size-1); l<=r ; l>>=1,r>>=1){
		if(l&1) ret=min(ret,segtree[l++]);
		if(!(r&1)) ret=min(ret,segtree[r--]);
	}
	return ret;
}

int main(){
	cin>>n>>m;
	while(size<n)
		size*=2;
	for(int i=1;i<=n;i++){
		scanf("%lld",segtree+i+size-1);
	}
	build();
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%lld\n",query(a,b));
	}
	return 0;
}