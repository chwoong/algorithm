#include<iostream>
#include <stdio.h>
using namespace std;
int N,M;
int psum[1000001];
long long divide[1000]={0,};
int main(){
	scanf("%d %d",&N,&M);
	psum[0]=0;
	divide[0]=1;
	int x;
	for(int i=1;i<=N;i++){
		scanf("%d",&x);
		psum[i]=(psum[i-1]+x%M)%M;
		divide[psum[i]]++;
	}
	long long num=0;
	for(int i=0;i<M;i++){
		num+=divide[i]*(divide[i]-1)/2;
	}
	printf("%lld",num);	
	return 0;
}