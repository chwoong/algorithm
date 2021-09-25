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
#include<math.h>
using namespace std;

int n,m;
int arr[100001];
vector<int> seg[400000];

void update(int node,int nodel,int noder,int val,int pos){
	if(pos<nodel || noder<pos) return;
	else if(nodel==noder) {seg[node].push_back(val);return;}
	seg[node].push_back(val);
	int mid=(nodel+noder)/2;
	update(node*2,nodel,mid,val,pos);
	update(node*2+1,mid+1,noder,val,pos);
}

int query(int node,int nodel,int noder,int l,int r,int k){
	if(noder<l || r<nodel) return 0;
	else if(l<=nodel && noder<=r){
		vector<int>::iterator it=lower_bound(seg[node].begin(),seg[node].end(),k+1);
		//k이하 개수
		return it-seg[node].begin();
	}
	int mid=(nodel+noder)/2;
	return query(node*2,nodel,mid,l,r,k)+query(node*2+1,mid+1,noder,l,r,k);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
		update(1,1,n,arr[i],i);
	}
	for(int i=1;i<400000;i++)
		sort(seg[i].begin(),seg[i].end());
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",b-a+1-query(1,1,n,a,b,c));
	}
	return 0;
}