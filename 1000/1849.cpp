#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int segtree[400000]={0,};
int ans[100001];
int size=1;
int init(int i){
	int &ret=segtree[i];
	if(ret!=0) return ret;
	else return ret=init(i*2)+init(i*2+1);
}
void update(int pos){
	segtree[pos]=0;
	int parent=pos/2;
	while(parent>=1){
		segtree[parent]=segtree[parent*2]+segtree[parent*2+1];
		parent/=2;
	}
}
int sum(int node,int nodel,int noder,int x){
	int mid=(nodel+noder)/2;
	if(node>=size) return nodel;
	if(segtree[node*2]<x) return sum(node*2+1,mid+1,noder,x-segtree[node*2]);
	else return sum(node*2,nodel,mid,x);
}

int N;
int main(){
	cin>>N;
	/*��ȭ ���� Ʈ�� ũ��*/
	while(size<N)
		size*=2;
	/*ó���� segtree�� ������ ��� 1�����ϰ� segtree������*/
	for(int i=size;i<2*size;i++)
		segtree[i]=1;
	init(1);
	for(int l=1;l<=N;l++){
		int x;
		scanf("%d",&x);
		/*sum[1~i]=x+1 �� i�� ã�Ƽ� arr[i]=l ����*/
		int i=sum(1,1,size,x+1);
		ans[i]=l;
		update(i+size-1);
	}
	for(int l=1;l<=N;l++)
		printf("%d\n",ans[l]);
	return 0;
}