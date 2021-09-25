#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
#include<stdlib.h>
using namespace std;

long long N;
long long psum=0;

int main(){
	cin>>N;
	for(long long i=1;i<=N;i++){
		long long x;
		scanf("%lld",&x);
		printf("%lld ",x*i-psum);
		psum=x*i;
	}
	return 0;
}