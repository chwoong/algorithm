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
#include <cstdio>
#include <fstream>
using namespace std;

int a,b;

int g(int i,int j){
	if(i>j) swap(i,j);
	if(i==0) return j;
	return g(i,j%i);
}

int main(){
	scanf("%d %d",&a,&b);
	int c=b/a;
	int sum=100000000;
	int x,y;
	for(int i=1;i<=10000;i++){
		if(i*i>c) break;
		if(c%i==0 && i<=c/i){
			if(sum>i+c/i && g(i,c/i)==1){
				sum=i+c/i;
				x=a*i;
				y=a*(c/i);
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}