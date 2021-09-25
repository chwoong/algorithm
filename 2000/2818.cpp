#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
using namespace std;

long long one[4]={14,1,6,12};
long long two[6]={42,5,11,19,28,36};
int main(){
	long long ans=0;
	long long r,c;
	cin>>r>>c;
	ans=r*(long long)14*(c/4);
	switch(c%4){
		case 1: ans+=(long long)14*(r/4)+one[r%4]; break;
		case 2: ans+=(long long)42*(r/6)+two[r%6]; break;
		case 3: ans+=(long long)11*r;
		default: break;
	}
	cout<<ans;
	return 0;
}