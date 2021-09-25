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

int N,M;
int map[701][701];
int fen[1500];
void update(int pos,int val){
	while(pos<=2*M-1){
		fen[pos]+=val;
		pos+=(pos&-pos);
	}
}
int sum(int pos){
	int s=0;
	while(pos>0){
		s+=fen[pos];
		pos-=(pos&-pos);
	}
	return s;
}
int main(){
	cin>>M>>N;
	for(int i=0;i<N;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		update(1+a,1);
		update(1+a+b,1);
	}
	for(int i=0;i<M;i++){
		map[i][0]=sum(M-i);
	}
	for(int j=0;j<M;j++){
		map[0][j]=sum(M+j);
	}
	for(int i=1;i<M;i++){
		for(int j=1;j<M;j++){
			 map[i][j]=max(map[i-1][j],max(map[i-1][j-1],map[i][j-1]));
		}
	}
	
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			printf("%d ",1+map[i][j]);
		}
		puts("");
	}
}