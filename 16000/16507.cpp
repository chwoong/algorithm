#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

int r,c,q;
int map[1001][1001];
int fanwick[1001][1001];

void update(int x,int y,int val){
	int tmp=y;
	while(x<=r){
		y=tmp;
		while(y<=c){
			fanwick[x][y]+=val;
			y+=(y&-y);
		}
		x+=(x&-x);
	}
}

int sum(int x,int y){
	int s=0;
	int tmp=y;
	while(x>0){
		y=tmp;
		while(y>0){
			s+=fanwick[x][y];
			y-=(y&-y);
		}
		x-=(x&-x);
	}
	return s;
}

int main(){
	cin>>r>>c>>q;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++){
			scanf("%d",&map[i][j]);
			update(i,j,map[i][j]);
		}
	
	
	while(q--){
		int r1,c1,r2,c2;
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		printf("%d\n",(sum(r2,c2)-sum(r1-1,c2)-sum(r2,c1-1)+sum(r1-1,c1-1))/( (r2-r1+1)*(c2-c1+1) ));
	}
	return 0;
}