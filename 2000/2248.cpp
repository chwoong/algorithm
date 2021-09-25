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

long long combi[32][32]={0,};

void precalc(){
	for(int i=0;i<=31;i++)
		combi[i][0]=1;
	combi[1][1]=1;
	for(int i=2;i<=31;i++)
		for(int j=1;j<=i;j++)
			combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
}


string solve(long long n,long long l,long long i){
	if(i==1) return string(n,'0');
	if(n==0) return "";
	long long sum=0;
	for(int k=0;k<=l;k++)
		sum+=combi[n-1][k];
	if(sum>=i) return "0"+solve(n-1,l,i);
	else return "1"+solve(n-1,l-1,i-sum);
		
}

int main(){
	long long n,l,i;
	cin>>n>>l>>i;
	precalc();
	cout<<solve(n,l,i);
	return 0;
}