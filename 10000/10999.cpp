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
	/*node�� ���� lazy���� ó���ؾ� �ȴٸ�*/
	if(lazy[node]!=0){
		/*������尡 �ƴϸ� �ڽĵ鿡�� lazy�� �̷�*/
		if(node<size){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		/*�׸��� �̹� ���� ���� ���� ����*/
		segtree[node]+= ( lazy[node]*(noder-nodel+1) );
		lazy[node]=0;
	}
}

/*[l,r]������ val�� �߰�����(���� node�� �ش��ϴ� �κи�)*/
void add(int node,int nodel,int noder,int l,int r,int val){
	propagate(node,nodel,noder);
	
	if(r<nodel || noder<l) return;
	/*Ž�� ���� node�� ���� ������ ����*/
	if(l<=nodel && noder<=r){
		lazy[node]+=val;
		propagate(node,nodel,noder);
		return;
	}
	int mid=(nodel+noder)/2;
	add(node*2,nodel,mid,l,r,val);
	add(node*2+1,mid+1,noder,l,r,val);
	/*�ڽ��� �����Ǿ��� �� �����Ƿ� node�� ����*/
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
	/*�ʱ�ȭ*/	
	for(int j=size-1;j>=1;j--)
		segtree[j]=segtree[j*2]+segtree[j*2+1];
	/*���� ����*/
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