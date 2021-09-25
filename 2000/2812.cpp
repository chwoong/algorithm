#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
using namespace std;

typedef pair<int,int> P;
int N,K,l;
int start=1;
string s;
P seg[2000010];

void update(int node,int nodel,int noder,int pos,P val){
	if(pos<nodel || pos>noder) return;
	if(nodel==noder) {seg[node]=val;return;}
	seg[node]=min(seg[node],val);
	int mid=(nodel+noder)/2;
	update(node*2,nodel,mid,pos,val);
	update(node*2+1,mid+1,noder,pos,val);
}

P query(int node,int nodel,int noder,int l,int r){
	if(l<=nodel && noder<=r) return seg[node];
	else if(l>noder || r<nodel) return P(1,0);
	int mid=(nodel+noder)/2;
	return min(query(node*2,nodel,mid,l,r),query(node*2+1,mid+1,noder,l,r));
}

int main(){
	cin>>N>>K;
	l=N-K;
	cin>>s;
	
	for(int i=0;i<2000005;i++)
		seg[i]=P(1,0);
	
	int len=s.size();
	for(int i=0;i<len;i++){
		update(1,1,N,i+1,P('0'-s[i],i+1));
	}
	
	for(int i=0;i<N-K;i++){
		P here=query(1,1,N,start,N-l+1);
		printf("%d",-here.first);
		start=here.second+1;
		l--;
	}
	
	return 0;
}