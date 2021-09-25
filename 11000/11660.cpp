#include<iostream>
#include <stdio.h>
using namespace std;

int N,M;
int psum[1025][1025]={0,};
int main(){
	scanf("%d %d",&N,&M);
	int x;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			scanf("%d",&x);
			psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+x;
		}
	}
	for(int i=0;i<M;i++){
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		printf("%d\n",psum[x2][y2]-psum[x1-1][y2]-psum[x2][y1-1]+psum[x1-1][y1-1]);
	}
	
	return 0;
}