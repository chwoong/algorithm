#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

#define DIV	1000000000
long long x[1000],y[1000];
int n,m;
long long ans=1;
long long gcd(long long a,long long b){
	if(a<b) swap(a,b);
	while(b!=0){
		a=a%b;
		swap(a,b);
	}
	return a;
}
int main(){
	int tmp=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>x[i];
	cin>>m;
	for(int i=0;i<m;i++)
		cin>>y[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			long long g=gcd(x[i],y[j]);
			x[i]/=g;
			y[j]/=g;
			if(ans*g>=DIV) tmp=1;
			ans=(ans*g)%DIV;
		}
	}
	//ansÀÇ ÀÚ¸´¼ö
	int digit=1;
	int k=ans;
	while((k/=10)!=0)
		digit++;
	for(int i=0;tmp&&i<9-digit;i++)
		cout<<'0';
	cout<<ans;
	return 0;
}