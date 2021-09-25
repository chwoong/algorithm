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
#define MAX 100001
int N;
int fanwick[MAX];
int arr[MAX];
int order[MAX];

void update(int pos,int val){
	while(pos<=N){
		fanwick[pos]+=val;
		pos+=(pos & -pos);
	}
}

int sum(int pos){
	int ret=0;
	while(pos>0){
		ret+=fanwick[pos];
		pos-=(pos& -pos);
	}
	return ret;
}

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		int x;
		scanf("%d",&x);
		order[x]=i;
		arr[i]=x;
	}
	for(int i=1;i<=N;i++){
		fanwick[i]=(i&-i);
	}
	for(int	i=1;i<=N;i++){
		int num;
		if(i%2==1){
			num=(i+1)/2;
			printf("%d\n",sum(order[num]-1));	
		}
		else{
			num=N+1-(i/2);
			printf("%d\n",sum(N)-sum(order[num]));
		}
		update(order[num],-1);
	}
	return 0;
}