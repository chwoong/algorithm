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

/*
본 풀이는 koosaga님과 kks227님의 풀이를 보고 공부해서
작성한 것
*/
#define MAX 100001

int N;
long long a[MAX],b[MAX];
/*convec hull에 쌓인 직선들(곡선을 이루는 직선들의 모임)*/
long long inc[MAX]; //기울기
long long y_int[MAX]; //y절편
long long dp[MAX]; 
int num=0; //지금까지 만든 직선의 최대 번호
int pos=0; //현재 사용중인 직선 번호

double cross(int p,int q){
	return (double)(y_int[p]-y_int[q])/(double)(inc[q]-inc[p]);
}

void add(long long c,long long t){
	inc[num]=c;
	y_int[num]=t;
	while(num>1 && cross(num,num-1)<cross(num-1,num-2)){
		inc[num-1]=inc[num];
		y_int[num-1]=y_int[num];
		num--;
	}
	num++;
}

long long con(long long x){
	while(pos+1<num && x>=cross(pos,pos+1)){
		pos++;
	}
	return inc[pos]*x+y_int[pos];
}

int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%lld",a+i);
	for(int i=0;i<N;i++)
		scanf("%lld",b+i);
	add(b[0],dp[0]);
	for(int i=1;i<N;i++){
		dp[i]=con(a[i]);
		add(b[i],dp[i]);
	}
	printf("%lld",dp[N-1]);
	return 0;
}