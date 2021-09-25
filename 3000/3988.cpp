#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define MAX 10000000
int n,k;
vector<int> v;
int segtree[4000000];
int arr[1000000];
int query(int node,int nodel,int noder,int l,int r){
	if(l>noder || nodel>r) return MAX;
	if(l<=nodel && noder<=r) return segtree[node];
	int mid=(nodel+noder)/2;
	return min(query(node*2,nodel,mid,l,r),query(node*2+1,mid+1,noder,l,r));
}

int update(int node,int nodel,int noder,int pos){
	if(pos<nodel || pos>noder) return segtree[node];
	else if(nodel==noder) return segtree[node]=arr[pos];
	int mid=(nodel+noder)/2;
	return segtree[node]=min(update(node*2,nodel,mid,pos),update(node*2+1,mid+1,noder,pos));
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<4000000;i++)
		segtree[i]=MAX;
	for(int i=1;i<n;i++){
		arr[i]=v[i]-v[i-1];
		update(1,1,n-1,i);
	}
	//정렬된 v의 앞에 i개의 숫자를 지움
	//자동으로 v의 뒤에 k-i개의 숫자를 지움
	int ans=20000000;
	for(int i=0;i<=k;i++){
		int a=v[n-1-k+i]-v[i];
		int b=query(1,1,n-1,1+i,n-1-k+i);
		ans=min(ans,a+b);
	}
	cout<<ans;
	return 0;
}