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

#define MAX 1000001
int n,q;
long long fanwick[MAX]={0};

void update(int pos,long long val){
	while(pos<=n){
		fanwick[pos]+=val;
		pos+=(pos&-pos);
	}
}
long long sum(int pos){
	long long s=0;
	while(pos>0){
		s+=fanwick[pos];
		pos-=(pos&-pos);
	}
	return s;
}

int main(){
	cin>>n>>q;
	for(int i=0;i<q;i++){
		long long x,a,b;
		scanf("%lld %lld %lld",&x,&a,&b);
		if(x==1){
			update(a,b);
		}else{
			printf("%lld\n",sum(b)-sum(a-1));
		}
	}
	return 0;
}