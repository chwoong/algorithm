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
#define MAX 131072
int n,k;
int arr[250000];
int segtree[MAX*2];

void update(int pos,int val){
	pos+=(MAX-1);
	for(segtree[pos]+=val;pos>1;pos>>=1){
		segtree[pos/2]=segtree[pos]+segtree[pos^1];
	}
}
int sum(int l,int r){
	int ret=0;
	for(l+=(MAX-1),r+=(MAX-1); l<=r ; l>>=1,r>>=1){
		if(l&1) ret+=segtree[l++];
		if(!(r&1)) ret+=segtree[r--];
	}
	return ret;
}
/*k번째 구하는(결국 중앙값) */
int median(int k,int node,int l,int r){
	if(l==r) return l;
	int mid=(l+r)/2;
	if(segtree[node*2]>=k) return median(k,node*2,l,mid);
	else return median(k-segtree[node*2],node*2+1,mid+1,r);
}

int main(){
	cin>>n>>k;
	long long ans=0;
	for(int i=0;i<k-1;i++){
		scanf("%d",arr+i);
		update(arr[i]+1,1);
	}
	for(int i=k-1;i<n;i++){
		scanf("%d",arr+i);
		update(arr[i]+1,1);
		ans+=(median((k+1)/2,1,1,MAX)-1);
		update(arr[i-(k-1)]+1,-1);
	}
	cout<<ans;
	return 0;
}