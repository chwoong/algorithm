#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int n,k;
long long arr[300000];

bool f(double x){
	double tmp[300000]={0,};
	for(int i=0;i<n;i++){
		tmp[i]=arr[i]-x;
	}
	double psum[300010]={0,};
	for(int i=1;i<=n;i++){
		psum[i]=psum[i-1]+tmp[i-1];
	}
	double m=0;
	for(int i=k;i<=n;i++){
		m=min(m,psum[i-k]);
		if(psum[i]>=m) return true;
	}
	return false;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%lld",arr+i);
	}
	double l0=1;
	double hi=1000000;
	for(int i=0;i<60;i++){
		double mid=(l0+hi)/2;
		//double 이상의 평균이 존재하는지 확인
		if(f(mid)) l0=mid;
		else hi=mid;
	}
	printf("%.6f",l0);
	return 0;
}