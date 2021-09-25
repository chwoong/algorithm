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
using namespace std;

int n,k;
vector<int> arr;

int gcd(int a,int b){
	if(a>b) swap(a,b);
	if(a==0) return b;
	return gcd(a,b%a);
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		arr.push_back(x);
	}
	arr.push_back(360);
	//a들의 최대공약수를 구하자
	int g=arr[0];
	for(int i=1;i<=n;i++){
		g=gcd(g,arr[i]);
	}
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		if(x%g==0) puts("YES");
		else puts("NO");
	}
	return 0;
}