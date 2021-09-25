#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int N,M;
long long fanwick[1000001]={0,};
long long arr[1000001]={0,}
;
void update(long long pos,long long val){
	while(pos<=N){
		fanwick[pos]+=val;
		pos+=(pos & -pos);
	}
}
long long sum(long long pos){
	long long s=0;
	while(pos>=1){
		s+=fanwick[pos];
		pos-=(pos & -pos);
	}
	return s;
}

int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a==0) c>=b?cout<<sum(c)-sum(b-1)<<'\n':cout<<sum(b)-sum(c-1)<<'\n';
		else {int x=c-arr[b]; arr[b]=c; update(b,x);}
	}
	return 0;
}