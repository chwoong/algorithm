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

int n,m,k;
int size=1;
long long segtree[8000000]={0,};
long long lazy[8000000]={0,};

void propagate(int node,int nodel,int noder){
	/*node에 적힌 lazy값을 처리해야 된다면*/
	if(lazy[node]!=0){
		/*리프노드가 아니면 자식들에게 lazy를 미룸*/
		if(node<size){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		/*그리고 이번 노드는 변경 내용 수정*/
		segtree[node]+= ( lazy[node]*(noder-nodel+1) );
		lazy[node]=0;
	}
}

/*[l,r]구간에 val을 추가하자(현재 node에 해당하는 부분만)*/
void add(int node,int nodel,int noder,int l,int r,int val){
	propagate(node,nodel,noder);
	
	if(r<nodel || noder<l) return;
	/*탐색 중인 node가 수정 범위에 포함*/
	if(l<=nodel && noder<=r){
		lazy[node]+=val;
		propagate(node,nodel,noder);
		return;
	}
	int mid=(nodel+noder)/2;
	add(node*2,nodel,mid,l,r,val);
	add(node*2+1,mid+1,noder,l,r,val);
	/*자식이 수정되었을 수 있으므로 node값 갱신*/
	segtree[node]=segtree[node*2]+segtree[node*2+1];
}

long long sum(int node,int nodel,int noder,int l,int r){
	propagate(node,nodel,noder);
	if(l>noder || r<nodel)	return 0;
	if(l<=nodel && noder<=r) return segtree[node];
	int mid=(nodel+noder)/2;
	return sum(node*2,nodel,mid,l,r)+sum(node*2+1,mid+1,noder,l,r);
}

int main(){
	cin>>n>>m>>k;
	while(size<n)
		size*=2;
	for(int i=0;i<n;i++){
		long long x;
		scanf("%lld",segtree+size+i);
	}
	/*초기화*/	
	for(int j=size-1;j>=1;j--)
		segtree[j]=segtree[j*2]+segtree[j*2+1];
	/*쿼리 실행*/
	for(int i=0;i<(m+k);i++){
		int a,b,c;
		long long d;
		scanf("%d ",&a);
		if(a==1){
			scanf("%d %d %lld",&b,&c,&d);
			//lazy propagtion
			add(1,1,size,b,c,d);
		}else{
			scanf("%d %d",&b,&c);
			printf("%lld\n",sum(1,1,size,b,c));
		}
	}
		
	return 0;
}