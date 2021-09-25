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

#define MOD 1000000007

int n,m,k;
long long segtree[4000000];

long long multi(int node,int nodel,int noder,int l,int r){
	if(l>noder || r<nodel)	return 1;
	if(l<=nodel && noder<=r) return segtree[node];
	int mid=(nodel+noder)/2;
	return (multi(node*2,nodel,mid,l,r)*multi(node*2+1,mid+1,noder,l,r))%MOD;
}

long long update(int node,int nodel,int noder,int pos,long long val){
	if(pos<nodel || noder<pos) return segtree[node];
	if(nodel==noder) return segtree[node]=val;
	int mid=(nodel+noder)/2;
	return segtree[node]=(update(node*2,nodel,mid,pos,val)*update(node*2+1,mid+1,noder,pos,val))%MOD;
}

int main(){
	cin>>n>>m>>k;
	memset(segtree,1,sizeof(segtree));
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		update(1,1,n,i,x);
	}
	for(int i=0;i<(m+k);i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		/*update*/
		if(a==1){
			update(1,1,n,b,c);
		}
		/*multiply*/
		else{
			printf("%lld\n",multi(1,1,n,b,c));
		}
	}
		
	return 0;
}