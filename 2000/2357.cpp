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
int N,M;
int size=1;
int min_segtree[400000]={0,};
int max_segtree[400000]={0,};

/*dec=0: min, dec=1: max*/
int update(int pos,int dec){
	if(dec==0){	
		if(pos>=size) return min_segtree[pos];
		return min_segtree[pos]=min(update(pos*2,dec),update(pos*2+1,dec));
	}else{
		if(pos>=size) return max_segtree[pos];
		return max_segtree[pos]=max(update(pos*2,dec),update(pos*2+1,dec));
	}
}

int solve(int node,int nodel,int noder,int a,int b,int dec){
	/*min °è»ê*/
	if(dec==0){
		if(b<nodel || a>noder) return 1000000001;
		if(a<=nodel && noder<=b) return min_segtree[node];
		int mid=(nodel+noder)/2;
		return min(solve(node*2,nodel,mid,a,b,dec),solve(node*2+1,mid+1,noder,a,b,dec));
	}else{
		if(b<nodel || a>noder) return 0;
		if(a<=nodel && noder<=b) return max_segtree[node];
		int mid=(nodel+noder)/2;
		return max(solve(node*2,nodel,mid,a,b,dec),solve(node*2+1,mid+1,noder,a,b,dec));
	}
}

int main(){
	cin>>N>>M;
	while(size<N){
		size*=2;
	}
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		max_segtree[size+i]=min_segtree[size+i]=x;	
	}
	update(1,0);
	update(1,1);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d\n",solve(1,1,size,a,b,0),solve(1,1,size,a,b,1));
	}
	return 0;
}