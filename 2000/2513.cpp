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

int n,k,s;
long long dist1[100001];
long long dist2[100001];
long long ret[100001];
int num[100001];

int main(){
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		num[a]=b;
	}
	long long x=0;
	int b=0;
	for(int i=0;i<=100000;i++){
		if(i!=0) dist1[i]=dist1[i-1]+b;
		else dist1[i]=0;
		x+=num[i];
		b=(x+k-1)/k;
	}
	x=0;
	b=0;
	for(int i=100000;i>=0;i--){
		if(i!=100000) dist2[i]=dist2[i+1]+b;
		else dist2[i]=0;
		x+=num[i];
		b=(x+k-1)/k;
	}
	for(int i=0;i<=100000;i++){
		ret[i]=dist1[i]+dist2[i];
	}
	cout<<2*ret[s];
	return 0;
}