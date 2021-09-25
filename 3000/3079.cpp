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

#define MAX 1000000000000000000

long long n,m;
long long t[100001];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",t+i);
	}
	long long l=0;
	long long h=MAX;
	while(l+1<h){
		long long mid=(l+h)/2;
		long long num=0;
		for(int i=0;i<n;i++){
			num+=mid/t[i];
			if(num>=m) break;
		}
		if(num<m) l=mid;
		else h=mid;
	}
	cout<<h;
	return 0;
}