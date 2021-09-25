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
	/*포화 이진 트리 크기*/
	while(size<N)
		size*=2;
	/*처음에 segtree의 리프에 모두 1저장하고 segtree생성함*/
	for(int i=size;i<2*size;i++)
		segtree[i]=1;
	init(1);
	for(int l=1;l<=N;l++){
		int x;
		scanf("%d",&x);
		/*sum[1~i]=x+1 인 i를 찾아서 arr[i]=l 대입*/
		int i=sum(1,1,size,x+1);
		ans[i]=l;
		update(i+size-1);
	}
	for(int l=1;l<=N;l++)
		printf("%d\n",ans[l]);
	return 0;
}