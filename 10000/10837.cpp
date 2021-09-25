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

int p[1010][1010];
int K,C;
//k¶ó¿îµå
void solve(int i,int j,int k,int isy){
	p[i][j]=1;
	if(k>K) return;
	//¿µÈñ Â÷·Ê
	if(isy==1){
		if(i+(K-k)+1<j) return;
		p[i+1][j]=1;
		if(i+(K-k)+1>j) solve(i,j,k,0);
		solve(i+1,j,k,0);
	}else{
		if(j+(K-k)+1<i) return;
		p[i][j+1]=1;
		if(j+(K-k)+1>i) solve(i,j,k+1,1);
		solve(i,j+1,k+1,1);
	}
}

int main(){
	cin>>K>>C;
	solve(0,0,1,1);
	while(C--){
		int M,N;
		scanf("%d %d",&M,&N);
		if(p[M][N]==1) puts("1");
		else puts("0");
	}
	return 0;
}