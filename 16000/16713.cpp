#include<iostream>
#include <stdio.h>
using namespace std;
int N,Q;
int xorsum[1000001];
int ans=0;

int main(){
	scanf("%d %d",&N,&Q);
	xorsum[0]=0;
	int x;
	for(int i=1;i<=N;i++){
		scanf("%d",&x);
		xorsum[i]=xorsum[i-1] ^ x;
	}
	int l,m;
	for(int i=1;i<=Q;i++){
		scanf("%d %d",&l,&m);
		ans = ans ^ (xorsum[m]^xorsum[l-1]);
	}
	printf("%d",ans);
	
	return 0;
}