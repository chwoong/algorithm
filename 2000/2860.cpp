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
using namespace std;

string s;
long long arr[6];
long long gcd(long long a,long long b){
	if(a>b) swap(a,b);
	while(a!=0){
		long long t=a;
		a=b%a;
		b=t;
	}
	return b;
}

int main(){
	cin>>s;
	//소수점 자리 개수
	int len=s.size()-2;
	long long a=0;
	long long d=1;
	a+=(s[0]-'0');
	for(int i=0;i<len;i++){
		a=(a*10ll+(s[i+2]-'0'));
		d*=10ll;
	}
	long long g=gcd(a,d);
	a/=g;
	d/=g;
	long long x=a/d;
	long long y=a%d;
	if(x==5){
		arr[5]=1;
	}else{
		arr[x]=(x+1)*d-a;
		arr[x+1]=d-arr[x];
	}
	for(int i=1;i<=5;i++)
		printf("%lld ",arr[i]);
	return 0;
}