#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n,m;

int gcd(int i,int j){
	if(i>j) swap(i,j);
	while(j%i!=0){
		int t=i;
		i=j%i;
		j=t;
	}
	return i;
}
int main(){
	cin>>n>>m;
	int x=n%m;
	if(x==0){
		cout<<0;
	}else{
		int q=gcd(x,m);
		cout<<q*(m/q-1);
	}
	return 0;
}