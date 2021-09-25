#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

int n,m;
int map[1025][1025];
int fanwick[1025][1025]={0,};

void update(int x,int y,int val){
	int tmp=x;
	while(y<=n){
		x=tmp;
		while(x<=n){
			fanwick[x][y]+=val;
			x+=(x & -x);
		}
		y+=(y & -y);
	}
}

int sum(int x,int y){
	int s=0;
	int tmp=x;
	while(y>0){
		x=tmp;
		while(x>0){
			s+=fanwick[x][y];
			x-=(x&-x);
		}
		y-=(y&-y);
	}
	return s;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&map[i][j]);
			update(i,j,map[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		int w,x1,y1,x2,y2,c;
		scanf("%d",&w);
		if(w==0){
			scanf("%d%d%d",&x1,&y1,&c);
			update(x1,y1,c-map[x1][y1]);
			map[x1][y1]=c;
		}else{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int a,b,c,d;
			/*(a,c)와 (b,d)사이의 합*/
			x1>x2?(a=x2,b=x1):(b=x2,a=x1);
			y1>y2?(c=y2,d=y1):(d=y2,c=y1);
			printf("%d\n",sum(b,d)-sum(a-1,d)-sum(b,c-1)+sum(a-1,c-1));
		}
	}
	return 0;
}