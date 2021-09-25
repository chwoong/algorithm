#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;
#define MAX 2000001

int N;
int size=1;
int segtree[MAX];
struct student{
	int score[3];
};
int mini(int node,int nodel,int noder,int a,int b){
	if(nodel>b || noder<a) return MAX;
	if(a<=nodel && noder<=b) return segtree[node];
	int mid=(nodel+noder)/2;
	return min(mini(node*2,nodel,mid,a,b),mini(node*2+1,mid+1,noder,a,b));
}
void update(int node,int val){
	segtree[node]=val;
	int p=node/2;
	while(p>0){
		segtree[p]=min(segtree[p*2],segtree[p*2+1]);
		p/=2;
	}
}

bool cmp(student a, student b){
	return a.score[0]<b.score[0];
}

int main(){
	cin>>N;
	while(size<N){
		size*=2;
	}
	for(int i=0;i<=2*size;i++){
		segtree[i]=MAX;
	}
	student s[MAX/4];
	for(int i=0;i<3;i++){
		for(int j=1;j<=N;j++){
			int x;
			scanf("%d ",&x);
			s[x].score[i]=j;
		}
	}
	sort(s+1,s+N+1,cmp);
	int ans=0;
	for(int i=1;i<=N;i++){
		int ret=mini(1,1,size,0,s[i].score[1]-1);
		if(ret>s[i].score[2]) ans++;
		update(s[i].score[1]+size-1,s[i].score[2]);
	}
	cout<<ans;
	
	return 0;	
}