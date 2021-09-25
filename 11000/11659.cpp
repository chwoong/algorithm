#include<iostream>
#include <stdio.h>
using namespace std;


int N,M;
int psum[100001];


int main(){
	scanf("%d %d",&N,&M);
	psum[0]=0;
	int x;
	for(int i=1;i<=N;i++){
		scanf("%d",&x);
		psum[i]=psum[i-1]+x;
	}
	int l,m;
	for(int i=0;i<M;i++){
		scanf("%d %d",&l,&m);
		printf("%d\n",psum[m]-psum[l-1]);
	}
	return 0;
}