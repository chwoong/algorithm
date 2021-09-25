#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;
/*
https://jason9319.tistory.com/40
보고 세그먼트 공부한 풀이
*/
#define MAX 100001

int n,k;

/*0: min, 1: max*/
int segment[4*MAX][2]={0,};
int dvd[MAX];
int query(int node,int nodel,int noder,int l,int r,int ch){
	if(r<nodel || noder<l) {
		if(ch) return -1;
		else return MAX;
	}
	if(l<=nodel && noder<=r) return segment[node][ch];
	int mid=(nodel+noder)/2;
	if(ch) return max(query(node*2,nodel,mid,l,r,1),query(node*2+1,mid+1,noder,l,r,1));
	else return min(query(node*2,nodel,mid,l,r,0),query(node*2+1,mid+1,noder,l,r,0));
}

int update(int node,int nodel,int noder,int pos,int val,int ch){
	if(nodel>pos || noder<pos){
		return segment[node][ch];
	}
	if(nodel==noder) return segment[node][ch]=val;
	int mid=(nodel+noder)/2;
	if(ch) return segment[node][ch]=max(update(node*2,nodel,mid,pos,val,ch),update(node*2+1,mid+1,noder,pos,val,ch));
	else return segment[node][ch]=min(update(node*2,nodel,mid,pos,val,ch),update(node*2+1,mid+1,noder,pos,val,ch));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			update(1,0,n-1,i,i,0);
			update(1,0,n-1,i,i,1);
			dvd[i]=i;
		}
		while(k--){
			int q,a,b;
			scanf("%d %d %d",&q,&a,&b);
			/*손님*/
			if(q){
				if( a==query(1,1,n,a+1,b+1,0) && b==query(1,1,n,a+1,b+1,1) ) printf("YES\n");
				else printf("NO\n");
			}
			/*진상*/
			else{
				swap(dvd[a],dvd[b]);
				update(1,0,n-1,a,dvd[a],0);
				update(1,0,n-1,a,dvd[a],1);
				update(1,0,n-1,b,dvd[b],0);
				update(1,0,n-1,b,dvd[b],1);
			}
		}
	}
	return 0;
}